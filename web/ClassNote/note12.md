WebSocket 就是使用TCP 去傳輸，連線導向，連一次就OK

做網站的重點是在HTTP(在應用層)，HTTP在傳輸是透過layer 3 去傳輸(TCP/UTP)，





await async 都是建立在 promise物件上，如果promise物件加上.then，就是Non block，直接不等

```js
const promise1 = new Promise((resolve, reject) => {
  setTimeout(() => {
    resolve('foo');
  }, 300);
});

promise1.then((value) => {    // 成功執行resolve
          console.log(value);
          // expected output: "foo"
        })
		.catch((value) => {   // 失敗執行reject
          console.log(value);
        })

console.log(promise1);
// expected output: [object Promise]
```





> 建立HTTPS連線(要取得網頁左邊的鎖頭，超麻煩)

* 取得證書 --> 免費的使用 [let's encrypt](https://letsencrypt.org/zh-tw/)
* 證書只能綁定domain name，linode有一個免費的，不過很長，要買domain name可以上gandi.net買
* linux crontab可以自動抓證書，因為let's encrypt 3 個月會過期

```js
// 使用oak
// await app.listen({ port: 8881 });
await app.listen({ 
    port: 8881,
    secure: true,
    certFile: <file>,  // let's encrypt證書位置
  	keyFile: <file>,
});

// 使用deno
const server = Deno.listenTls({
  port: 8443,
  certFile: "localhost.crt",  // let's encrypt證書位置
  keyFile: "localhost.key",
  alpnProtocols: ["h2", "http/1.1"],
});
```







> JS 指定 onload 事件觸發，使用addEventListener比較好，因為可以加不只一個

```js
const handler = (e: Event): void => {
  console.log(`got ${e.type} event in event handler (imported)`);
};

window.addEventListener("load", handler); // 可以加好幾個函式
window.addEventListener("unload", handler);

window.onload = (e: Event): void => {  // 只能用一個
  console.log(`got ${e.type} event in onload function (imported)`);
};

window.onunload = (e: Event): void => {
  console.log(`got ${e.type} event in onunload function (imported)`);
};

console.log("log from imported script");
```







> **deno**上server之後，不要都用-A，這樣安全性會變低，使用詳細的指令控制比較好

```
deno run --allow-read=/etc https://deno.land/std@0.116.0/examples/cat.ts /etc/passwd

// fetch.js
const result = await fetch("https://deno.land/");

deno run --allow-net fetch.js

// run.js
const proc = Deno.run({ cmd: ["whoami"] }); // 可以直接執行CMD

deno run --allow-run=whoami run.js
deno run --allow-run run.js

// env.js
Deno.env.get("HOME");

deno run --allow-env=HOME env.js
deno run --allow-env env.js



```



> [deno 指令查詢](https://deno.land/manual@v1.16.3/getting_started/command_line_interface)

```
# Using the short flag -- outputs the same as above.
deno -h

# 使用不同版本的函式庫，可以加入map.json檔，對函式做統一管理，用在大型專案
--import-map <FILE>           Load import map file

# 會幫你把檔案縮排好
deno fmt <檔名>

# 可以把檔案變執行檔，然後再用其他軟體把它包一下，就可以讓人下載了
deno compile
```



> [deno worker](https://deno.land/manual@v1.16.3/runtime/workers)

* 可以把動作放在背景執行，要檔案再和worker要，大型專案會用到





>Proxies

* 很多大公司會有，學校之類的也可能會有，用在網路上，在上網時，要先打入指定IP和port，電信公司會對使用者進行統一管理，可以限制上網也可以快取網路資料





> 可以自己做一個deno 套件，發佈到github上，然後再放入deno third party上面

> WebAssembly 可以讓各種語言在網路上跑

> lint 工具可以檢查語法





> https://deno.land/manual@v1.16.3/tools

# Built-in tooling

Deno provides some built-in tooling that is useful when working with JavaScript and TypeScript:

- [bundler (`deno bundle`)](https://deno.land/manual@v1.16.3/tools/bundler)   **可以把很多檔案變成一個，網站讀取好用**

- [compiling executables (`deno compile`)](https://deno.land/manual@v1.16.3/tools/compiler)  **把檔案變成執行檔** 

  ` deno compile --allow-read --allow-net https://deno.land/std/http/file_server.ts`

- [installer (`deno install`)](https://deno.land/manual@v1.16.3/tools/script_installer)

- [dependency inspector (`deno info`)](https://deno.land/manual@v1.16.3/tools/dependency_inspector)

- [documentation generator (`deno doc`)](https://deno.land/manual@v1.16.3/tools/documentation_generator)

- [formatter (`deno fmt`)](https://deno.land/manual@v1.16.3/tools/formatter)

- [repl (`deno repl`)](https://deno.land/manual@v1.16.3/tools/repl)

- [test runner (`deno test`)](https://deno.land/manual@v1.16.3/testing)

- [linter (`deno lint`)](https://deno.land/manual@v1.16.3/tools/linter)