## 類別概念

```c#
// 建立父類
public class TreatureBoxCreater : MonoBehaviour
{
    // 可以讓其他檔案讀取到資料
    // 可以在get set設定private，讓資料變成只在這個類別裡面可以修改
    public int TreatureIndex { get; set; } 
	
    // virtual代表可以被改寫(override)
    public virtual void Die(){}
}

// 使用繼承(建立子類)
public class TreatureBoxMode : TreatureBoxCreater
{
    // 使用子類的東西
    TreatureIndex = 1;
    
    // 使用override，可以改父類
    public override void Die(){}
}

```





## unity兩個向量求夾角

> 參考網站: https://www.itread01.com/content/1512314485.html

```
##成功案例
// 把兩個點的位置差標準化
Vector2 dir = (player.transform.position - transform.position).normalized;

// Mathf.Atan2(dir.y, dir.x) 求兩點弧度
float degree = Mathf.Atan2(dir.y, dir.x) / Mathf.PI * 180;// 根據弧度值，求角度

transform.rotation = Quaternion.Euler(0, 0, degree -90);


unity 由兩個向量求夾角


//////////////////////////////////fail
1. 

float angle = Vector3.Angle (fromVector, toVector); //求出兩向量之間的夾角 

Vector3 normal = Vector3.Cross (fromVector,toVector);//叉乘求出法線向量 

//求法線向量與物體上方向向量點乘，結果為1或-1，修正旋轉方向  
angle *= Mathf.Sign (Vector3.Dot(normal,upVector)); 

// Dot -->拿來求 兩個向量的夾角，例如你想知道 兩個人物是否面對面，或者某人是否在另一個人後面都可以用這個公式來做解決(Dot --> 內積)

2.

//對目標向量進行反向旋轉，得到的新向量與z軸的夾角即為目標向量與當前物體方向的夾角  
Vector3 velocity = Quaternion.Inverse (transform.rotation)*destinationVector; 
     
//返回tan值為x/z的角的弧度，再轉化為度數。 
float angle = Mathf.Atan2 (velocity.x,velocity.z) * Mathf.Rad2Deg; 
 
3.

數學法:已知a,b兩個向量

cosθ=X; (X=(a*b)/(|a|*|b|))


然後求θ=arccosX c#裏是Mathf.Acos(X);



// 三角形
//a**2=b**2+c**2−2bc⋅cosθ --> cosθ = b**2 + c**2 - a**2   / 2ab
```



## 利用正弦值求角度  (fail

> 參考: https://blog.csdn.net/xpj8888/article/details/88362784、https://ithelp.ithome.com.tw/articles/10214418。 

```C#
float sinValue = 0.5 // sin 值0.5
float sinRadianValue = Mathf.Asin(sinValue); // 求弧度值
float sinAngleValue = sinRadianValue / Mathf.PI * 180; // 根據弧度值，求角度

float sinAngleValue = 30 // 角度30
float sinRadianValue = Mathf.PI * sinAngleValue / 180 // 求弧度
float sinValue = Mathf.Sin(sinRadianValue1); // 弧度轉sin

Mathf.Pow(float, float) // 平方
```

