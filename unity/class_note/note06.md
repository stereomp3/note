Game2D configaration 是看開始選項(預設按鈕、視窗大小......)

```c#
void OnCollisionEnter2D(Collision2D col)
  {
        Debug.Log(RockerController.hp);
        Destroy(gameObject);  // 物件撞到就損毀
        
        // 不能寫，會讀取不到 if (col.gameObject == player)
        if (col.gameObject.name == "plane")  // 這個是撞到的對象
        {
            RockerController.hp -= 1;
            Debug.Log(RockerController.hp);
            if(RockerController.hp == 0)
            {
                Destroy(col.gameObject);
            }
        }
  }
```

> 取消碰撞

```c#
GameObject myMissile = Instantiate(item,    // instantiate創造物件會回傳物件的值
new Vector3(gameObject.transform.position.x, 
gameObject.transform.position.y + 0.65f, 0), 
Quaternion.Euler(new Vector3(0, 0, 0)));
            
						// GetComponent是一種泛型，後面加上類型，注意! 他是函式
Physics2D.IgnoreCollision(gameObject.GetComponent<Collider2D>(), myMissile.GetComponent<Collider2D>());

// 其實transform 是用這種方式取得，不過因為太常用所以unity讓他可以直接呼叫
Transform transform = GameObject.Getcomponent<Transforms>()
   
transform
```







* 如果把isTrigger(是觸發器)打開，就不會觸發 onCollilsionEnter2D(Collision2D col)

```
void OnTriggerEnter2D(Collider2D col)
```







>  tag(標籤)，創建完prefab(預製物件)後，在標籤處命名，可以像是name一樣操作，比較方便

```
void OnTriggerEnter2D(Collision2D col)
  {
  		// ...
        if (col.gameObject.tag == "plane")  // 這個是撞到的對象
        {
            //...
        }
  }
```



## else

```
object.enabled = false // 可以讓物件看不到

如果要讓背景選轉
1. 使用材質把背景圖放進去


2. 使用相機做效果  //比較複雜
```





