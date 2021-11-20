# 2D game

2D和3D其實都差不多

程式要賦予的物件就叫gameObject(gameObject.transform好像也可以不加直接用transform)

bool atk = Input.GetButton("Fire1"); // 取得滑鼠

Input.GetKeyDown()  // 取得鍵盤

Instantiate(item, gameObject.transform.position, gameObject.transform.rotation)   // 創造物件

Destroy(gameObject); // 銷毀物件

Quaternion.Euler(new Vector3(x, y,z)) // 可以旋轉物件



* unity 2D 的碰撞 -->
* collision(造成物理碰撞) --> collision
* trigger(沒有物理碰撞) --> enter stay exit
* 會動的物件最好都加rigbody
* 兩個物件碰撞只要寫在一個就可以觸發(要有rigbody) // void OnCollisionEnter2D(Collision2Dcol){}
* Getcomponent<自己物件的東西>.物件
* 屬性/ 過濾模式(filter mode): point，壓縮(compassion): none

