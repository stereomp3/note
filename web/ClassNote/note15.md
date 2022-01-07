使用 deno 的 [dvm](https://github.com/justjavac/dvm)套件(版本管理器)，讓版本可以自由切換



deno install ?? 可以把套件裝到系統裡面，直接使用



老師的區塊鍊套件: [github](https://github.com/cccdeno/coin6)、 套件放在網頁上用deno 裝https://cccdeno.github.io/coin6/coin6.js

老師有發布教學，在9:55左右





```
$ 代表在命令列
$ deno install -A https://cccdeno.github.io/coin6/coin6.js
$ coin6 create chain
$ coin6 start chaining

另外開一個視窗

$ coin6 start mining
```



peer to peer

```
				E連進去peertopeer
				A告訴E有BC
		A      ------------->   E (E再連到B，B再告訴E有...)

B				C

		D
		
之後就可以挑選近的做互聯網，越多人使用這種架構的網路就越快
```





lib6函數: https://deno.land/x/lib6@v0.5/src/util.ts

```js
export function sleep(ms:number) {
    // 把setTimeout設成Promise物件，要await才能用
    return new Promise(resolve => setTimeout(resolve, ms));
}
```





pub/sub -> publish/subscription

最常用在訊息駐列

可以用在區塊鍊，讓pub傳給有sub的電腦

也可以用在認證上面

範例:

```js
//pubcoin.js

import * as lib6 from 'https://deno.land/x/lib6/mod.ts'

// import the connect function
// import { connect, StringCodec } from "../../src/mod.ts";
import { connect, StringCodec } from "https://deno.land/x/nats/src/mod.ts";

// to create a connection to a nats-server:
const nc = await connect({ servers: "demo.nats.io:4222" });

// create a codec
const sc = StringCodec();
// create a simple subscriber and iterate over messages
// matching the subscription
const sub = nc.subscribe("coin6_channel");

let count = 0
while (true) {
  await lib6.sleep(1000)
  console.log('pub:', count++)
  nc.publish("coin6_channel", sc.encode(""+count));
}

await nc.drain()
```

```js
//subcoin.js

import * as lib6 from 'https://deno.land/x/lib6/mod.ts'

import { connect, StringCodec } from "https://deno.land/x/nats/src/mod.ts";

// to create a connection to a nats-server:
const nc = await connect({ servers: "demo.nats.io:4222" });

// create a codec
const sc = StringCodec();
// create a simple subscriber and iterate over messages
// matching the subscription
const sub = nc.subscribe("coin6_channel");  // 訂閱頻道

for await (const m of sub) {
       				// 目前收到第幾個訊息       // 訊息內容
  console.log(`sub:[${sub.getProcessed()}]: ${sc.decode(m.data)}`);
}

await nc.drain()
```





({})()  JS在最後加上()代表馬上執行函式，不用再呼叫他



> !! git add -A 在合作是大忌，合作用git add 資料夾或是檔案