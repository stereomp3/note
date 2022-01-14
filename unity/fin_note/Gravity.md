使用重力系統  F = GMm/r**2，[參考影片]( https://www.youtube.com/watch?v=Ouu3D_VHx9o&list=PLPV2KyIb3jR5qEyOlJImGFoHcxg9XUQci)



```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Attractor : MonoBehaviour {

	const float G = 667.4f; // 重力常數

	public static List<Attractor> Attractors; 

	public Rigidbody rb;

	void FixedUpdate ()
	{
		foreach (Attractor attractor in Attractors)
		{
			if (attractor != this) // 不會跟自己吸引
				Attract(attractor); // 觸發F = GMm/r**2
		}
	}

	void OnEnable ()
	{
		if (Attractors == null)
			Attractors = new List<Attractor>(); // 如果沒有列表就創建一個

		Attractors.Add(this); 
	}

	void OnDisable ()
	{
		Attractors.Remove(this);
	}

	void Attract (Attractor objToAttract)
	{
		Rigidbody rbToAttract = objToAttract.rb;

		Vector3 direction = rb.position - rbToAttract.position; // 兩個物體位置相減
        // Vector3.magnitude 返回一個浮點數，它是一個表示向量長度的單維值(因此它會丟失方向信息)
        // Vector3.normalized 會反回單位向量，把他標轉化到 1~-1範圍
        // 任何向量先normalized再magnitude 大小都會是 1
		float distance = direction.magnitude; // r

		if (distance == 0f) // 除數不為0
			return;

		float forceMagnitude = G * (rb.mass * rbToAttract.mass) / Mathf.Pow(distance, 2);
		Vector3 force = direction.normalized * forceMagnitude; // GMm/r**2

		rbToAttract.AddForce(force); // F=GMm/r**2
	}

}
```



> 在有引力的狀況下運動，用MovePositon動，參考: https://github.com/Morinethar5/Shrinking-Planet/tree/master/Assets/Scripts

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Controller : MonoBehaviour
{
	public float moveSpeed = 10f;
	public float rotationSpeed = 10f;

	private float rotation, moveDir;
	private Rigidbody rb;

	void Start()
	{
		rb = GetComponent<Rigidbody>();
	}

	void Update()
	{
		rotation = Input.GetAxisRaw("Horizontal"); // 不按是 0 按了左是 -1 按右是 1
		moveDir = Input.GetAxisRaw("Vertical");
	}

	void FixedUpdate()
	{
		rb.MovePosition(rb.position + moveDir * transform.forward * moveSpeed * Time.fixedDeltaTime); // 向前走
		Vector3 yRotation = Vector3.up * rotation * rotationSpeed * Time.fixedDeltaTime; // Time.fixedDeltaTime = 0.02
		Quaternion deltaRotation = Quaternion.Euler(yRotation);
		Quaternion targetRotation = rb.rotation * deltaRotation;
		rb.MoveRotation(Quaternion.Slerp(rb.rotation, targetRotation, 50f * Time.deltaTime)); // (a,b,t) a在t時間內轉向b物體，讓移動滑順
		// transform.Rotate(0f, rotation * rotationSpeed * Time.fixedDeltaTime, 0f, Space.Self);
	}
}
```

