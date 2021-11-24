## webSocket

> google地圖就是用ajax(比較老)、websocket(新技術，比較快)去抓，不會一次抓下來，是根據使用者需求去抓

```JS
while (true) {

 // deno 只要有輸出入就要有輸出入，這邊會報錯是因為這邊是deno語法，用的是JS，JS await只能寫在module裡面
 // prompt是取得終端輸入
 var line = await prompt("> ")

 console.log('you type: ', line)

}
```



> 可以使用這個讓每個不同使用者(client)透過server互動
>
> 基礎寫法如下

```JS
import { WebSocket, WebSocketServer } from "https://deno.land/x/websocket@v0.0.5/mod.ts";

// 建立伺服端，WebSocket是專門針對伺服端跟客戶端的連接
const wss = new WebSocketServer();
// 有人連進來，就會觸發(connecting)
wss.on("connection", function (ws: WebSocket) {
  console.log("socket connected!");
  ws.on("message", function (message: string) { // 有人傳訊息就會顯示他打的訊息
    console.log(message);
    ws.send(message)
  });
});
```



> webSocket是用另外一個port進行網路通訊的，所以client要通訊，要連到webSocket開的port

```JS
import { Application, send } from "https://deno.land/x/oak/mod.ts";
import { WebSocketClient, WebSocketServer } from "https://deno.land/x/websocket/mod.ts";

const app = new Application();
// html serve
app.use(async(ctx) => {
	console.log('path=', ctx.request.url.pathname)
	try{
		await send(ctx, ctx.request.url.pathname, {
			root: `${Deno.cwd()}`,
			index: "index.html",
		  });
	}
	catch (e) {console.log("Error:" + e)}
});


// websocket serve  //不能用一樣的port  // client要和這個連到同一個才能互相傳資料
const wss = new WebSocketServer(8080);

wss.on("connection", function (ws: WebSocketClient) {
	ws.on("message", function (message: string) {
		console.log(message);
		//ws.send(message);
		// broadcast message
		// forEach是回乎函數，只要client沒關，這個就還會在，這邊做的效果是任何人傳訊息都會廣播給所有人
		wss.clients.forEach(function each(client) {
			if (!client.isClosed) {
				client.send(message);
			}
		});
	});
});

console.log('start at : http://127.0.0.1:8881')
await app.listen({ port: 8881 });

```