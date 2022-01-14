## 取消物理條件

```c#
// 取消碰撞
Physics.IgnoreCollision(gameObject.GetComponent<Collider>(), col.transform.GetComponent<Collider>());
```



## 偵測碰撞

> 偵測球的半徑裡面有沒有東西 Physics.OverlapSphere(Vector3 origin, float radius, LayerMask Detect)
>
> 如果是要指定方向就用Physics.SphereCast(Ray ray, float radius, float max_distance, LayerMask Detect)
>
> 要拿到撞到物件的hitinfo 就要用Physics.SphereCastAll用法跟上面一樣 只不過回傳是RaycastHit[]

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DialogueTrigger : MonoBehaviour
{
    public LayerMask WhatToDetect;

    void Update()
    {
        												 // 也可以用int 層數(有特殊寫法)
        Collider[] items = Physics.OverlapSphere(transform.position, 10f, WhatToDetect);
        // Ray ray = new Ray(transform.position, transform.forward);
        // bool ishit = Physics.SphereCast(ray, 10f, 10f, WhatToDetect)
        
        // RaycastHit hitinfo = Physics.SphereCastAll(ray, 10f, 10f, WhatToDetect)
        if (items.Length != 0 )
        {
			Debug.Log("in");
        }
    }
}
```







## DrawGizmo除錯

```c#
private void OnDrawGizmos() // 繼承MonoBehaviour下才可以用，可以畫出物理線條
{
    Gizmos.color = Color.red;
    Gizmos.DrawLine(transform.position, transform.position + transform.forward * 3);
}
```

