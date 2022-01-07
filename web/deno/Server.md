## 建立deno server(使用oak套件)

> 指導老師: [[**陳鍾誠**](https://www.facebook.com/ccckmit?__cft__[0]=AZVethTz5Hu1AEYrrvQU5sZznAuGm23KAa9UsX-All2jFE_drFygSWwPVyz0N_wm0--tN5ue2-EaLQ5PoQ5Y8aKZ8Z5cVtZI4xPu-WBwXOPICbEqcPzVoBTec5aiX6I0WTE&__tn__=-UC%2CP-R)]
>
> [網站]((https://gitlab.com/ccc110/ws))

1. 先import deno 的oak套件

   `import { Application, Router, send } from "https://deno.land/x/oak/mod.ts";`

2. 使用他的Application建立伺服器

   `const app = new Application();` 

   `await app.listen({ port: 6020 }); `

3. 使用他的router接收訊息或是把資料放到目錄裡面

   > 以下是server範例

```js
import { Application, Router, send } from "https://deno.land/x/oak/mod.ts";

const router = new Router(); 

// 使用router讓不同的路徑顯示不同資料
router
     // 根目錄/，(.*)代表所有的符號都可以
  .get("/(.*)", async (ctx) => {
    await send(ctx, ctx.params[0],{
      // 把資料夾(根目錄)的檔案傳到網站上
      root: Deno.cwd(),
      // 預設檔案(一進網站就會執行)
      index: "index.html"
    })
  })
	// 放到路徑/assets裡面
  .get("/assets/(.*)", async (ctx) => { //get("/", func())根目錄顯示
   await send(ctx, ctx.params[0],{
        // 把資料夾(/assets)的檔案傳到網站上
        root: Deno.cwd() + "/assets", 
    })
  })

const app = new Application();

// router的所有方法都可以使用
app.use(router.allowedMethods()); 
// 讓router啟動
app.use(router.routes()); 


console.log('start at : http://127.0.0.1:6020')
// 把伺服器開在port 6020
await app.listen({ port: 6020 }); 
```



> **!!改了後端的東西就要重啟伺服器才可以運行!!**
