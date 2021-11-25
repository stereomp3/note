> 自學網頁遊戲開發，參考網頁:  [Phaser  幫我撐個 30 天](https://ithelp.ithome.com.tw/users/20111617/ironman/1794)、[Note of Phaser3](https://rexrainbow.github.io/phaser3-rex-notes/docs/site/)

#  創建物理條件



## Arcade

>Phaser 配有內建的物理系統，[Arcade](https://rexrainbow.github.io/phaser3-rex-notes/docs/site/arcade-world/)是其中一個，下面就用這個套件呈現

```js
let config = {
    //...
    physics: {
        default: 'arcade',
        arcade: { 
            gravity: { y: 1000 },     // 每秒下降多少
            debug: true               // debug 提供給我們更多畫面訊息，更有幫助開發
        }
    }
}

// 載入圖片
scene.preload = function() {
    this.load.image('ground', 'assets/ground.png')
}

scene.create = function() {
    //...
    // 製作平面
    // (方法一
    // 讓物件具有物理條件 (有重力)
    let ground = this.add.sprite(180, 400, 'ground')
    this.physics.add.existing(ground)

    // 取消重力
    ground.body.allowGravity = false
    // 不受重力、碰撞影響而變更位置
    ground.body.immovable = true

    // 直接創建具有物理條件的物件
    let ground2 = this.physics.add.sprite(180, 200, 'ground')

    // 讓兩個物件產生碰撞
    this.physics.add.collider(ground, ground2)
    
    
    // (方法二
    let ground = this.add.sprite(180, 400, 'ground')
    // 設為true讓物體變成靜態
    this.physics.add.existing(ground, true)

    let ground2 = this.physics.add.sprite(180, 200, 'ground')
    
    this.physics.add.collider(ground, ground2)
}
```



## Arcade Body

> [設定物理性質](https://rexrainbow.github.io/phaser3-rex-notes/docs/site/arcade-body/?h=body)

```js
// Get physics body
var body = ground.body;

// default set (一部分)
body.setImmovable = false;  // 受重力、碰撞影響而變更位置
body.pushable = true;  // 物件可推動
body.moves = true;  // 物件可移動
body.setAllowGravity = true;  //物件有重力
body.setCollideWorldBounds= false;  // 沒有世界邊線


body.onFloor(); //  body.blocked.down 在地面時為true
body.onCeiling(); //  body.blocked.up 碰到天花板時為true
body.onWall();  // body.blocked.left || body.blocked.right 碰到左邊或右邊牆壁為true

body.reset(x, y);  //  物件移動到(x, y)
body.stop();  // 速度，加速度，重力...歸零
body.velocity.y = var

body.setMass(m);  // 設置質量
body.setVelocityY(-500)  // 設置速度
body.setAcceleration(x, y);  // 設置加速度

body.setBounce(x, y);   // 讓物體有彈性

// 調整物件碰撞邊框
body.setSize(width, height, center);   // 矩形
body.setCircle(radius, offsetX, offsetY);  // (橢)圓形

// 增加碰撞
scene.physics.add.collider(objectsA, objectsB); // scene如果在scene.裡面可以用this


// 設置世界邊界                
scene.physics.world.setBounds(x, y, width, height);
// 取得邊界數值
var top = body.world.bounds.top;
var bottom = body.world.bounds.bottom;
var left = body.world.bounds.left;
var right = body.world.bounds.right;

// 刪除物理性質
scence.physics.world.disable(gameObj)


```

