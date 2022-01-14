https://www.youtube.com/watch?v=HQNl3Ff2Lpo&list=PLPV2KyIb3jR4KLGCCAciWQ5qHudKtYeP7&index=6

[ScriptableObject](https://www.youtube.com/watch?v=aPXvoWVabPY&list=RDCMUCYbK_tjZ2OrIZFBvU6CCMiA&index=6)

## ScriptableObject

> 平常的都要用GetComponent<Script>，去取得，但ScriptableObject可以直接創一個物件在資料夾裡!
>
> 這是一個模板，可以存物件，讓每個物件不用再一直重複寫同樣的東西，以下用卡片遊戲作範例
>
> ScriptableObject好處很多，而且又很省空間!

```c#
// Card.cs，製作卡片模板
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

// 可以在Create中新增Card，Default name = New Card
[CreateAssetMenu(fileName = "New Card", menuName = "Card")]
public class Card : ScriptableObject {

	public new string name;  // 讓其他Scriptable也可以用name
	public string description;

	public Sprite artwork;  // 可以丟圖片

	public int manaCost;
	public int attack;
	public int health;

	public void Print ()  // 每個物件都可以呼叫函數
	{
		Debug.Log(name + ": " + description + " The card costs: " + manaCost);
	}

```



```c#
// CardDisplay.cs
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class CardDisplay : MonoBehaviour {

	public Card card; // 直接填入物件(把創建在資料夾的拉進去)

	public Text nameText;
	public Text descriptionText;

	public Image artworkImage;

	public Text manaText;
	public Text attackText;
	public Text healthText;

	// Use this for initialization
	void Start () {
		nameText.text = card.name;
		descriptionText.text = card.description;

		artworkImage.sprite = card.artwork;

		manaText.text = card.manaCost.ToString();
		attackText.text = card.attack.ToString();
		healthText.text = card.health.ToString();
	}
	
}
```








```c#
using UnityEngine;

/* The base item class. All items should derive from this. */
// 可以在專案裡面直接按右鍵產生一個item
[CreateAssetMenu(fileName = "New Item", menuName = "Inventory/Item")]
public class Item : ScriptableObject {

	public new string name = "New Item";// Name of the item，讓其他Scriptable也可以用name
	public Sprite icon = null;				// Item icon
	public bool isDefaultItem = false;      // Is the item default wear?

	// Called when the item is pressed in the inventory
	public virtual void Use ()  // 可以讓子物件Equitment使用override
	{
		// Use the item
		// Something might happen

		Debug.Log("Using " + name);
	}

	public void RemoveFromInventory ()
	{
		Inventory.instance.Remove(this);
	}
	
}
```

以下功能都需要繼承才能用

override 要 父物件的函數是 virtual 才能做使用

new是覆蓋(會有兩個(多一個))，override是修改(還是一個)





這裡使用virtual是因為不同物品使用會有不同功能!!
