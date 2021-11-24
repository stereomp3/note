> 參考網站: [w3schools](https://www.w3schools.com/tags/tag_iframe.ASP)

## iframe

> iframe可以用把其他網站放入自己的網站裡面，~~像我就是要用github放遊戲放前端然後自己的伺服器只需要負荷後端，爽賺(X~~

```HTML
<--! 使用iframe，把要抓的網站網址寫進來，並設定他的寬和高，當然也可以加上style-->
<iframe src="/default.asp" width="100%" height="300" style="border:1px solid black;">
</iframe>
    
下面是一些好用的iframe屬性
    
```



> iframe好用屬性

* 設置視窗不能滑動`scrolling="no"`

* 讓iframe不要有邊框 `frameborder="0"`

* 全螢幕 

  `allowfullscreen="true"`、`webkitallowfullscreen="true"`、`mozallowfullscreen="true"`



> 把網頁直接丟到iframe裡面

```CSS
siframe{
    position: fixed;
    left: 10%;s
    top: 0;
    width: 90%;
    height: 100%;
}
```

