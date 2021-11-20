>  參考資料: [Event](https://docs.unity3d.com/2019.1/Documentation/ScriptReference/Events.UnityEvent.AddListener.html)

##  改變物件角度

```c#
transform.Rotate (new Vector3 (0f, 0f, 2f));  // 圖片翻轉 用Z 控制讓他不會轉到圖片本身加上去
transform.rotation = Quaternion.Euler (0f, 0f, 2f);  // 讓他變這個角度

transform.rotation.z // get 角度


Quaternion quate = Quaternion.identity;
quate.eulerAngles = new Vector3(45, 0, 0); // 表示設置x軸方向旋轉了45度
gameObj.transform.rotation = quate;
```



##  新增事件

```c#
// 新增事件，需要 using UnityEngine.Events;
UnityEvent m_MyEvent = new UnityEvent();

    void Start()
    {
        // 只要有input就觸發
        m_MyEvent.AddListener(MyAction);
    }

    void Update()
    {
        // Press Q to close the Listener
        if (Input.GetKeyDown("q") && m_MyEvent != null)
        {
            Debug.Log("Quitting");
            m_MyEvent.RemoveListener(MyAction);

            #if UNITY_EDITOR
            UnityEditor.EditorApplication.isPlaying = false;
            #endif
			// 退出程式
            Application.Quit();
        }

        //Press any other key to begin the action if the Event exists
        if (Input.anyKeyDown && m_MyEvent != null)
        {
            //Begin the action
            m_MyEvent.Invoke();
        }
    }

    void MyAction()
    {
        //Output message to the console
        Debug.Log("Do Stuff");
    }



// 可以在加入滑鼠hover事件，物體要有Collider!!
void OnMouseOver()
{
    //If your mouse hovers over the GameObject with the script attached, output this message
    Debug.Log("Mouse is over GameObject.");
}

void OnMouseExit()
{
    //The mouse is no longer hovering over the GameObject so output this message each frame
    Debug.Log("Mouse is no longer on GameObject.");
}

//Detect if the Cursor starts to pass over the GameObject
public void OnPointerEnter(PointerEventData pointerEventData)
{
    //Output to console the GameObject's name and the following message
    Debug.Log("Cursor Entering " + name + " GameObject");
}

//Detect when Cursor leaves the GameObject
public void OnPointerExit(PointerEventData pointerEventData)
{
    //Output the following message with the GameObject's name
    Debug.Log("Cursor Exiting " + name + " GameObject");
}
```



## 字典

> [C# Dictionary的用法](http://code2study.blogspot.com/2012/01/c-dictionary.html)

```c#
Dictionary<string, string> MyDic = new Dictionary<string, string>( );

// 建立字典
private void CreateDictionary( )
{
    MyDic.Add( "Name", "Jack" );
    MyDic.Add( "Blog", "Jack’s Blog" );
    MyDic.Add( "Group", "KTV Group" );
}

// 查字典
private String FindInDictionary( String FindMe )
{
    if ( true == ( MyDic.ContainsKey( FindMe ) ) )
    {
        return MyDic[ FindMe ];
    }
    else
    {
        return "Not Found";
    }
}

// 巡整個字典
private void ShowAllInDictionary( )
{
    foreach ( var OneItem in MyDic )
    {
        Console.WriteLine( "Key = " + OneItem.Key + ", Value = " + OneItem.Value );
    }
}


```



## 改變物體大小

> 使用[Scale](https://clay-atlas.com/blog/2021/07/08/unity-cn-game-object-scale-adjust/)

```
// get
vector3 objectScale = transform.localScale

// set
transform.localScale = new Vector3(objectScale. x*2,  objectScale.y*2, objectScale.z*2);


// 可以建立空物件，調整他和要伸展一邊的物件(到他的一半)，這樣調整空物件(大小)，就可以讓他的小孩伸縮一邊
```



## 改變物體顏色

```C#
private SpriteRenderer spriteRender;

// 直接引響用這個script的物體，如果script本身有顏色，就用疊色
// spriteRender.color = new Color32(255, 255, 255, 255) 這個對原本圖片不影響 (白)
// new Color(R,G,B,A)不行影響sprite顏色
spriteRender = GetComponent<SpriteRenderer>();
spriteRender.color = new Color32(100,100,100,255) // new Color(R,G,B,A) A -> 0~1
```



## Script停用、加入

```C#
// 加入物件
GameObject body;

// 找到物件(name)
body = GameObject.Find("body_" + init_data_button.BodyIndex.ToString() + "(Clone)");

// 把物體的script停用
body.GetComponent<BMuti>().enabled = false;

// 動態加入物體
GameObject bullet;
bullet = Resources.Load("Prefabs/Bullet/muti") as GameObject;

// 動態加入Script
body.AddComponent<Booster>();

// 動態加入主攝影機
public Camera cam;
cam = Camera.main;

// 摧毀script !! 就算用AddComponent也加不回來
Destroy(GetComponent<Enemy01Create>());
```





## 呼叫其他指令函式碼

```
第一種，被呼叫指令碼函式為static型別，呼叫時直接用  指令碼名.函式名()。很不實用……

第二種，GameObject.Find("指令碼所在物體名").SendMessage("函式名");  此種方法可以呼叫public和private型別函式

第三種，GameObject.Find("指令碼所在物體名").GetComponent<指令碼名>().函式名();此種方法只可以呼叫public型別函式

https://www.itread01.com/content/1547794088.html
```



## 動態修改物體標籤

> 參考: https://blog.csdn.net/qq_37875134/article/details/111993466

```C#
gameObject.transform.tag = "Player"; // 標籤存在

// 標籤不存在標籤列
string newtag = "newtag";
if(!UnityEditorInternal.InternalEditorUtility.tags.Contain(newtag))
	UnityEditorInternal.InternalEditorUtility.AddTag = (newtag)
	gameObject.transform.tag = "newtag";

// 用標籤尋找物件
player = GameObject.FindGameObjectsWithTag("Player")[0];
```





