

## 製作瞄準

> line (renderer)

```c#
使用effect/Line 製作

public LineRenderer LineRenderer; // 呼叫線

void Start()
{
    // 調整線的圖層
    LineRenderer.sortingOrder = 1;
    // 線加上材質(才可以用下面的顏色)
    LineRenderer.material = new Material(Shader.Find("Sprites/Default"));
    // 調整線的顏色
    LineRenderer.material.color = new Color(255, 0, 0, 1);
}


// 可以用兩個script，一個是生成(裝在需要線的物件)，一個是操作和毀滅(裝在line)
## 生成
    
LineRenderer LineRenderer;
GameObject head;

void Start()
{
    // 從prefabs裡面拿取物件
    LineRenderer = Resources.Load<LineRenderer>("Prefabs/Effect/Line");
    head = GameObject.Find("header_" + init_data_button.HeaderIndex.ToString() + "(Clone)");
}


void Update()
{
    if (Input.GetKeyDown(KeyCode.Space))
    {
        // 指定物件在哪裡生成
        var lineRenderer = Instantiate(LineRenderer, new Vector3(head.transform.position.x, head.transform.position.y), Quaternion.identity);
        lineRenderer.sortingOrder = 1;
        lineRenderer.material = new Material(Shader.Find("Sprites/Default"));
        lineRenderer.material.color = new Color(255, 0, 0, 1);
    }
}


## 毀滅
    
GameObject head;
float life_span = 0;

void Start()
{
    head = GameObject.Find("header_" + init_data_button.HeaderIndex.ToString() + "(Clone)");
    transform.parent = head.transform;
}

void Update()
{
    Debug.Log(transform.position);
    //transform.position += head.transform.position;
    life_span += Time.deltaTime;
    if (life_span >= 3)
    {
        Destroy(gameObject);
        life_span = 0;
    }
}

```



## 尾線特效

> [trail](https://www.youtube.com/watch?v=_TcEfIXpmRI)

```c#
// 可以讓滑鼠消失，變成尾線
void Start()
{
	Cursor.visible = false;
}

void Update()
{
    Vector2 pos = Camera.main.ScreenToWorldPoint(Input.mousePosition);
    transform.position = pos;
}
```

> 使用script

```C#
// 可以讓物件隨時間改變大小，或直接random物件大小
private float timeBtwSpawns = 0;
public float startTimeBtwSpawns = 0.5f;

public GameObject echo;

void Update()
{
    if(timeBtwSpawns <= 0)
    {
    	GameObject instance = (GameObject)Instantiate(echo, transform.position, Quaternion.identity);
        //      8f是消失時間
    	Destroy(instance, 8f);
    	timeBtwSpawns = startTimeBtwSpawns;
    }
    else
    {
    	timeBtwSpawns -= Time.deltaTime;
    }
}
```

