> 自學網頁遊戲開發，參考網頁:  [Phaser 幫我撐個 30 天](https://ithelp.ithome.com.tw/users/20111617/ironman/1794)、[Note of Phaser3](https://rexrainbow.github.io/phaser3-rex-notes/docs/site/)、[Create a Perloader](https://gamedevacademy.org/creating-a-preloading-screen-in-phaser-3/)

# 遊戲製作畫面處理

> [調整螢幕大小](#調整螢幕大小)



>[動畫特效](#動畫特效)



>[畫面載入](#畫面載入)



> [螢幕畫面跟隨](#螢幕畫面跟隨)



> [燈光效果](#燈光效果)



### 調整螢幕大小

> 利用HTML、CSS和JS對canvas進行調整

```html
<!--HTML、CSS-->
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <style> 
        body {
            margin: 0;
            background-color: #000000;
        }
        canvas {
            position: absolute;
            /*讓遊戲畫面在中間*/
            top: 50%;
            left: 50%;
            /*translate3d(橫坐標, 縱坐標, 上下層位置)*/
            transform: translate3d(-50%, -50%, 0);
        }
      </style>
</head>
```

```js
// 網頁開著時，就會自己執行
window.onload = function() { 
    function resize() {
        let canvas = document.querySelector('canvas')
        let ww = window.innerWidth
        let wh = window.innerHeight
        let wRatio =  ww / wh
        let gameRatio = config.width / config.height
        if (wRatio < gameRatio) {
            canvas.style.width = ww + 'px'
            canvas.style.height = ( ww / gameRatio ) + 'px'
        } else {
            canvas.style.width = ( wh * gameRatio ) + 'px'
            canvas.style.height = wh + 'px'
        }
    }
    resize()
    // target.addEventListener(type, listener, options); 觸發視窗改變時，就發起函式
    window.addEventListener('resize', resize, false)	// 偵聽事件 resize
}
```

>  獲取螢幕寬可以用  **let width = this.sys.game.config.width**，高也用同樣方法。

### 動畫特效

>這裡使用pharse3裡面的[Camera](https://rexrainbow.github.io/phaser3-rex-notes/docs/site/camera/)

```JS

// 假如撞到坦克，會一直呼叫 gameOver，這時候我們還要特別處理不要呼叫多次的 gameOver

scene.init = function() {
    .....
    this.isGameOver = false
}

scene.update = function() {
    if (this.isGameOver) return
    if (遊戲失敗條件) {this.gameOver()}
    .....
}

// 在這裡加上遊戲結束特效
scene.gameOver = function() {
    // 500 ms 相機 shake 效果
    this.cameras.main.shake(500)					
    
    // 偵聽 shake 動畫結束
    this.cameras.main.on('camerashakecomplete', () => {
        // 500 ms 相機 fade 效果
        this.cameras.main.fade(500)				
    })
    
    // 偵聽 fade out 動畫結束
    this.cameras.main.on('camerafadeoutcomplete', () => {	
        // 遊戲重新
        this.scene.restart()						
    })
}
```



## 畫面載入

> [text](https://rexrainbow.github.io/phaser3-rex-notes/docs/site/text/)、[loader](https://rexrainbow.github.io/phaser3-rex-notes/docs/site/loader/)、[Graphics](https://rexrainbow.github.io/phaser3-rex-notes/docs/site/graphics/?h=graphics)

```js
## text
scene.create = function () { 
    // ...
    // 加入文字                x    y   文字內容
    this.text = this.add.text(30, 20, 'x: 50', {
        font: '24px Open Sans',   // 文字樣式
        fill: '#000000'           // 顏色
    })
    this.keyboard = this.input.keyboard.createCursorKeys()
}

// 在 update 這邊，當操作 man 的時候，把 man 的 x 數值，更新到 text 上
scene.update = function () {
    //...
    if (this.keyboard.right.isDown) {
        this.text.setText('x: ' + 2)    // 更改顯示文字內容
    } 
}

## loader
scene.preload = function() {
    //... 
    // 創建 text
    let percentText = this.add.text(320, 160, '', {
        font: '24px Open Sans',
        fill: '#ffffff'
    }).setOrigin(0.5, 0.5)  // 文字置中
    
    let assetText = this.add.text(320, 200, '', {
        font: '18px monospace',
        fill: '#ffffff'
    }).setOrigin(0.5, 0.5) 
    
	// 畫出進度條
    var progressBar = this.add.graphics();
    var progressBox = this.add.graphics();
    progressBox.fillStyle(0x222222, 0.8); // fillStyle(color, alpha)
    progressBox.fillRect(150, 135, 320, 50);  // fillRect(x, y, width, height)
    
    // 偵聽處理檔案
    this.load.on('progress', value => {
        percentText.setText(parseInt(value * 100) + '%')
        progressBar.clear();  // 避免進度條一直疊加
        progressBar.fillStyle(0xffffff, 1);
        progressBar.fillRect(160, 145, 300 * value, 30);
        console.log(value)
    })
    // 顯示處理文件
    this.load.on('fileprogress', file => {
        assetText.setText('Loading asset: ' + file.key);
        console.log(file.src);
    });

    // 偵聽載入檔案結束
    this.load.on('complete', () => {
        percentText.destroy()		// 載入完，把它從畫面上清除
        progressBar.destroy();
        progressBox.destroy();
    })
}
```



## 螢幕畫面跟隨

> camera 跟隨著 player 的位置

```js
scene.create = function() {
    // 設定物理邊界
	this.physics.world.setBounds(0, 0, 1000, 1000); // setBounds(x, y, width, height)
	//...
    // 設定相機邊界      
    this.cameras.main.setBounds(0, 0, 1000, 1000)  // setBounds(x, y, width, height)
    this.cameras.main.startFollow(this.player)  // 相機跟隨
}


```



## 燈光效果

> 使用[SpriteIlluminator](https://www.codeandweb.com/spriteilluminator/tutorials/normal-map-painting-with-spriteilluminator)來做出normal maps，如果這個效果要用在sprite sheet要特殊方法，這裡就不提了

```js
scene.preload = function () { 
    //...
    // 加載圖像, player02.png 為一般圖像 ;  player02_n.png 為 normal map
    this.load.image('player02', ['assets/player02.png', 'assets/player02_n.png']);
}

scene.create = function() {
    let player02 = this.add.sprite(250, 300, 'player02')
    player02.setScale(0.5)
    
    // 讓角色接受光源
    player02.setPipeline('Light2D')

    // 在 (350, 250) 位置添加半徑 200 的光源
    let light = this.lights.addLight(350, 250, 200)
    this.lights.enable()
        
    // 設定環境燈
    this.lights.setAmbientColor(0x555555)

    // 滑鼠移動，變更燈光位置
    this.input.on('pointermove', function (pointer) {
        light.x = pointer.x;
        light.y = pointer.y;
    });
}
```















