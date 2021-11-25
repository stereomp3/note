> **root: Deno.cwd(), `把資料夾根目錄丟到網路上` **

> **index: "index.html", `在/時顯示的文件，一般都是html`**

* deno debugger 可以進行調適(要額外下載)
	不過開發網站的人比較常用denon，程式碼一改就重啟伺服器

## 在伺服器上，如果要引入其他檔案(JS, CSS)，就要使用靜態網站放檔案(像是github)

> 使用router
>
> ```
> import { Application, Router, send } from "https://deno.land/x/oak/mod.ts";
> ```

* 鍊式語法: router.get().get().get() = router.get()， 現在很多語言都支援
				      
	```js
	*  router.get()
	  			       router.get()
	
	context.params  	(context是自定義變數)
	context.params.id
	```
	
	

```
Q: 為甚麼要加上 router.allowedMethod() ?

A:

1. router.allowedMethods()中間件，主要用於 405 Method Not Allowed 這個狀態碼相關
2. 如果不加這個中間件，如果接口是get請求，而前端使用post請求，會返回 404 狀態碼，接口未定義。
   如果加了這個中間件，這種情況時，會返回405 Method Not Allowed ，提示 request method 不匹配，並在響應頭返回接口支持的請求方法，更有利於調試
```

