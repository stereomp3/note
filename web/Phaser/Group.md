> 自學網頁遊戲開發，參考網頁:  [Phaser  幫我撐個 30 天](https://ithelp.ithome.com.tw/users/20111617/ironman/1794)、[Note of Phaser3](https://rexrainbow.github.io/phaser3-rex-notes/docs/site/)、[JSON](https://developer.mozilla.org/zh-TW/docs/Learn/JavaScript/Objects/JSON)、[關於你關於我關於phaser 系列](https://ithelp.ithome.com.tw/articles/10206906)

# 群組

> [Group](#Group)



> [JSON](#JSON)



> [創建tilemap](#創建tilemap)



> [生成刪除物件](#生成刪除物件)



## Group

> 如果同一個物件要用到很多次可以使用Group重複呼叫
>
> [Group](https://rexrainbow.github.io/phaser3-rex-notes/docs/site/group/)

```js
scene.create = function() {
## 新建群組
    this.houses = this.add.group({
        key: 'house',
        repeat: 5,				// 多創建 5 個
        setXY: {
            x: 350,				// 從 x 350 位置開始
            y: 50,				// 從 y 50 位置開始
            stepX: 50,			// 每 x 間隔 50
            stepY: 0
        }
    })

## 這邊使用 getChildren() 方法，來找群組底下的物件，並 scale 它們
    this.houses.getChildren().forEach(item => {
        item.setScale(0.8)
    })  
    
## 也可以創建一個容器裝靜態物件(像地形)，或是怪物群裝怪物....
    this.platforms = this.add.group()
    
    // 製作地面
    let ground = this.add.tileSprite(0, 300, 32 * 40, 32, 'ground')  // 寬重複 40 份
    this.physics.add.existing(ground, true) // 變成靜態物件
	
    // 製作第二層平面
    let ground02 = this.add.tileSprite(200, 200, 32 * 3, 32, 'ground')
    this.physics.add.existing(ground02, true)
    
    // 加入platforms裡面
    this.platforms.add(ground)	
    this.platforms.add(ground02)
    
    this.player = this.add.sprite(180, 400, 'player', 0)	// 創建 player 第 0 張
    this.physics.add.existing(this.player)

    this.physics.add.collider(this.player, this.platforms)	// 增加碰撞
    
}
```

| 新增物件到群組列表                             |       group.add(gameObject);        |
| ---------------------------------------------- | :---------------------------------: |
| 新增多個物件到群組列表                         |   group.addMultiple(gameObjects);   |
| 移除物件                                       |      group.remove(gameObject);      |
| 對物件設置屬性                                 | group.propertyValueSet(key, value); |
| 對物件新增屬性                                 | group.propertyValueInc(key, value); |
| 對物件設置座標                                 |         group.setXY(x, y);          |
| 對物件增加座標                                 |         group.incXY(x, y);          |
| 破壞群組，如果(true)則把裡面的children一起破壞 |          group.destroy();           |



## JSON

>把一些數據寫在JSON檔案裏面，之後比較好做調整

```json
// json檔
{
    "platforms": [
        { "x": 0, "y": 300, "num": 40, "key": "ground" },
        { "x": 200, "y": 200, "num": 3, "key": "ground" },
        { "x": 400, "y": 200, "num": 3, "key": "ground" }
    ]
}
```

```js
scene.create = function() {
    //...
    this.setData()  // 放入設定資料
    //...
}

scene.preload = function() {
    //...
    this.load.image('ground', 'assets/ground.png')
    // 載入json檔
    this.load.json('map', 'data/map.json')
}

scene.setData = function() {
   	this.gameData = this.cache.json.get('map') // 取得JSON檔
    this.platforms = this.add.group()
    // 取得每個素材，把他們放入platforms裡面
    this.gameData.platforms.forEach(item => {
        let w = this.textures.get(item.key).get(0).width // 取得素材的寬
        let h = this.textures.get(item.key).get(0).height  // 取得素材的高
        let obj = this.add.tileSprite(item.x, item.y, item.num * w, h, item.key)
        this.physics.add.existing(obj, true)
        this.platforms.add(obj)
    })
}
```



## 創建tilemap

> [tilemap](https://rexrainbow.github.io/phaser3-rex-notes/docs/site/tilemap/?h=map)使用的時候要和檔名一樣才讀取的到

```js
preload() {
    // tile map editor 製作的 json 檔案
    this.load.tilemapTiledJSON('map', 'data/map.json')
    // 載入tilemap
    this.load.spritesheet('RPGpack_sheet', 'assets/RPGpack_sheet.png', {
        frameWidth: 64,
        frameHeight: 64
    })
}
create() {
    //....
    this.map = this.make.tilemap({ key: 'map' })
    // 加入製作地圖使用的tilemap
    this.tiles = this.map.addTilesetImage('RPGpack_sheet')
    // 使用 Tiled Map Editor 做的 background 圖層
    this.backgroundLayer = this.map.createStaticLayer('background', this.tiles, 0, 0)

    // 使用 Tiled Map Editor 做的 block 圖層
    this.blockedLayer = this.map.createStaticLayer('block', this.tiles, 0, 0)
    // 讓背景可以站在上面
    this.blockedLayer.setCollisionByExclusion([-1])
}
```



## 生成刪除物件

>用在子彈飛行，或是敵人死亡之類的

```JS
// 創建子彈
const bullet = this.add.sprite(x, y , key, frame);

// 子彈毀滅
bullet.destory()

// 可以為子彈建立一個群組，統一設定
this.bullets = this.add.group();
this.bullets.add(bullet);
this.physics.add.existing(bullet);


```

