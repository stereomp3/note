使用套件: https://assetstore.unity.com/packages/tools/input-management/joystick-pack-107631

參考影片: https://www.youtube.com/watch?v=bp2PiFC9sSs



## Touch

> 可以使用點擊，讓腳色移動到螢幕位置

```c#
public class MoveByTouch: MonoBehaviour{

	void Update()
	{
		if(Input.touchCount > 0)
		{
			Touch touch = Input.GetTouch(0);
			Vector3 touchPosition = Camera.main.ScreenToWorldPoint(touch, position);
			// touchPosition.z = 0f; // 如果是 2D 才要加上這個 
			transform.position = touchPosition;
		}
        
        // 偵測多個觸控，使用Debug畫出線條
        for(int i = 0; i < Input.touchCount; i++)
        {
            Vector3 touchPosition = Camera.main.ScreenToWorldPoint(Input.touches[i], position);
          	Debug.DrawLine(Vector3.zero, touchPosition, Color.red);   
        }
	}
}
```



> 使用虛擬搖桿，用法很簡單，只要改改就好

```c#
public Joystick joustick;

void Update()
{
    // 可以用if判斷，讓他大於某個值的時候，horizontalMove = moveSpeed;
    horizontalMove = joystick.Horizontal; // 介於 1 ~ -1，會根據距離中心的遠近調整值
    verticalMove = joystick.Vertical;
}
```

