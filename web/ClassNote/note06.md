* 前端是送給瀏覽器的資料，後端的資料無法從開發人員選向看到



## template

* 這個跟樣板字符串(程式包樣板)很像，不過他是樣板包程式，可以在樣板裡面加程式
* ejs是JS檔案的模板引擎，djs是deno檔案的模板引擎

* **`renderToString`** 是把字串轉字串，好用，但是負擔很大，很耗網路流量

* 從08-fetch開始就是web2.0，不是一直換頁，而是用書籤



## Session

> 不同瀏覽器有不同的session，可以讓不同用戶使用

```
ctx.state.session.set('user', user)  // 設定資料傳給session
await ctx.state.session.get('user')  // 從伺服器上取資料需要 await
```







```
表單回傳用post，一般進去網址用get
```



> 可以做web版本的SQLite修改器，當作期末作業

>網頁設計上傳 加上 -A 是 allow read 和 allow write ，打後面兩個比較安全，可以控制要如何作業