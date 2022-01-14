使用對話系統管理對話，[參考影片]( https://www.youtube.com/watch?v=_nRzoTzeyxU&list=PLPV2KyIb3jR5qEyOlJImGFoHcxg9XUQci&index=2)



> DialogueTrigger.cs 決定是什麼時候觸發對話、觸發與誰的對話

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DialogueTrigger : MonoBehaviour {

	public Dialogue dialogue; // 把下面的Dialogue.cs放入

	public void TriggerDialogue ()
	{
        // 找到script，觸發裡面的函式
		FindObjectOfType<DialogueManager>().StartDialogue(dialogue);
	}

}
```

* `GameObject.FindObjectsOfType<T>()`

  ```c#
  根據元件的類別直接搜尋，如果是Script腳本就直接輸入對應名稱，如果是下面這樣，會找到所有物件
  private GameObject[] obj;
  obj = FindObjectsOfType<GameObject>()
  ```

  





> Dialogue.cs 可以讓管理者創建對話

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

// 序列化，讓資料(位元組流)可以在網路上傳送 // 可以序列化的類需要用這個屬性標記
[System.Serializable]  // 使用自訂一類型數據就要使用，可以直接在script上調整
public class Dialogue {

	public string name;

	[TextArea(3, 10)] // 輸入範圍加大
    // 這裡因為是System.Serializable，所以一開始會要輸入size再填內容，如下圖
	public string[] sentences; 
}
```

![](.\image\dialogue.png)





> DialogueManager.cs 管理主要對話邏輯(控制對話開始、結束、段落)

```c#
using System.Collections;  // 使用Queue
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class DialogueManager : MonoBehaviour {

    // UI
	public Text nameText;  
	public Text dialogueText;

	public Animator animator; // 控制動畫效果(關閉對話、開啟對話)

	private Queue<string> sentences;  // 使用Queue讓對話新增到裡面(enqueue)

	// Use this for initialization
	void Start () {
		sentences = new Queue<string>();
	}

	public void StartDialogue (Dialogue dialogue) // 在DialogueTrigger.cs觸發
	{
		animator.SetBool("IsOpen", true); // 控制UI動畫，開始對話

		nameText.text = dialogue.name; 

		sentences.Clear(); // 把對話先清除

		foreach (string sentence in dialogue.sentences) // 把對話丟到Queue裡面
		{
			sentences.Enqueue(sentence);
		}

		DisplayNextSentence();
	}

	public void DisplayNextSentence ()
	{
		if (sentences.Count == 0) // Queue裡面沒東西就結束對話(到了列隊的末尾)
		{
			EndDialogue();
			return;
		}

		string sentence = sentences.Dequeue(); // 讓第一個句子離開Queue並存入sentence裡面
        // dialogueText.text = sentence; UI顯示，下面可以讓UI逐字顯示
		StopAllCoroutines(); // 確保前一個動畫完成後才執行下一個動畫
		StartCoroutine(TypeSentence(sentence));
	}

	IEnumerator TypeSentence (string sentence)  // 使用這個讓對話有打字效果
	{
		dialogueText.text = "";
        // ToCharArray() 可以讓
		foreach (char letter in sentence.ToCharArray())
		{
			dialogueText.text += letter;
			yield return null; // 可以控制回傳時間，這裡不設置
            // yield return new WaitForSeconds(0.02f);
		}
	}

	void EndDialogue()  // 控制UI動畫，結束對話，在DisplayNextSentence ()呼叫
	{
		animator.SetBool("IsOpen", false);
	}

}
```

