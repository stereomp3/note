`transform.LookAt(plant.transform);` 

* 可以一直對者那個物體方向(Vector3)，可以用在camera

`Quaternion.Slerp(Vector3 a, Vector3 b ,t )`

* a(Vector3) 在t時間內轉向b(Vector3)物體，通常用在Rigibody.MoveRotation裡面，或是給rotation

`Quaternion.LookRotation(Vector3 forward, Vector3 upwards = Vector3.up);`

* 第一個參數向量通常以目標位置-自身位置(通常是他要轉向哪裡)為主，會在象限中慢慢選轉慢慢靠近目標向量，第二個它的前方是指向哪裡

```c#
Vector3 targetDir = (transform.position - plant.transform.position).normalized;
Quaternion targetRot = Quaternion.LookRotation(targetDir, transform.up);//讓物件一直是頭向上
transform.rotation = Quaternion.Lerp(transform.rotation, targetRot, Time.deltaTime * 100); // 慢慢選轉
```



`Vector3.SmoothDamp(a, b, ref velocity, t);` 

* 在t時間從a到b位置(Vector3)中間的velocity通常都是Vector.zero

`FindObjectOfType<DialogueManager>().StartDialogue(dialogue);`

* 不創建物件直接觸發裡面的函式

`transform.position = Vector3.MoveTowards(Vector3 obj_pos, Vector3 target_pos, float step);`

* 讓位置跟著玩家走，也可以當作電梯喔



> 可以在別的script使用目標script裡面的function，利用在裡面創建一個靜態的自己

```c#
public static SmoothFollow instance;

void Awake() // 跟Start類似但是Awake就算這個套件被enable還是會執行
{
	instance = this;
}
```



物件可以設定navigation，詳情可以看[Brackeys的影片](https://www.youtube.com/watch?v=S2mK6KFdv0I&list=PLPV2KyIb3jR4KLGCCAciWQ5qHudKtYeP7&index=3)，物件如果勾選右上角的static就是靜態地圖，可以被用來baking資料，navigation要偵測那個障礙物，那個障礙物就要勾選





https://douduck08.wordpress.com/2016/06/26/usage-of-unity-quaternion/
