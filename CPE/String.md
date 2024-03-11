# string

![](https://github.com/stereomp3/note/blob/main/picture/c%2B%2B/string.jpg)

## string用法(跟[vector](Vector.md)差不多)

1. 創建
   * string str1;                 // 內容為空字串
   * string str2("caterpillar");  // 內容為指定的字串常量
   * string str3 = "Justin";      // 內容為指定的字串常量
   * string str4(str3);           // 以 str3 實例建立字串

2. 添加
   * str.push_back() - 新增元素至 string 的尾端，必要時會進行記憶體配置。
   * insert(str.begin(), 'a') - 新增元素至第一個

3. 刪除
   * str.pop_back() - 刪除 string 最尾端的元素。
   * erase(str.begin()+str.size()-1) - 刪除倒數第一個元素
   * str.clear() - 清空所有元素。

4. 獲取
   * 從index裡面去獲取，如上圖
   * str.at(i) - 存取索引值為 i 的元素的值，
   * str.front() - 回傳 string 第一個元素的值。
   * str.back() - 回傳 string 最尾元素的值。
   * **需要 printf 出來的時候需要使用 str.c_str()**
   
5. 取得長度
   * str.empty() - 如果 vector 內部為空，則傳回 true 值。
   * str.size() - 取得 vector 目前持有的元素個數。(也可以用str.length())

6. 迭代
   * str.begin() - 回傳一個 iterator，它指向 vector 第一個元素。
   * str.end() - 回傳一個 iterator，它指向 vector 最尾端元素的下一個位置（請注意：它不是最末元素）。
   * str.rbegin() - 回傳一個反向 iterator，它指向 vector 最尾端元素的。
   * str.rend() - 回傳一個 iterator，它指向 vector 的第一個元素。 // r是使用在逆向迭代器

## string邏輯判斷

   * 賦值 = : 將字串指定給另一個字串。
   * 相等比較 == : 比較兩個字串的字元內容是否相同。
   * 串接字串 + : 直接使用 + 運算子來串接字串。


## demo01: 測試字串長度

input:

```c++
#include <iostream> 
#include <string> 
using namespace std; 

int main() { 
    string str1; 
    string str2 = "caterpillar"; 
    string str3(str2); 

    cout << "str1 是否為空：" << str1.empty() << endl;
    cout << "str1 長度: " << str1.size() << endl;
    cout << "str2 長度: " << str2.size() << endl;
    cout << "str3 長度: " << str3.size() << endl;

    cout << "str1 與 str2 內容是否相同：" << (str1 == str2) << endl;
    cout << "str2 與 str3 內容是否相同：" << (str3 == str3) << endl;

    return 0; 
}
```

output:

```c++
str1 是否為空：1
str1 長度: 0
str2 長度: 11
str3 長度: 11
str1 與 str2 內容是否相同：0
str2 與 str3 內容是否相同：1
```

## demo02: 取得字串

input01:

```c++
#include <iostream> 
#include <string> 
using namespace std; 

int main() { 
    string name = "caterpillar";

    for(int i = 0; i < name.length(); i++) {
        cout << name[i] << endl;
    }

    return 0; 
}
```

input02:

```c++
#include <iostream> 
#include <string> 
using namespace std; 

int main() { 
    string name = "caterpillar";

    for(int i = 0; i < name.length(); i++) {
        cout << name[i] << endl;
    }

    return 0; 
}
```

output:

```c++
c
a
t
e
r
p
i
l
l
a
r
```

#### string.find()
> 會回傳找到的位置

```c++
#include<iostream>
#include<string>

int main(){
    string a = "asdfghjkl;'";
    int num = a.find('a');  // num == 0
    int num02 = a.find('z')  // 沒找到 num02 == -1
}
```

> 如果 `string name = "中文";` 要在前面加上u8，才可以讀入 --> `string name = u8"中文"`

> 如果`string str`想要print出來，需要告知第一個位置`str.c_str()` // 或是用`&str[0]`

> int 轉字串: `to_string(int)`