## 網頁遊戲筆記

>[**Phaser Game**](https://github.com/stereomp3/note/tree/main/web/Phaser)



>[Unity Game](https://github.com/stereomp3/note/tree/main/unity)



## 網站概述

> 本網站使用Web2.0架構

* 前端使用fetch做網站前後端的資料傳輸，利用onclick 觸發函數，使用querySelector取得資料內容，再用fetch把內容回傳到後端(server.js)，進行資料庫的添加，前端部分比重偏重



> 主網站內嵌次網站(放在github)

* 網頁有些內容使用iframe，把內容放如github裡面，在使用iframe把他們叫入主網頁中



> 網站登入判定

* 網頁login是使用fetch判斷，利用data判斷後端的ctx.response.body傳回的內容(會在/user顯示用戶名)，再決定要跳到哪個頁面(如果登入成功會拿到flag，再用flag去開登入功能)

```JS
let r = window.fetch('/login', {
    // 把json物件轉成字串
        body: JSON.stringify({username: username, password: password}),
        method: 'POST',
        headers: {
        'Content-Type': 'application/json'
        }
    })

  r.test().then(function(data) {
    console.log(data); // this will be a string --> 對應到後端的ctx.response.body 
  });
```



> 登入可以做的事情(會慢慢加):

   1.  發文 (Web1.0)
   2.  ......





> 檢查格式參考網頁: https://jadoggy.pixnet.net/blog/post/10638134

```js
// 檢查是否為MAIL格式
	// ^ -> 搜尋規則前的「起頭」。意思代表「非」
    // $ -> 搜尋規則後的「結尾」
	// . -> 任意一個字元 
	// \.前面加上\代表原始含意，就是. ， \@也一樣
	// [-] -> 範圍；如[A-Z]即A，B，C一直到Z都符合要求
    // 這裡是從 一開始比對到結束([a-zA-Z0-9_\.\-])代表所有可比對自符，中間一定要有@
    // exec() 是字符和正規表達式有沒有符合，如果沒有符合，return null;
	// (([a-zA-Z0-9\-])+\.)+([a-zA-Z0-9]) 代表偵測到.之後還要再有符號才給過
re1 = /^([a-zA-Z0-9_\.\-])+\@(([a-zA-Z0-9\-])+\.)+([a-zA-Z0-9])+$/;
if (re1.exec(user.email) == null) alert("你的電子郵件格式不合！");           

```



預設使用者:

```
user: abc password: 123456 email: abc@gmail.com
```







