>  搜尋引擎是用crawl去爬

> 爬蟲要有道德，如果一直抓，會被鎖IP(爬蟲可以用來攻擊(DOS Attack; 阻斷服務，讓系統癱瘓))

* header，想要看JS可以看[阮一峰的網站](http://www.ruanyifeng.com/blog/2019/09/curl-reference.html)

```


回應: HTTP/1.1 200 OK // 網頁一定是傳200，不是200就有問題

請求: get或是post url HTTP..





可以指定網頁Agent，可以騙伺服器讓他以為你是瀏覽器 crawl -A
```

> 可以對付爬蟲，利用產生假網址，一直讓爬蟲爬到假網址，內容都是gabege

> 爬蟲也可以用來測試，測試自動化，讓他自己去點(end-to-end test)



> 使用爬蟲抓網址

```js
// 可以在終端輸入，用網址去抓
let url = Deno.args[0]
console.log('fetch page at : ', url)
const res = await fetch(url);
const data = await res.text(); // 顯示網站HTML
console.log(data)

```





> 爬蟲範例，會一直抓，只要有連到超連結就會把資料丟到data裡面，不過這個只偵測絕對路徑

```js

async function getPage(url) {
  const res = await fetch(url);
  return await res.text();
}

// 會把所以網站的超連結加入urlList，所以會一直抓到記憶體到底
function html2urls(html) {
  // http或https(\shref\s*)才抓，相對路徑無法顯示，所以要到下一版09才會完整
  var r = /\shref\s*=\s*['"](.*)['"]/g
  var urls = []
  while (true) {
    let m = r.exec(html)
    if (m == null) break
    urls.push(m[1])
  }
  return urls
}

// 增加url list的大小
async function craw(urlList) {
  for (let i=0; i<urlList.length; i++) {
    var url = urlList[i]
    console.log(url, 'download')
    if (!url.startsWith('http')) continue
    try {
      var page = await getPage(url)
      // 把資料丟到本地
      await Deno.writeTextFile(`data/${i}.txt`, page)
      var urls = html2urls(page)
      for (url of urls) {
        urlList.push(url)
      } 
    } catch (error) {
      console.log('error=', error)
    }
  }
}

var urlList = [
  'https://example.com', 
]

await craw(urlList)
```



> 抓相對路徑，原理是用兩個路徑，把他們合成

```js
var urlList = [
  // 'http://msn.com', 
  'https://en.wikipedia.org/'
]

var urlMap = {}

async function getPage(url) {
  try {
    const res = await fetch(url);
    return await res.text();  
  } catch (error) {
    console.log('getPage:', url, 'fail!')
  }
}

function html2urls(html) {
  var r = /\shref\s*=\s*['"](.*)['"]/g
  var urls = []
  while (true) {
    let m = r.exec(html)
    if (m == null) break
    urls.push(m[1])
  }
  return urls
}

async function craw(urlList, urlMap) {
  for (let i=0; i<urlList.length; i++) {
    var url = urlList[i]
    if (!url.startsWith("https://en.wikipedia.org/")) continue;
    console.log(url, 'download')
    try {
      var page = await getPage(url)
      await Deno.writeTextFile(`data/${i}.txt`, page)
      var urls = html2urls(page)
      // console.log('urls=', urls)
      for (let surl of urls) {
        var absurl = surl
        // 如果是相對路徑，就把他合成
        if (surl.indexOf("//")<0) { // 是相對路徑
           absurl = (new URL(surl, url)).href
           // console.log('absurl=', absurl)
        }
        if (urlMap[absurl] == null) {
          urlList.push(absurl)
          urlMap[absurl] = 0
        }
      }
    } catch (error) {
      console.log('error=', error)
    }
  }
}

await craw(urlList, urlMap)

```



* 補(ngrok):

```
127.0.0.1:8000 --> 本地隱藏port

使用 ngrok 神器，幫我們把本地的 port 對外開放
ngrok 官方的宣傳語

Spend more time programming. One command for an instant, secure URL to your localhost server through any NAT or firewall.

ngrok 希望開發者花多一點時間來寫程式，所以 ngrok 的使命就是，把 localhost server 對外開放成安全的網址。
```

