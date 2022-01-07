

# 第五周筆記

## form表單

* form 會使網頁換頁，是web1.0用的，web2.0是用JS傳送資料

```html
<form action="/post" method="post">  
    <!--文字輸入 (default value)-->
    <p><input type="text" placeholder="Title" name="title"></p>
    <!--選時間-->
    <p><input type="time" placeholder="預定行程時間" name="date"></p>
    <!--大範圍文字輸入-->
    <p><textarea placeholder="Contents" name="body"></textarea></p>
    <!--submit會對應到action執行對應的動作，這裡是切分頁到post
		submit會丟出name的值當作鍵(key)，內容當作值(value)，可以用
		const 變數 = await body.value`接收						-->
    <p><input type="submit" value="Create"></p>
    <!--選項選擇-->
    <select name="cars" id="cars">
        <option value="volvo">Volvo</option>
        <option value="saab">Saab</option>
        <option value="opel">Opel</option>
        <option value="audi">Audi</option>
  </select>
</form>

```

| `<input type="range" min="0" max="50">` | 拉條可以設最大最小值，也可以用id配label的for                 |
| :-----------------------------------: | ------------------------------------------------------------ |
|         `<input type="search">`         | 尋找通常會用id配label的for(說明)，再加name讓submit可以傳回到後端 |
|         `<input type="color">`          | 選顏色                                                       |
|          `<input type="date">`          | 選日期                                                       |
|     `<input type="datetime-local">`     | 可以選日期和時間                                             |
|         `<input type="month">`          | 選年和月                                                     |
|          `<input type="week">`          | 選年和周                                                     |
|          `<input type="file">`          | 放入文件檔案                                                 |
|         `<input type="hidden">`         | 隱藏的，沒東西                                               |
|         `<input type="image">`          | 放圖片                                                       |
|         `<input type="number">`         | 輸入數字                                                     |
|         `<input type="email">`          | 輸入信箱                                                     |
|        `<input type="password">`        | 輸入密碼                                                     |
|        `<input type="checkbox">`        | 多選框通常會設定id，搭配label的for指定選項                   |
|         `<input type="radio"> `         | 單選框通常會設定id，搭配label的for指定選項                   |
|         `<input type="reset">`          | 所有form裡面的input重設                                      |
|          `<input type="tel"> `          | 填入電話                                                     |
|          `<input type="url"> `          | 傳網址                                                       |
|         `<input type="button"> `        | 普通按鍵                                                     |
|                                       |                                                              |

## From Attributes

| Attribute      | Value                                                        | Description                                                  |
| :------------- | :----------------------------------------------------------- | :----------------------------------------------------------- |
| accept-charset | *character_set*                                              | 指定表單提交的字符編碼                                       |
| action         | *URL*                                                        | 指定表單提交的數據要發到哪裡                                 |
| autocomplete   | on、 off                                                     | 指定表單是否應打開或關閉自動完成功能                         |
| enctype        | application/x-www-form-urlencoded、 multipart/form-data、 text/plain | 指定提交到服務器時應如何編碼表單數據（僅適用於 method="post"） |
| method         | get、 pos                                                    | 指定發送表單數據時使用的 HTTP 方法，get會讓資料在連結顯示，post在內容顯示，比較安全 |
| name           | *text*                                                       | 指定表單的名稱                                               |
| novalidate     | novalidate                                                   | 指定提交時不應驗證表單                                       |
| rel            | external、 help、 license、 next、 nofollow、 noopener、 noreferrer opener、 prev、 search | 指定鏈接資源和當前文檔之間的關係                             |
| target         | _blank、 _self、 _parent、 _top                              | 指定在何處顯示提交表單後收到的response                       |



> 參考網站: https://www.w3schools.com/tags/tag_input.asp

## 小型資料庫(sqlite; 資料量<10**5)

* 資料庫會幫你處理一些文字轉換，幫你把資料放在 .db檔案裏面

* db.query("裡面是資料庫的指令，跟ls，pwd很像")，只有添加修改創建要加db，讀取不用

* 所有SQLite語句開頭可以以任何關鍵字，如SELECT，INSERT，UPDATE，DELETE，ALTER，DROP等；所有的語句用分號結束。

* query() 回傳是列表包字典

  > use
  >
  > ```
  > import { DB } from "https://deno.land/x/sqlite/mod.ts";
  > ```
  
  > create
  >
  > ```sqlite
  > CREATE TABLE 可以加條件 創建資料名(資料欄位1 資料類型, 資料欄位2 資料類型, ...)
  > 資料類型可以寫 -> INTEGER PRIMARY KEY AUTOINCREMENT 表示自動生成遞增的整數(id)
  > ```
  
  > SELECT
  >
  > ```sqlite
  > SELECT 資料欄位1, 資料欄位2, ...
  > FROM   創建資料名
  > WHERE  符合的資料(資料欄位1 = 10之類的)
  > ```
  
  > INSERT
  >
  > ```sqlite
  > INSERT INTO 創建資料名 (資料欄位1, 資料欄位2,...)]  
  > VALUES (可以填值, 也可以不填值, ?,...); /*不填值(?)的話後面要補變量(,var1,var2)*/
  > ```
  
  >DELETE
  >
  >```sqlite
  >DELETE FROM 創建資料名
  >WHERE  符合的資料
  >```



> 參考文章: http://tw.gitbook.net/sqlite/sqlite_create_table.html

## else

* 網路使用別人的東西要注意授權!!   ALL Right Reserved

* pm2 nodejs npm

* linode + pm2

```e
root@localhost:~/pub6# vim run1.sh
root@localhost:~/pub6# ls
app          _footer.md  README.md  run.sh       static
favicon.ico  pm2run.sh   run1.sh    _sidebar.md  web
root@localhost:~/pub6# chmod +x run1.sh
root@localhost:~/pub6# ls
app          _footer.md  README.md  run.sh       static
favicon.ico  pm2run.sh   run1.sh    _sidebar.md  web
root@localhost:~/pub6# cat pm2run.sh
開啟: pm2 start ./run.sh -f --cron="*/30 * * * *"
關掉使用: pm2 stop ./run.sh
刪掉: pm2 delete 名字
```

* flask djungle (python網站)

* PHP Golang

* pupperteer deno 可以對系統、程式做測試 

* docker Kubernetes(k8s)

* wsl --install ( linux系統，裝了windows可能變盜版，要先把windows版本保存)

  使用wsl(在studio code 可以用linux) 



```
Q:
	在函式裡面prompt()和alert()為甚麼是顯示在終端機? 使用onclick去觸發
	class不能在router裡面運作?
		obj.func, 不能直接被 oak router 呼叫。
		必須包成 (ctx)=>obj.func(ctx)
		
	如何把form input 裡面的回傳的file 存到伺服器上面? (好像只能存檔名
	--> Upload
	search搜尋引擎? 12-elasticsearch
	
	如何不讓if有優先順序?
	switch(this.keyboard): case left.down 不行跑，要如何實現功能?
	
```

