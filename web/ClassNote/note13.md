網站撐流量，加速 --> http://mdeditor.tw/pl/phb2/zh-tw

* 使用CDN

* 快取
  * 讀取使用者記憶體(本地緩存; 使用deno)，不是讀寫硬體
  * 分佈式緩存
  * 快取放到資料庫

* 平行
  * 使用多個伺服器

* 資料庫處理
  * 讀寫分離，讀的可以用快取加速
  * 不同類型的資料放到不同的server

* 使用正向代理、反向代理
  * 使用Nginx操作(效能超好)
  * Nginx 最好用 linux裝，window的不好用
  * 使用LVS或F5來使多個Nginx負載均衡









分佈式文件json 可以不用定義資料結構，直接亂塞資料也可以

表格用資料庫

上面兩個分開也可以撐流量



大應用拆成小應用



網站傳資料基本上都用json

互傳資料可以用fetch api 、 ajax(表格互傳) 或 websocket(繪圖板，互動)





qemu+kvm(可以讓qemu變跟下面兩種虛擬機差不多快)

virtual Box速度50%

VMWare速度50%

Docker是容器的作業系統，可以達到速度99%

可以用Docker把作業系統放在不同port，然後用Docker功能把他們串起來，就可以做出微服務



kubernates可以做到容器遷移式的功能，kubernates自己放作業係統，不用自己設定





最後用雲端承載系統



加鹽

存加鹽過的hash值

> https://deno.land/x/salt6@v0.1

```js
// signup
const password = 123  // 使用者輸入
const salt = 456  // 存在資料庫
const hash = await salt6.hash(password+salt)  // 存在資料庫

// login
```

```js
import * as salt6 from '../mod.ts';

function signup(password) {
  const salt = salt6.genSalt()
  const hash = salt6.hash(password+salt)
  return {salt, hash}
}

function login(input, salt, hash) {
  return hash == salt6.hash(input+salt)
}

// signup
let password = "csienqu123"
let {salt, hash} = signup(password)

// login
let input = Deno.args[0]
if (login(input, salt, hash)) {
  console.log('login success!')
} else {
  conso
```

```
(base) $ deno run salt1.js ccc
login fail!
(base) $ deno run salt1.js csienqu123
login success!
```





