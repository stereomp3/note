> 自學網頁遊戲開發，參考網頁:  [Phaser  幫我撐個 30 天](https://ithelp.ithome.com.tw/users/20111617/ironman/1794)、[Note of Phaser3](https://rexrainbow.github.io/phaser3-rex-notes/docs/site/)

# Phaser遊戲製作

* 引入script `<script src=“//cdn.jsdelivr.net/npm/phaser@3.14.0/dist/phaser.min.js"></script>`

  

>[建創遊戲視窗](#建創遊戲視窗)



>[加入遊戲素材](#加入遊戲素材)



>[素材變形](#素材變形)



> [Scene manager](#Scene manager)



> [Audio](#Audio)



### 建創遊戲視窗

```js
// 創建場景
let scene = new Phaser.Scene('Game')

// 基本配置
let config = {
    type: Phaser.AUTO,	// 會使用 WebGL 或 Canvas API，AUTO 是讓 Phaser 決定
    width: 640,
    height: 320,
    scene			// 等同於 scene: scene
    /*scene: {           // 讓scene裡面的func對應到自己創的func
        preload: preload,
        create: create,
        update: update
    }*/
}

// 創建遊戲
let game = new Phaser.Game(config)
life_span()
```



### 加入遊戲素材

> 遊戲整體架構

```js
function life_span(){
    // 生命週期_初始
    scene.init = function() {  // constructor
        // 生命週期 init 上，定義變數，這樣就不用寫在 update 裡，並統一接口。
        this.playerSpeed = 1
        this.keyboard = null
    } 

    // 生命週期_加載素材
    scene.preload = function() {
        this.load.image('bg', 'assets/bg.png')  		//「bg」當作一個標籤
        this.load.image('player', 'assets/player.png')  //「player」當作一個標籤
    }
    
    scene.create = function(){
        // add.sprite(x, y, key, frame)
        // let bg = this.add.sprite(0, 0, 'bg')
        // let player = this.add.sprite(0, 0, 'player')
        this.bg = this.add.sprite(0, 0, 'bg')
        this.player = this.add.sprite(0, 0, 'player') // 使用this是讓其他函數可以對create裡面的變數進行操作(因為他已經變成scene.play了)
        this.player.depth = 1	// 預設 depth(z-index) 為 0，這裡設定 1
        
        // 方法 1 ) 把圖片的中心點設為 (0,0) 左上角
        this.bg.setOrigin(0,0)

        // 方法 2 ) 抓取原本設定的 config
        let width = this.sys.game.config.width	// 取得 config 的 width : 640
        let height = this.sys.game.config.height// 取得 config 的 width : 320
        this.player.setPosition(width / 2, height / 2)	// 也就是 this.add.sprite(320, 160, 'player')
        
    }

    scene.update = function(){
        console.log('update')
    }
}
```



### 素材變形

> 可以放在scene.create裡面，在創建時就決定好大小

```js
scene.create = function(){
    //前面內容....
// 調整大小，像CSS的 transform: sacle(x, y)。
    // 方法 1 )  兩倍大小的圖片物件，可以省略成 setScale(2)
    this.player.setScale(2, 2)

    // 方法 2 ) 針對xy設定大小
    this.bg.scaleX = 0.5
    this.bg.scaleY = 0.5 	

    // 方法 3 ) 直接設定寬度，可以讓背景對齊遊戲視窗		
    this.bg.displayWidth = width
    this.bg.displayHeight = height
        
## 圖片左右是否翻轉，像cs的 rotateX(180deg)、rotateY(180deg)     
    // 方法 1 )  用 setFlip 來設定 X 和 Y 翻轉
    this.player.setFlip(true, true)

    // 方法 2 ) 直接用 flipX 和 flipY 來更改
    this.bg.flipX = true
    this.bg.flipY = true

## 圖片角度翻轉
    // 方法 1 )旋轉角度的設定，使用「角度」，等同 player.angle = 45
    this.player.setAngle(45)

    // 方法 2 ) 旋轉角度的設定，使用「弧度」，等同 player.rotation = Math.PI / 4
    this.player.setRotation(Math.PI / 4)
    
## 可以使用多種方法在同一物件上
    // 旋轉90度然後縮小0.3倍
    this.player.setAngle(-90).setScale(0.3) 
}

// 透明度調整
this.player.alpha = 0.5

// 可以在update裡面加上角度，可以讓角色轉起來
scene.update = function() {
    //前面內容....
    this.player.angle += 0.5
}


### !! 如果上面沒有用 this.bg(let bg)就不用加this直接用bg就好
```



## Scene manager

> [Scene manager](https://rexrainbow.github.io/phaser3-rex-notes/docs/site/scenemanager/)可以對場景做切換，或者用圖層的概念疊畫面

```JS
// initialization
var GUI = {
    preload,
    create,
    update
}

// 在創建完成遊戲之後，可以用下面這個新建一個新的場景，一開始不會運作，要呼叫之後才會動
let game = new Phaser.Game(config)
game.scene.add("GUI", GUI)

// 可以新建函式對新畫面做操作
function StartGUI(){
    //console.log(testx)
    GUI.preload = function() {
        //...
    }
    GUI.create = function(){
        //...
    }
    
    GUI.update = function(){
        //...
    }
}
```



>常用的scene呼叫

```JS
## 在主要場景中可以呼叫新的場景
// 下面這個是把剛剛建立的GUI和原本的場景一起運作，GUI在下層
Mainscene.scene.launch("GUI") // "key"

// 關掉主場景(會被重置)，換成GUI場景
Mainscene.scene.start("GUI")

// 主場景sleep，換成GUI場景
Mainscene.scene.switch("GUI");    

// 目前場景重置
Mainscene.scene.restart()

// update關、renders開、不會重置(no shutdown)
Mainscene.scene.pause(key);

// update關、renders關、不會重置(no shutdown)
Mainscene.scene.sleep(key);  // timer會被暫停

// update關、renders關、重置(shutdown)
Mainscene.scene.stop(key);

Mainscene.scene.resume(key);    // 恢復pause

Mainscene.scene.wake(key);      // 恢復sleep
 
Mainscene.scene.run(key, data); // 上面的暫停這個都可以恢復


// 設置場景可不可見
Mainscene.scene.setVisible(value, key);  // value = true | false


// 兩個場景位置(圖層)互換
Mainscene.scene.swapPosition(key);
Mainscene.scene.moveAbove(key);

// 把keyScene調到Mainscene的上面
Mainscene.scene.moveAbove(key);



// 取得Mainsscene **可以用裡面的物件!!**
this.nowScene = Mainscene.scene.get(key)
this.nowScene.player.x => Mainscene.player.x
```



## Audio

```JS
scene.preload = function() {
    this.load.audio('music', 'audio/music.png');  // 載入音樂
}


// 音樂播放
scene.sound.play('music');


// 創造音樂物件
var music = scene.sound.add(key);

// 音樂播放，這個其實跟上面一樣 --> scene.sound.play('music');
music.play();

// 也可以設定音樂物件配置放到play裡面
let music_config = { // default
    mute: false,
    volume: 1,
    rate: 1,
    detune: 0,
    seek: 0,
    loop: false,
    delay: 0
}
music.play(config);
music.play({volume: 0.5, loop: true})

// 暫停音樂
music.stop();  // 直接停掉，無法繼續
music.pause(); // 暫停

// 音樂繼續
music.resume();

```





