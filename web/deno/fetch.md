## fetch

> 這個是web2.0的東西，不像之前1.0版的前端後端並重，這個比較吃前端。
>
> 1.0版本是操作寫在render裡面，後端import render，對他進行操作。
>
> 而2.0是把東西都放在前端，不過前端使用fetch去和後端進行資料交互
>
> ajax 和 fetch --> [ajax & fetch & axios](https://ithelp.ithome.com.tw/articles/10244631)
>
> **注意!!，使用fetch要利用onclick觸發函式，所以form的最後不是用 `type = "submit`, 而是`type="button"`**

```js
var R = {}

// 這邊的東西都是前端的
// 相當於前端的router，利用hash(#後面的)去操作
window.onhashchange = async function () {
  var r
  // #後面的東西(包含)     // window.location.ref: 全部的url
  var tokens = window.location.hash.split('/')  // 用/把標籤隔開放入陣列(str to list)
  console.log('tokens=', tokens)
  switch (tokens[0]) {
    case '#show':
      // 這裡使用fetch的get，先到/post/:id呼叫後端的show，show把文字檔丟到網站上後
      // 再用r.json把字串轉json，最後放到show(post)裡面呈現
      r = await window.fetch('/post/' + tokens[1])       
      let post = await r.json()  
      R.show(post)
      break
    case '#new':
      R.new()
      break
    default:
      r = await window.fetch('/list')
      let posts = await r.json()
      R.list(posts)
      break
  }
}

window.onload = function () {
  // hash(#後面的)有任何改變就會觸發
  window.onhashchange()
}

// 把內容丟到html裡面(title 放到網站標題，id = 'content'的區塊填資料進去)
R.layout = function (title, content) {
  document.querySelector('title').innerText = title 
  document.querySelector('#content').innerHTML = content
}

R.list = function (posts) {
  let list = []
  for (let post of posts) {
    list.push(`
    <li>
      <h2>${post.title}</h2>
      <p><a id="show${post.id}" href="#show/${post.id}">Read post</a></p>
    </li>
    `)
  }
  let content = `
  <h1>Posts</h1>
  <p>You have <strong>${posts.length}</strong> posts!</p>
  <p><a id="createPost" href="#new">Create a Post</a></p>
  <ul id="posts">
    ${list.join('\n')}
  </ul>
  `
  return R.layout('Posts', content)
}

R.new = function () {
  return R.layout('New Post', `
  <h1>New Post</h1>
  <p>Create a new post.</p>
  <form>
    <p><input id="title" type="text" placeholder="Title" name="title"></p>
    <p><textarea id="body" placeholder="Contents" name="body"></textarea></p>
    <p><input id="savePost" type="button" onclick="R.savePost()" value="Create"></p>
  </form>
  `)
}

R.show = function (post) {
  return R.layout(post.title, `
    <h1>${post.title}</h1>
    <p>${post.body}</p>
  `)
}

// 之前的寫法是用server端把表單裡面的東西拿出來，這個是用客戶端，比較省錢 // 在R.new裡面呼叫
R.savePost = async function () {
  let title = document.querySelector('#title').value
  let body = document.querySelector('#body').value
                  // 把東西丟到 /post  這邊可以觸發後端的create函式
  let r = await window.fetch('/post', {
    // 把json物件轉成字串
    body: JSON.stringify({title: title, body: body}),
    method: 'POST',
    headers: {
      'Content-Type': 'application/json'
    }
  })
  window.location.hash = '#list'
  return r
}
```



> 後端接收的程式碼需要加上ctx.response.body = "???"，讓網頁有內容，才不會報錯(網頁不會顯示)



> fetch可以取得當前狀態，由server回傳，200是成功，其他的則會報錯

```js
let r = await window.fetch('/login', {
        // 把json物件轉成字串
        body: JSON.stringify({username: username, password: password}),
        method: 'POST',
        headers: {
        'Content-Type': 'application/json'
        }
    })
    console.log("r.status = " + r.status)  // 200 成功
	// 對應到後端的ctx.response.status
```





> fetch可以取得get的內容，利用then把他的promise物件轉成文字:

```js
let r = window.fetch('/login', {
    // 把json物件轉成字串
        body: JSON.stringify({username: username, password: password}),
        method: 'POST',
        headers: {
        'Content-Type': 'application/json'
        }
    })

  r.test().then(function(data) {
        console.log(data); // this will be a string --> 對應到後端的ctx.response.body 
        if(data=="success") {
            window.location.hash = '#loginSuccess' // 切換到成功頁面
            sideNav.login()
        }
        else window.location.hash = '#loginFail'
  });
```













> 前端console.log在網頁看，後端console.log在terminal裡面看

