大致資料庫操作


```js
import { DB } from "https://deno.land/x/sqlite/mod.ts";

const db = new DB("data.db"); // 創建資料庫

// 拿取資料庫全部內容
// postQuery("SELECT id, username, title, body FROM Posts")

// 直接執行資料庫查詢
// sqlcmd("INSERT INTO posts (username, title, body) VALUES (?, ?, ?)", [user, post.title, post.body])

// 防報錯出問題，主要SQL操作
function sqlcmd(sql, arg1) {
  console.log('sql:', sql)
  try {
    var results = db.query(sql, arg1)
    console.log('sqlcmd: results=', results)
    return results
  } catch (error) {
    console.log('sqlcmd error: ', error)
    throw error
  }
}

// 把列表轉成字典
function postQuery(sql) {
  let list = []
  // table column
  for (const [id, username, title, body] of sqlcmd(sql)) {
    list.push({id, username, title, body})
  }
  console.log('postQuery: list=', list)
  return list
}
```





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

  > SELECT  可以把東西拿出來，使用裡面的值  EX: post.title , post.id, post.body....
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
  > VALUES (可以填值, 也可以不填值, ?,...); /*填值(?)的話後面要補變量(,var1,var2)*/
  > ```

  > UPDATE
  >
  > ```sqlite
  > UPDATE 創建資料名
  > SET 欄位1 = 值, 欄位2 = 值...
  > WHERE 符合的資料
  > ```
  
  >DELETE
  >
  >```sqlite
  >DELETE FROM 創建資料名
  >WHERE  符合的資料
  >```



> 參考文章: http://tw.gitbook.net/sqlite/sqlite_create_table.html