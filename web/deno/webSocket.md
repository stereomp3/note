## webSocket

> client.js --> 前端

```js
var socket = new WebSocket("ws://"+window.location.hostname+":8080")  // 連到server port

// 開啟網站時觸發(連接到websocket)
socket.onopen = async function (event) { 
    console.log(event.data)
    console.log('socket:onopen()...') 
    let user = await window.fetch('http://127.0.0.1:8666/user')
    user.text().then(function(data){
        console.log(data)
        //document.getElementsByClassName("topNavText")[0].appendChild(document.createTextNode("*"+data)) // 這邊加上這句只會在自己電腦看到
        // client 傳給 server
        socket.send(JSON.stringify(data)) // 加上這句配合伺服器才能讓所有人看到
    })
}
socket.onerror = function (event) { console.log('socket:onerror()...') }
// 關閉時觸發
socket.onclose = function (event) { console.log('socket:onclose()...') }

// 有字串時觸發 // server傳給client時觸發
socket.onmessage = function(event){
    console.log(event.data);
    var line = JSON.parse(event.data);  // JSON.parse把JSON檔案轉物件
    document.getElementsByClassName("topNavText")[0].appendChild(document.createTextNode(line))
}
```



> server.ts --> 後端

```tsx
import { WebSocketClient, WebSocketServer } from "https://deno.land/x/websocket/mod.ts";

// websocket serve  //不能用一樣的port  // client要和這個連到同一個才能互相傳資料
const wss = new WebSocketServer(8080);

wss.on("connection", function (ws: WebSocketClient) {
	ws.on("message", function (message: string) { 
		console.log(message);
		//ws.send(message);  // 單向傳送
        
		// forEach是回乎函數，只要client沒關，這個就還會在，這邊做的效果是任何人傳訊息都會廣播給所有人
		wss.clients.forEach(function each(client) {
			if (!client.isClosed) {
				client.send(message); // server 傳給 client // broadcast
			}
		});
	});
});
```



### send

> 可以判斷傳送類型

```js
// client
socket.send(JSON.stringify({
      type:'drawing',
      x0: x0 / w,  
      y0: y0 / h,
      x1: x1 / w,
      y1: y1 / h,
      color: color
}))

socket.onmessage = function(event){
	if (data.type == 'drawing') {....}
}

// server 也可以用JSON.stringify傳送 指定內容
wss.clients.forEach(function each(client) {
    if (!client.isClosed) {
        client.send(JSON.stringify({
            type:'id',
            id: 0
        }));  // broadcast message
    }
});
```

