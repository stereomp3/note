> 參考網站: https://developer.mozilla.org/zh-TW/docs/Web/API/Document/createElement、https://ithelp.ithome.com.tw/articles/10191867



## 增加節點

> [Document.createElement()](https://developer.mozilla.org/zh-TW/docs/Web/API/Document/createElement)

```js
document.body.onload = addElement; // 在網頁運作時執行

function addElement () {
  var newDiv = document.createElement("div"); // 新增節點
  var newContent = document.createTextNode("Hi there and greetings!"); // 增加節點文字
  newDiv.appendChild(newContent); // 新增到節點下面(div裡面)

  var currentDiv = document.getElementById("div1");  // 取得位置
  document.body.insertBefore(newDiv, currentDiv);  // 新增節點到指定位置
}
```



## 刪除節點

> [removeChild](https://ithelp.ithome.com.tw/articles/10191867)

```html
<ul id="myList">
    <li>Item 01</li>
    <li>Item 02</li>
    <li>Item 03</li>
</ul>
      
<script>
    var myList  = document.getElementById('myList'); // 取得容器
    var removeNode = document.querySelectorAll('li')[1]; // 取得 "<li>Item 02</li>" 的元素
    myList.removeChild(removeNode); // 將 myList 下的 removeNode 節點移除
</script>
```





## 新增區域

> 利用新增節點的id，對節點做innerHTML的處裡

```js
document.body.onload = addElement; // 在網頁運作時執行

function addElement () {
   var newDiv = document.createElement("div"); // 新增節點
    newDiv.id = "test"
    document.body.appendChild(newDiv)  // 新增到body下面
    document.getElementById("test").innerHTML = `<h1>asdasdasd</h1>`
}
```



## 刪除區域

> 取得物件的parent，再用removeChild 刪除

```html
<ul id="myList">
    <li>Item 01</li>
    <li>Item 02</li>
    <li>Item 03</li>
</ul>
      
<script>
    var myList  = document.getElementById('myList'); // 取得容器
    var parentObj = myList.parentNode; // 獲取parent，其實就是document.body
    parentObj.removeChild(myList); // 將 myList移除
</script>
```



