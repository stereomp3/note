## input Event

>使用 document.addEventListener 新增鍵盤輸入事件，再用keystate去偵測按鍵

```js
var fps, fpsInterval, startTime, timestamp = Date.now(), preTimestamp, progress;

function main() {
    startAnimating(12) // 調整fps
    //console.log(init_map(map))
    // 監聽按鍵輸入
    document.addEventListener("keydown", function (event) {//這裡的evt是接收玩家的鍵盤事件
        keystate[event.code] = true//鍵盤按下
    }, true);
    document.addEventListener("keyup", function (event) {
        keystate[event.code] = false;//放開取消事件，避免短期按太多按件
    }, true);
}

function controller(){
    if (keystate["KeyW"]) {
        // 按下W 觸發事件
    }
}
```





## fps控制

> 使用requestAnimationFrame控制螢幕刷新，再用Date.new()偵測時間，用時間差控制fps

```js
var fps, fpsInterval, startTime, timestamp = Date.now(), preTimestamp, progress;
function main() {
    startAnimating(12) // 調整fps
    //console.log(init_map(map))

    var loop = function () {
        timestamp = Date.now(); //調整速率
        progress = timestamp - preTimestamp;
        if (progress > fpsInterval) { 
            console.log("in")
            startAnimating(12); 
        }
        window.requestAnimationFrame(loop);
    }
    window.requestAnimationFrame(loop);
}
// fps控制
function startAnimating(fps) {
    fpsInterval = 1000 / fps;
    preTimestamp = Date.now();
    startTime = preTimestamp;
}
```

