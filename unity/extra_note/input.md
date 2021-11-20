## keyboard Input

```c#
Input.GetKeyUp("space")
Input.GetKeyUp("left")
Input.GetKeyUp("j") // 要是小寫
Input.GetKeyDown(KeyCode.Space) // 按下
Input.GetKey(KeyCode.LeftArrow)
Input.GetKey(KeyCode.Keypad0)
Input.GetKey(KeyCode.Space)
Input.GetKey(KeyCode.A)
    .....
可以抓取布林值，按下去觸發(連續)
    
Input.GetAxis("Vertical")  // 取得上下操控 預設 上下 WS
Input.GetAxis("Horizontal")// 取得左右操控 預設 左右 AD
Input.GetAxis("Mouse X")   // 取得滑鼠左鍵
Input.GetAxis("Mouse Y")   // 取得滑鼠右鍵
```



## Input Field

> 取得玩家輸入，可以讓玩家選擇遊戲按鍵，遊戲暱稱

```c#
public TMP_InputField inputField;
public string Head_input;
    
void Start()
{
    inputField.textComponent.alignment = TextAlignmentOptions.Midline;  // 把文字置中
}
 
// 讓輸入卡在1個字元
public void InputName()
{ 
    if (inputField.text.Length <= 1) Head_input = inputField.text.ToLower();

    else inputField.text = Head_input + "";
    Debug.Log(Head_input);
}
```





## input STR

> 參考: https://answers.unity.com/questions/762073/c-list-of-string-name-for-inputgetkeystring-name.html

```
 backspace
 delete
 tab
 clear
 return
 pause
 escape
 space
 [0]  pad num  KeyCode.Keypad0
 [1]
 [2]
 [3]
 [4]
 [5]
 [6]
 [7]
 [8]
 [9]
 [.]
 [/]
 [*]
 [-]
 [+]
 equals
 enter
 up
 down
 right
 left
 insert
 home
 end
 page up
 page down
 f1
 f2
 f3
 f4
 f5
 f6
 f7
 f8
 f9
 f10
 f11
 f12
 f13
 f14
 f15
 0    top num  KeyCode.Alpha0
 1
 2
 3
 4
 5
 6
 7
 8
 9
 -
 =
 !
 @
 #
 $
 %
 ^
 &
 *
 (
 )
 _
 +
 [
 ]
 `
 {
 }
 ~
 ;
 '
 \
 :
 "
 |
 ,
 .
 /
 <
 >
 ?
 a
 b
 c
 d
 e
 f
 g
 h
 i
 j
 k
 l
 m
 n
 o
 p
 q
 r
 s
 t
 u
 v
 w
 x
 y
 z
 numlock
 caps lock
 scroll lock
 right shift
 left shift
 right ctrl
 left ctrl
 right alt
 left alt
 right cmd
 left cmd
 right super
 left super
 alt gr
```

