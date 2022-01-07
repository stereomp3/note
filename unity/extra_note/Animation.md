> 參考網址: [[Unity] 使用 Animator 來幫角色加上動畫](https://clay-atlas.com/blog/2021/07/03/unity-cn-player-animator-animation/)



## 準備動畫

1. 導入sprite sheet 之後，使用sprite editor把圖片切割(不會切到原圖)

2. 把角色放到場景裡面，加入Animator(動畫器)
3. 開啟視窗/動畫/動畫  創建動畫(這裡可以創好幾個)，把需要的圖片拉進去(要點擊主要角色才可以創建)





## 製作動畫

* 使用動畫器，裡面有各種動畫的交互，可以用script去操作動畫如何執行
* 把idle 設置為最開始的動畫(set as layer default state)
* 取消有退出時間(Has Exit Time)，不取消會執行完動畫才到下一個，會卡卡的
* 把所有相關聯的動畫連接起來(左鍵 make translation(建立過渡))
* 在parameters(參數)新增一個Status的int變數(Script只需要更改Status就可以控制動畫)
* 在連接處新增condition，讓Status可以在切換動作時做改變(equals)





* 動畫變數bool可以true過去false回來，trigger則是過去了會自己回來



## Script

```c#
using UnityEngine;

public class playercontroller : MonoBehaviour
{
    // Init
    public float moveSpeed = 0.2f;

    // Properties
    private Animator myAnimator;
    private SpriteRenderer mySpriteRenderer;

    // Start is called before the first frame update
    void Start()
    {
        // Animator，取得物件的動畫器
        myAnimator = GetComponent<Animator>(); 

        // Sprite，取得物件的SpriteRenderer，這裡用來控制圖片翻轉
        mySpriteRenderer = GetComponent<SpriteRenderer>();
    }

    // Update is called once per frame
    void Update()
    {
        // Movement
        if (Input.GetKey(KeyCode.LeftArrow))
        {
            // 不翻轉
            mySpriteRenderer.flipX = false;
            // 設置動畫器裡面的變數，這裡對應到上面 make translation設定的condition
            myAnimator.SetInteger("Status", 1);
            transform.position -= new Vector3(moveSpeed * Time.deltaTime, 0);
        }
        else if (Input.GetKey(KeyCode.RightArrow))
        {
            mySpriteRenderer.flipX = true;
            myAnimator.SetInteger("Status", 1);
            transform.position += new Vector3(moveSpeed * Time.deltaTime, 0);
        }
        else
        {
            myAnimator.SetInteger("Status", 0);
        }
    }
}

```



* 可以在每個動畫裡面加入script，讓在那個狀態的物體可以執行那個script，在寫boss很好用!!

## 建立物件動畫

> 使用Animation動畫製作

* 點選物件後按下windows/animation
* 選中要調整的物件屬性
* 在關鍵點上面增加事件(長方形)，並設置set...
* 之後就可以看到物件改變了!!
* 也可以對物件屬性作改變，然後加上關鍵禎
* 動畫要在那一個地方選擇左上的錄製按鈕!!!



## 動畫事件、script

> 參考: https://www.youtube.com/watch?v=AD4JIXQDw0s&list=PLPV2KyIb3jR6TFcFuzI2bB7TMNIIBpKMQ&index=10

```C#
// 動畫器的script基本上只會用到前三個

public float speed = 2.5f;

Transform player;
Rigidbody2D rb;

bool Atk;

// OnStateEnter is called when a transition starts and the state machine starts to evaluate this state  // 這個就像 start()
override public void OnStateEnter(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
{
   player = GameObject.FindGameObjectWithTag("Player").transform;  // 找到玩家位置
   rb = animator.GetCompoent<Rigidbody2D>()  // 要取到物件就要用animator
}

// OnStateUpdate is called on each Update frame between OnStateEnter and OnStateExit callbacks   // 這個就像 update()
override public void OnStateUpdate(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
{
   if(Atk)
   {
       animator.SetTrigger("Attack"); // 觸發trigger ，可能會多次觸發，所以要在下面函式加上一行
   }
}

// OnStateExit is called when a transition ends and the state machine finishes evaluating this state
override public void OnStateExit(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
{
   animator.ResetTrigger("Attack")
}
```



```
在外部改變animator變數
GetCompoent<Animator>().SetBool("IsEnraged", true);
```



> 動畫器可以在想要的地方加上那個物件有的script，像是boss攻擊的時候，加入public void Attack()
