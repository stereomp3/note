## 正規表達式:	/開頭/結尾
	(.*) 可以表達任何字串(.是指所有字元 *是指多個) 
	
	\d 比對數字([0-9]) /w 比對字母
	\s 比對空格字元 \s* 比對多個空格
	. --> 所有字元 
	+ --> 比對一次以上
	* --> 比對零次以上
	? --> 比對零次和一次
	{x, y} --> 比對x~y次
	
	字符串比對可以用"/(.*)" 表示根目錄位置


	\符號 --> 如果符號有特殊涵意，可以用\取消他的特殊涵義，讓他變成可以比對的符號(\.)
	
	正規表達式.exec(html) : 抓出裡面的的東西，傳回矩陣 [0] --> 全部， 
				[1] --> 第一個誇號裡的東西

# 爬蟲:
     不要發太多請求，不然會被ban IP

* routerStatic2 很重要 !

* 寫middleware 必須用 async await 很像 yeild next (generater)，

```js
a(function(){
    b(function(){
	c(function(){
	    // 回呼地獄
	})
    })
})
```

可以改成 :

```js
let r = await a
r = await b
r = await c
```

取得資料用await

# request, respond?
```js
request: 傳回使用者
ctx.request.url.pathname --> 取路徑
ctx.request.body().value --> 取出裡面有name的東東和內容組成類似字典的東東
				通常要再用一個字典取出
    --->
	const post = {}
      	for (const [key, value] of pairs) {
    	    post[key] = value
  		}	
```


```js
respond: 傳到伺服器
ctx.body = `` --> 把`html`放到網站裡
ctx.respond.body = ` `  -->
ctx.respond.redirect("/") --> 把目錄切到("/") 
```

* **app(router.router())讓 router裡面的.get會根據網址作動作**

* JS的 for of 比較像 python 的 for in
  JS的 for in 要加上可迭代對象的index


* 用nginx 把http轉https --> 使用 reverse coure(反向代理) 

  

**<input> 裡面的name=""在上面請求(ctx.request.body().value)時候會用到，用來當鍵，內容當值**

**send(ctx, 路徑,{root:Deno.cwd() index:文件})**

> 路徑可以有很多表示法:
>     ctx.params[0]
>     ctx.request.url.pathname

```
Q:
ctx.respond.body? 
ctx.body?
為甚麼標準字幅串沒辦法讀取到onclick裡面的函數?
router一個網址對應一個方法?
/:D?
CSS如何對應到所有(在標準字幅串李)
標準字幅串做小切換，CSS
如何把CSS修改成沒有show()
```

