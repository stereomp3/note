## Script

* Audio: 放音樂相關的檔案
  * AudioManager: 統一管理聲音，使用 instance物件，再呼叫play()函式就可以播放音效
  * Sound: 定義聲音模板 // 無法使用 會出現錯誤 ???



* bulletMode: 存放子彈的地方

  * Bullet: 統一管理子彈類
  *  Bullet01: 玩家初始子彈

  

* Camera

  * SmoothFollow: 相機控制(主要)
  * ThirdPersonCamera: 相機控制(會一直震動，效果不好)

  

* Canvas

  * EnemyUIBloodeManeger: 主要負責敵人血條顯示
  * FuncListManeger:  控制按鈕、小地圖和背包的圖示是否開者，使用到StaticVar裡面的變數
  * ListManeger: 控制UI list收與開
  * PlayerUIBloodeManeger: 主要負責玩家血條顯示，有讀取文件內容(SaveSystem)
  * SettingManeger: 控制存檔讀檔案的UI介面，有用PlayerPrefs存入時間
  * StatusUpdate: 裡面有函數，可以讓turn on button click時候，把玩家資料跟新到UI上
  * TurnOnOffManeger: 控制FuncList裡面button Opne 和 Close，對應到物件
  * UI: 如果StaticVar.PlayerDeath = true; 就會消失
  * VirtualGamePad: 使用StaticVar裡面的變數，跟ATKMode、DialogueTrigger、HealthRecover和Trade有關連
  * WinInfo: 主要放Continue，讓玩家可以退出WinInfo
  * WinTheGame: 放在最後一個關卡，用來判定遊戲勝利(Portal_back出現觸發)

  

* Data: 後面有Data的都是[System.Serializable]物件，讓資料可以儲存

  * PermanentData: 紀錄永久物件(存檔，把下面的資料都存入)
  * PlayerData: 玩家資料，用在SaveSystem存取玩家資料時，可以直接傳遞物件
  * SaveManeger: 放在GameManeger物件裡面，觸發儲存函數(SaveSystem)，LoadPlayerHp()做LoadPlayerStatus()的內容，因為output時候會讀取不到檔案QQ(但unity可以)
  * SaveSystem: 把玩家或是其他資料序列化變成Binary檔案存放在遊戲檔案裡
  * Stage: 紀錄關卡是否通關，遊戲開始所有物件都會出現，如果通關則物件不會再出現，放在父Stage
  * StageData: 存放Stage bool[] 變數，用Stage的List填入它，遊戲是否勝利
  * StaticVar: 存放暫時性資料(遊戲是否開始、小地圖有沒有開...)，在一開始的場景出現(重製資料)，裡面有到StartScene的function 和 退出的function
  * TempData: 專門記錄Inventory物件 Item的name

  

* DialogueSystem

  * Dialogue: 用來儲存對話模型，讓有他的NPC可以有自己的對話

  * DialogueManager: 用來控制開始對話，下一段對話，結束對話

  * DialogueTrigger:  用來觸發對話，我是用`Physics.OverlapSphere`偵測玩家有沒有在附近

  * HealthRecover: NPC幫玩家回血用到，控制UI和改變玩家血量至上限

  * Trade: 可以和NPC進行交易

    

* Enemy

  * Enemy: 統一管理敵人類，裡面有傷害敵人判定和跟新敵人血量到UI上(使用EnemyUIBloodeManeger)
  * enemy01: enemy01和enemy011的行為邏輯
  * enemy01_creater: 用來生產enemy01，有生產數量上限
  * enemy02: enemy02的行為邏輯，回到基地會回血(enemy02和enemybase)
  * enemy02_creater: 用來生產enemy02，有生產數量上限
  * enemy011_creater: 用來生產enemy011，有生產數量上限
  * enemydetector_explore: 如果場上沒有敵人，就自爆

  

* Inventory 

  * Inventory: 處理Inventory邏輯，增加物品，刪除物品，物品空間，物品串列，資料(物件名稱)儲存到tempdata，再用名稱去Resources 尋找Item物件
  * InventorySlot: 增加移除UI上面的圖片和按鈕，透過 InventoryUI的UpdateUI() 觸發
  * InventoryUI: 在跟物件互動時，會顯示在UI上面(利用UpdateUI()觸發InventorySlot)
  * TradeSlot: 在跟商店物品互動時，會扣玩家的錢，並減少商品數量

  

* Items

  * Item: ScriptableObject，讓物品有基本屬性(icon、name....)

  * ItemPickUp: 把創建好的Item ScriptableObject 放到這，觸發 `Inventory.instance.Add(item);`

  * UseItem: 用名字判斷物品，使用物品功能，key是用來開門的

    

* Plant

  * Attractor: 讓有這個script的物件可以互相吸引(F = GMm/R^2)

  * EnemyDetector: 裡用Plant當圓心，偵測星球上有沒有敵人(用layer mask判斷)

  * Gravity: 專門吸引玩家的Script

  * Plant: 目前沒有用，可以控制星球transform

    

* Player

  * ATKmode: 控制攻擊邏輯，createBullet

  * Player: 統一管理玩家類
  * PlayerController: 利用很複雜的運算讓人可以在球面上跑，可以偵測建築物讓自己過不去

  

* Scene

  * GoStage1: 到Stage1，並存玩家資料，和把傳送點關閉，存到temp裡面
  * GoStartScene: 回到StartScene，並把玩家的位置載入，並儲存
  * StageManeger: 重新開始、結束遊戲...函數

  

* StartScene:  在遊戲開始或是回到StartScene會用到的script

  * GameStart: 存玩家初始狀態並把StaticVar.GameStart設為true
  * LoadStartScene: 載入玩家位置、玩家血量並儲存



Notice: 最後一關的prefab被拆了(Player、Portal_back)，玩家鏡頭有調遠，portal_back裡面有多放script(判斷遊戲勝利)

### Item

* temp: 
  * 0 stage01    # 在GoStage1改變狀態



* permanent: null





## 檔案讀取

> 下面的GetComponent都是get GameManeger物件，用裡面的script進行一系列操作

* PlayerData: 需要物件 player

  * 攻擊力: data.ATK
  * 生命、最大生命: data.health、data.max_health
  * 位置: data.positon  (float [3] // Vector3)
  * 可以用`GetComponent<SaveManeger>().LoadPlayerPos();`
  * 和`GetComponent<SaveManeger>().LoadPlayerHp();`

  

* StageData: 存取布林值， 需要物件 stage0...

  * Stage01: data.StageList[0]
  * 可以用`GetComponent<SaveManeger>().LoadStage(Stage Obj, Stage Obj.ID);`



* TempData: 需要物件 Inventory script裡面的items

  * item名稱: data.name
  * 可以用`LoasSaveItem(GetComponent<SaveManeger>().LoadTempItem());`存入

  

* PermanentData: Save把上面所有資料都取得後，Load再存入各自檔案裏面



notice: player, GameManager名字在很多script都用Find找，不要亂改名字





to do

Enemy的轉向調整

星球材質看要怎麼用

GameStop

商店抽獎?
