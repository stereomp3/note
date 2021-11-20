## 碰撞介紹

1. 要產生碰撞必須為遊戲對象添加剛體（Rigidbody）和碰撞器，剛體可以讓物體在物理影響下運動。碰撞體是物理組件的一類，它要與剛體一起添加到遊戲對像上才能觸發碰撞。如果兩個剛體相互撞在一起，除非兩個對像有碰撞體時物理引擎才會計算碰撞，在物理模擬中，沒有碰撞體的剛體會彼此相互穿過。

2. 發生碰撞條件:

   兩個物體都必須帶有碰撞器(Collider)，其中一個物體還必須帶有Rigidbody剛體。
   在unity3d中，能檢測碰撞發生的方式有兩種，一種是利用碰撞器，另一種則是利用觸發器。



## 取消物理條件

```c#
// 取消碰撞
 Physics2D.IgnoreCollision(gameObject.GetComponent<Collider2D>(), myMissile.GetComponent<Collider2D>());
```





## 碰撞函式

```C#
void OnCollisionEnter2D(Collision2D col)
{
	//...
}


void OnTriggerEnter2D(Collider2D col)
{
	//...
}
```



## 激光效果

> 使用射線[Physics2D](https://docs.unity3d.com/ScriptReference/Physics2D.html).Raycast判斷某個方向是否有碰撞體

```
Physics2D.Raycast(Vector2 origin, Vector2 direction, float distance, int layerMask);

1、origin：射線投射的原點
2、direction：射線投射的方向
3、distance：射線的長度
4、layerMask：射線只會投射到layerMask層的碰撞體（注意此int參數的寫法：1 << 層數）
可以只寫1、2就好，不過東西太多可以用4.，把要撞的(敵人)，全都丟到一層去讓撞

RaycastHit2D hitInfo = Physics2D.Raycast(GameObject.transform.position, GameObject.transform.right);  // right是判定他右邊有沒有物件(有collider)
if (hitInfo)
{
	Debug.Log("!!");
}

這個跟角度也有關系，所以要做激光效果要用GameObject.transform.up來判斷
這個判斷不會跟parent撞在一起，好用!!
```

>  **使用[line renderer](https://www.youtube.com/watch?v=wkKsl1Mfp5M)** 要先把layer調到最上層，調整x,y，再把末端頂點調大，讓激光更柔和，勾選使用世界空間，這樣會讓線條的使用更容易

```c#
// 使用上面的代碼加上線條特效!! 和爆炸效果
public Transform firePoint;
public int damage = 40;
public GameObject impactEffect;
public LineRenderer lineRenderer;

void Shoot(){
    //                                     right是判定他右邊有沒有物件(有collider)
    RaycastHit2D hitInfo = Physics2D.Raycast(firePoint.position, firePoint.right);  
    
    if (hitInfo)
    {
        Enemy enemy = hitInfo.transform.GetCompoent<Enemy>();
        if(enemy!=null){
			enemy.TakeDamage(damage);
        }
        
        //        創建爆炸效果     生成位置在擊中的點 
        instantiate(impactEffect, hitInfo.point, Quaternion.identity);
        
        // 生成線段，起始位置(firePoint.position)，末位置(hitInfo.piont) // vector3
        lineRenderer.SetPosition(0, firePoint.position);
        lineRenderer.SetPosition(1, hitInfo.point);
    }
    else{
        // 沒有設到人就射遠遠的
        lineRenderer.SetPosition(0, firePoint.position);
        lineRenderer.SetPosition(1, firePoint.position + firePoint.right * 100)
    }

// 注意，要有空物件判斷右邊有沒有敵人，雷射只是特效(加碰撞)，真正判斷的是空物件(先出來，不加碰撞)
    
    
}
```

> 使用IEnumerator，如果放在update函數裡面，要加上timer做緩衝，不然效果會很差

```C#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LaserModeA : MonoBehaviour
{
    //public LineRenderer bullet;
    public static float ATK = 1.8f;
    public LineRenderer lineRenderer;
    public float moveSpeed = 14f;
    float bufferTime = 0.03f;
    
    // Start is called before the first frame update
    void Start()
    {
        lineRenderer.enabled = false;
    }

    // Update is called once per frame
    void Update()
    {
        bufferTime -= Time.deltaTime;
        if (bufferTime <= 0 && HLaserA.timer < 3 && Input.GetKey(InputField.head_input) && init_data_button.HeaderIndex == 0)
        {
            StartCoroutine(shoot());
            bufferTime = 0.03f;
        }
    }
    // 讓unity短暫停止，並讓物件不會一直生，原理很複雜
    IEnumerator shoot()
    {
        
        // 由沒有碰撞的空物件用來偵測，後面出來的線用來碰撞                             // 只有在敵人層才可以打到
        RaycastHit2D hitInfo = Physics2D.Raycast(transform.position, transform.up, 100f, 1 << LayerMask.NameToLayer("enemy"));
        if (hitInfo)
        {
            Enemy enemy = hitInfo.transform.GetComponent<Enemy>();
            if(!Boss01Mode.EnermyInvincible) enemy.TakeDamage(ATK);
            Debug.Log("!!");
            // 生成線段，起始位置(firePoint.position)，末位置(hitInfo.piont) // vector3
            lineRenderer.SetPosition(0, transform.position);
            lineRenderer.SetPosition(1, hitInfo.point);
            Debug.Log("collisionwith:" + hitInfo.collider.name);

        }
        else
        {
            // 沒有射到人就射遠遠的
            lineRenderer.SetPosition(0, transform.position);
            lineRenderer.SetPosition(1, transform.position + transform.up * 100);
        }

        lineRenderer.enabled = true;

        yield return new WaitForSeconds(0.02f);

        lineRenderer.enabled = false;
    }


}
```



## 改變mask

```C#
LayerMask mask;
mask = LayerMask.NameToLayer("Player01");
RaycastHit2D hitInfo = Physics2D.Raycast(transform.position, transform.up, 100f, 1 << mask);
```









## 速度

```C#
使用Rigidbody2D

public float speed = 20f;
public Rigidbody2D rb;

void start(){
	rb.velocity = transform.right * speed
}
```

