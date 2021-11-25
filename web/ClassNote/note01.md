* deno 開伺服器，在終端機站著，ctrl+c停掉伺服器
* deno run -A helloServer.js   // A是--allow-read

* 把終端機改成bash --> select default shell --> 選擇 git bash
* bash 使用linux指令
  
### windows shell 是 windows指令，使用bash比較好，未來會比較常用

```
11-crawler(爬蟲)
curl 使用方法 : http://www.ruanyifeng.com/blog/2019/09/curl-reference.html
```

* 打完程式碼可以加上js讓文字有顏色
  
```js
"""js
	JS程式
"""
```

### 02-fileserver

```js
const app = new Application();
app是一個物件
app.use(回應函數)

reqServer.js
JSON.stringify(Object.fromEntries(ctx.request.headers)) 
//把物件便字串//把東西變物件
```

### 03-oak

```js
await app.listen({ port: 8000 }); // await 是 等待伺服器輸出輸入，有一組都是表達這種，後面會說
				  // app.listen 是真正連到伺服器的地方


app.use((ctx) => {
  ctx.response.redirect('https://tw.youtube.com') // 直接連到youtube，但會經過我們的網站(fast)
});09537318


app.use(async (ctx) => { // async 是非同步，因為有send函數讀資料造成不同步，所以要加，，也要加await
  console.log('path=', ctx.request.url.pathname)
  //send函數可以傳任何物體(影像，音訊...)
  await send(ctx, ctx.request.url.pathname, {
    // root: `${Deno.cwd()}/public/`,
    root: Deno.cwd()+'/public/',  // Deno.cwd()取得目前資料夾
    index: "index.html", // 如果沒有根目錄，index就是default開啟檔案
  });
});
```

```
Q:
myoak.js --- 為甚麼要設置request和header? 
         --- 為甚麼只能塞一個function到列表就要break，塞兩個會如何??
```

