參考資料: [OnMouseOver()](https://docs.unity3d.com/2019.1/Documentation/ScriptReference/MonoBehaviour.OnMouseOver.html)、[我要和天一樣高！！！（Unity 2D手機小遊戲開發日誌）](https://ithelp.ithome.com.tw/users/20103149/ironman/1003)

# UI



## Button

>  創建之後直接使用，如果已經有圖片，下面的text可以刪掉

```c#
// 在script裡面新建public func，拉到要給的button，之後在onclick那邊拉入自己，選擇func ButtonOnclick()

public void ButtonOnclick()
{
	Debug.Log("click");
}
```



## 遊戲畫面暫停

> `Time.timeScale`可以調整遊戲引擎中時間運行的速度比例。任何和時間有關的函數都會受到影響(如`Update()`、`Coroutine`、`Invoke()`等等)。`Time.timeScale`為`1 f`時，時間以正常速度運行。

```c#
// 在script裡面加入
void OnEnable()
{
	//時間暫停
    Time.timeScale = 0f;
}
    
void OnDisable()
{
	//時間以正常速度運行
	Time.timeScale = 1f;
}
```



## Scene

```c#
// 開始場景
SceneManager.LoadScene("GameScene");
```



## 動態切換圖片

```C#
void Start()
{
    // 切換物件
    gameObject.GetComponent<SpriteRenderer>().sprite = (Sprite)Resources.Load<Sprite>("body_1");
    
    // 切換圖片(UI)，圖片要是sprite、要放在Resources資料夾裡面，限定在start或awake裡面叫
    gameObject.GetComponent<Image>().sprite = Resources.Load<Sprite>("body_0"); 
    
    // 如果是要用spriteSheet載入，就要用LoadAll
    Sprite[] MySprite = Resources.LoadAll<Sprite>("body");
    然後用MySprite[0]決定位置
}
```



## 製作血條

> 用scrollbar，再把多出來的尾巴蓋掉

```C#
public Scrollbar Header;

// 總長度是1
Header.size -= 0.1f
```

> 上面的方法很笨，可以用更好的方式寫，參考網址: https://www.youtube.com/watch?v=BLfNP4Sc_iA

```
利用一個空物件當作healthBar，再用三個子物件，一個當border，一個當fill(血條)，一個當小圖示，把空物件裡面加上Slider屬性，把fill拉到填充矩形裡面，再把border、fill調成stretch，小圖示用來放在左邊，之後只要調整裡面的value就可以了!!
```





> 可以用Tostring()控制顯示小數點下第幾位 --> `testFloat.ToString("0.00")` 顯示小數點下第二位



## Background loop

> 可以把主攝影機的清除標誌調成僅深度，再把深度調成0，這樣可以看到所有攝影機
>
> 創建一個新的攝影機負責無線背景，要把投影變正交(orthographic)，在2D通常都是正交，3D才是透視
>
> 上面這些可以不用做，用一個相機比較簡單

* 創建材質，把default改成Unlit/Texture
* 把想要的轉成會動背景的圖丟進去(圖片拼接方式要改成repeat)
* 把圖和材質都放到物件裡面
* 就可以開始轉了!!

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ScrollScript : MonoBehaviour
{
    public float speed = 0;
    void Update()
    {
        GetComponent<Image>().material.mainTextureOffset = new Vector2(Time.time * 0.1f, 0);
    }
}
```



* 材質也可以用在角色死亡，讓角色上的材質慢慢不見，就會有死亡效果!

```C#
Material material
public float fade = 1f;

void Start(){
	material = GetComponent<SpriteRenderer>().material;
}


void Update(){
    if(isDissolving)
    {
        fade -= time.delatime
        if(fade <= 0f)
        {
            fade = 0f;
            isDissolving = false;
        }
        material.SetFloat("_Fade", fade)
    }
}

```





