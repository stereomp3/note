## 參考資料

> 程式碼來源: [expr.c](https://github.com/embedded2015/rubi/blob/master/expr.c)、[expr.h](https://github.com/embedded2015/rubi/blob/master/expr.h)



## expr.h

```c
#ifndef RUBI_EXPR_INCLUDED
#define RUBI_EXPR_INCLUDED

#include <stdint.h>

void relExpr();

int32_t skip(char *s);  // 這個在parser.c裡面定義

#endif
```





## expr.c

> 專門處理語句(and、or、[、|、+、-、<.....)，使用到rubi.h裡面的tok結構，利用tok位置移動判斷字符類型

最開始由 `relExpr()` 進入觸發然後就開始一系列順序呼叫: 

`relExpr() -> condExpr() -> addSubExpr() -> mulDivExpr() ->  primExpr() -> relExpr()  `

因為上面的function都是一開始就會呼叫下一個函數，所以執行因該是先由 `primExpr()` 開始



* `void primExpr()`:  根據符號判斷是什麼類型(number、char、string、variable or inc or dec、function)，如果是function，就會觸發`stdlib.c`裡面的`make_stdfunc()`，做函式的呼叫

* `void mulDivExpr()`: 判斷算數運算符號(`*` `/` `%`)，如果沒有(使用skip判斷)，就跳出迴圈，不執行算數操作

* `void addSubExpr()`: 判斷算數運算符號(`+` `-`)，如果沒有(使用skip判斷)，就跳出迴圈，不執行算數操作

* `void condExpr()`: 判斷關係運算符號(`<` `>` `!=` `==` `<=` `>=`)，如果沒有(使用skip判斷)，就不執行比大小的動作

* `void relExpr()`: 判斷邏輯運算符號(`and` `&` `or` `|` `||` `^`)，如果沒有(使用skip判斷)，就不執行比邏輯判斷的動作

  

```c
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "expr.h"
#include "rubi.h"
#include "asm.h"
#include "parser.h"

extern int make_stdfunc(char *);

// strcmp(str1, str2)會比較str1和str2的大小
// 這裡是判斷 tok.tok[tok.pos] 裡面的 val 是不是等於 [
static inline int32_t isIndex() { return !strcmp(tok.tok[tok.pos].val, "["); }

static void primExpr()
{
    if (isdigit(tok.tok[tok.pos].val[0])) { // number?
        emit(0xb8 + EAX); emitI32(atoi(tok.tok[tok.pos++].val)); // mov eax %d
    } else if (skip("'")) { // char?
        emit(0xb8 + EAX);
        emitI32(tok.tok[tok.pos++].val[0]); // mov eax %d
        skip("'");
    } else if (skip("\"")) { // string?
        emit(0xb8); getString(); emitI32(0x00); // mov eax string_address
    } else if (isalpha(tok.tok[tok.pos].val[0])) { // variable or inc or dec
        char *name = tok.tok[tok.pos].val;
        Variable *v;

        if (isassign()) assignment();
        else {
            tok.pos++;
            if (skip("[")) { // Array?
                if ((v = getVar(name)) == NULL)
                    error("%d: '%s' was not declared",
                          tok.tok[tok.pos].nline, name);
                relExpr();
                emit(0x89); emit(0xc0 + EAX * 8 + ECX); // mov ecx eax

                if (v->loctype == V_LOCAL) {
                    emit(0x8b); emit(0x55);
                    emit(256 - sizeof(int32_t) * v->id); // mov edx, [ebp - v*4]
                } else if (v->loctype == V_GLOBAL) {
                    emit(0x8b); emit(0x15); emitI32(v->id);
                        // mov edx, GLOBAL_ADDR
                }

                if (v->type == T_INT) {
                    emit(0x8b); emit(0x04); emit(0x8a);
                        // mov eax, [edx + ecx * 4]
                } else {
                    emit(0x0f); emit(0xb6); emit(0x04); emit(0x0a);
                        // movzx eax, [edx + ecx]
                }

                if (!skip("]"))
                    error("%d: expected expression ']'",
                          tok.tok[tok.pos].nline);
            } else if (skip("(")) { // Function?
                if (!make_stdfunc(name)) {	// standard function
                    func_t *function = getFunc(name);
                    char *val = tok.tok[tok.pos].val;
                    if (isalpha(val[0]) || isdigit(val[0]) ||
                        !strcmp(val, "\"") || !strcmp(val, "(")) { // has arg?
                        for (int i = 0; i < function->args; i++) {
                            relExpr();
                            emit(0x50 + EAX); // push eax
                            skip(",");
                        }
                    }
                    emit(0xe8); emitI32(0xFFFFFFFF -
                                        (ntvCount - function->address) - 3);
                        // call func
                    emit(0x81); emit(0xc0 + ESP);
                    emitI32(function->args * sizeof(int32_t)); // add esp %d
                }
                if (!skip(")"))
                    error("func: %d: expected expression ')'",
                          tok.tok[tok.pos].nline);
            } else {
                if ((v = getVar(name)) == NULL)
                    error("var: %d: '%s' was not declared",
                          tok.tok[tok.pos].nline, name);
                if (v->loctype == V_LOCAL) {
                    emit(0x8b); emit(0x45); emit(256 - sizeof(int32_t) * v->id);
                        // mov eax variable
                } else if (v->loctype == V_GLOBAL) {
                    emit(0xa1); emitI32(v->id); // mov eax GLOBAL_ADDR
                }
            }
        }
    } else if (skip("(")) {
        if (isassign()) assignment(); else relExpr();
        if (!skip(")")) error("%d: expected expression ')'",
                              tok.tok[tok.pos].nline);
    }

    while (isIndex()) {
        emit(0x89); emit(0xc0 + EAX * 8 + ECX); // mov ecx eax
        skip("[");
        relExpr();
        skip("]");
        emit(0x8b); emit(0x04); emit(0x81); // mov eax [eax * 4 + ecx]
    }
}

static void mulDivExpr()
{
    int32_t mul = 0, div = 0;
    primExpr();
    while ((mul = skip("*")) || (div = skip("/")) || skip("%")) {
        emit(0x50 + EAX); // push eax
        primExpr();
        emit(0x89); emit(0xc0 + EAX * 8 + EBX); // mov ebx eax
        emit(0x58 + EAX); // pop eax
        if (mul) {
            emit(0xf7); emit(0xe8 + EBX); // mul ebx
        } else if (div) {
            emit(0xb8 + EDX); emitI32(0); // mov edx 0
            emit(0xf7); emit(0xf8 + EBX); // div ebx
        } else { /* mod */
            emit(0xb8 + EDX); emitI32(0); // mov edx 0
            emit(0xf7); emit(0xf8 + EBX); // div ebx
            emit(0x89); emit(0xc0 + EDX * 8 + EAX); // mov eax edx
        }
    }
}

static void addSubExpr()
{
    int32_t add;
    mulDivExpr();
    while ((add = skip("+")) || skip("-")) {
        emit(0x50 + EAX); // push eax
        mulDivExpr();
        emit(0x89); emit(0xc0 + EAX * 8 + EBX); // mov ebx eax
        emit(0x58 + EAX); // pop eax
        if (add) {
            emit(0x03); emit(EAX * 8 + 0xc0 + EBX); // add eax ebx
        } else {
            emit(0x2b); emit(EAX * 8 + 0xc0 + EBX); // sub eax ebx
        }
    }
}

static void condExpr()
{
    int32_t lt = 0, gt = 0, ne = 0, eql = 0, fle = 0;
    addSubExpr();
    if ((lt = skip("<")) || (gt = skip(">")) || (ne = skip("!=")) ||
        (eql = skip("==")) || (fle = skip("<=")) || skip(">=")) {
        emit(0x50 + EAX); // push eax
        addSubExpr();
        emit(0x89); emit(0xc0 + EAX * 8 + EBX); // mov ebx eax
        emit(0x58 + EAX); // pop eax
        emit(0x39); emit(0xd8); // cmp %eax, %ebx
        emit(0x0f);
        emit(lt ? 0x9c /* < */ :
                   gt ? 0x9f /* > */ :
                        ne ? 0x95 /* != */ :
                             eql ? 0x94 /* == */ :
                                   fle ? 0x9e /* <= */ :
                                         0x9d /* >= */);
        emit(0xc0); // setX al
        emit(0x0f); emit(0xb6); emit(0xc0); // movzx eax al
    }
}

void relExpr()
{
    int and = 0, or = 0;
    condExpr();
    while ((and = skip("and") || skip("&")) ||
           (or = skip("or") || skip("|")) || (skip("xor") || skip("^"))) {
        emit(0x50 + EAX); // push eax
        condExpr();
        emit(0x89); emit(0xc0 + EAX * 8 + EBX); // mov ebx eax
        emit(0x58 + EAX); // pop eax
        emit(and ? 0x21 : or ? 0x09 : 0x31); emit(0xd8); // and eax ebx
    }
}
```

