## Session

> session主要是對不同的用戶進行操作，可以用這個進行帳號的管理

> 引入session `import { Session } from "https://deno.land/x/oak_sessions/mod.ts";`

> 使用session `const session = new Session();`

> 使用router時，注意，如果觸發的函式有用到session，就要加 `session.initMiddleware()`

```js
import { Router } from "https://deno.land/x/oak/mod.ts";
import { Session } from "https://deno.land/x/oak_sessions/mod.ts";

const session = new Session();
const router = new Router();

router.get('/', session.initMiddleware(),list) // list函式裡有用到session，所以要加
  .get('/post/:id', show)
  .post('/post', session.initMiddleware(), create)
```



> 使用session常用功能，get和set，可以讓不同電腦存取不同的使用者

```js
async function login(ctx){
    // 設置數據(登入綁定使用著)
    ctx.state.session.set('user', user)
    // 取得數據(可以用在需要使用者名字的地方)，需要加上await
    var user = await ctx.state.session.get('user')
    
    console.log(user.username)
    
    //....
}
// 在logout時，把使用者清空
async function logout(ctx) {
   ctx.state.session.set('user', null)
}

```

