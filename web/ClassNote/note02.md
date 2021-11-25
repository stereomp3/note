* typscript 是把js的檔加上型態

```
Router裡面的method
get 
add
delet
post
```

### 樣板字符串 (通常是用` HTML `)

```js
字符串裡面可以傳參，使用:
 --> "/book/:id"  --> id是參數

for (let i=1; i<=9; i++)
	let row = `<tr><th>${i}</th>`
	for (let j=1; j<=9; j++) {
 	    row += `<td>${i+j}</td>` // 裡面可以加上變數利用${variable}
	}
```

* **如果有寫JS檔(輸出型式)要轉成HTML 可以用 deno run ???.js > ???.html**

* 對陣列處理

    陣列增加元素:
    陣列.push(element)
    
    陣列移除最後元素:
    陣列.pop()
    
    html元素內容物件...:
    html元素.append(element)
    
    陣列轉str:
    陣列.join("分隔符號")
    
    str轉陣列:
    str.split("分隔符號")

```
Q: 如何將CSS文件傳入到樣板字符串中
Q: html檔案可以直接放到樣板字符串或是JS裡面嗎?
Q: 為甚麼在終端機會顯示return的東東? 跟伺服器有關嗎?
Q: 網頁版跟本地版樣板為甚麼會有差?
```

