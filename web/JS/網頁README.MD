前端使用fetch做網站前後端的資料傳輸，利用onclick 觸發函數，使用querySelector取得資料內容，再用fetch把內容回傳到後端(server.js)，進行資料庫的添加，前端部分比重偏重



網頁有些內容使用iframe，把內容放如github裡面，在使用iframe把他們叫入主網頁中



網頁login是使用fetch判斷，利用data判斷後端的ctx.response.body傳回的內容，再決定要跳到哪個頁面(如果登入成功會拿到flag(在後端)，再用flag去開登入功能)

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







