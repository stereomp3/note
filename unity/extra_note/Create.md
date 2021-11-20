# 創建物件



## 創造多個物件

```c#
// 使用instantiate函式可以叫出多個物件
public GameObject[] echo;

void Update(){
    int rand = Random.Range(0, echo.Lenth);
    GameObject instance = (GameObject)Instantiate(echo[rand], transform.position, Quaternion.identity);
}
```







## 創建在子物件裡面

```C
public GameObject player;
    public GameObject head; 
    public GameObject body;
    public GameObject foot;
    // Start is called before the first frame update
    void Start()
    {
        // 可以讓物件在場景中尋找
        head = GameObject.Find("assets_0");
        var position = player.transform.position;
        var _head = Instantiate(head, new Vector3(position.x, position.y+1.2f), Quaternion.Euler(0, 0, 0));
        var _body = Instantiate(body, new Vector3(position.x, position.y), Quaternion.Euler(0, 0, 0));
        var _foot = Instantiate(foot, new Vector3(position.x, position.y-1.2f), Quaternion.Euler(0, 0, 0));
        
        // 把物件放到主物件的字物件
        _head.transform.parent = player.transform;
        _body.transform.parent = player.transform;
        _foot.transform.parent = player.transform;
    }
```



## 呼叫子物件

> [Unity C# 取得父子物件](https://cindyalex.pixnet.net/blog/post/143734467-unity-c%23-%E5%8F%96%E5%BE%97%E7%88%B6%E5%AD%90%E7%89%A9%E4%BB%B6)

```
→  1. 取得父物件

     gameObject.transform.parent.gameObject;

 

→  2. 取得子物件

     gameObject.transform.GetChild(int index).gameObject;

     int index : 數字，放入索引值，代表取第幾個子物件，第一個索引值為0。

      e.g.     gameObject.transform.GetChild(0).gameObject;

 

    ● 取得子物件數量

    gameObject.transform.childCount;

    e.g. int Obj_childCount;

    Obj_childCount = gameObject.transform.childCount;

 

→  3. XX物件變成子物件

     XX.transform.parent = gameObject.transform;

 

→  4. XX物件變成父物件

     gameObject.transform.parent =XX.transform;

 

→  5. 子物件脫離父物件

     gameOject.transform.parent = null;
```



## 毀掉子物件

```

foreach (Transform child in head.transform)
{
	GameObject.Destroy(child.gameObject);
}
```







