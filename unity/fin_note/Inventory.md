參考影片: https://www.youtube.com/watch?v=w6_fetj9PIw&list=PLPV2KyIb3jR4KLGCCAciWQ5qHudKtYeP7&index=6

## Inventory UI設計

* create UI panel object inventory
  * 先使用UI的Panel創造主要區塊，在編輯的時候可以先切換成2D模式再按f去對準他
* create background
  * 在penal裡面再建創一個penal，用來當作背景板，去除掉父物件的image屬性
  * 把下層的penal影像調整成想要的圖(2D sprite)，這裡有個問題，拉動penal圖形會跑掉
  * 對下層的penal做調整，到sprite editor，使用裡面的border，縮小可變動範圍，讓邊框不會被蓋掉
  * 然後把image的模式從simple調成sliced
* inventory slot
  * 一樣需要做上面penal的sprite edit 和 image to sliced，如果圖片變怪怪的可以調整Pixels Per Unit
  * 在最下面的penal下面再加一個penal當作裡面的item
  * 在這格penal 裡面再創建一個image當作物品圖示icon
  * 在這一個penal加上button然後把底下選項navigation關掉 (no use controller)
  * 創建一個空父物件，叫做inventory slot，這層叫做ItemButton，再創建一個image叫做RemoveButton
  * 一樣在RemoveButton加入button然後navigation關掉
  * 把inventory slot 變成perfab，然後創建多個
* modify background
  * 在背景這層，加入Grid Layout Group，可以直接把下面inventory slot物件排列
* modify inventory slot
  * 把ItemButton的image關掉，圖片設成none
  * 把RemoveButton裡面的button屬性interactable關掉，把disable color變全透明
  * 把prefeb apply，完成!!









## code

> Inventory.cs:  處理Inventory邏輯，增加物品，刪除物品，物品空間，物品串列
>
> delegate invoke https://dotblogs.com.tw/atowngit/2009/12/07/12311

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Inventory : MonoBehaviour {

	#region Singleton // 這個就像是 /**/ 配合下面的 #endregion
        
	// 宣告靜態，讓這個只會有一個，當其他script要使用時，只需要Inventory.instance就好了
	public static Inventory instance;  

	void Awake ()
	{
		if (instance != null)
		{
			Debug.LogWarning("More than one instance of Inventory found!");
			return;
		}

		instance = this;
	}

	#endregion

	// Callback which is triggered when
	// an item gets added/removed. 
	// 使用 delegate invoke() 會呼叫onItemChangedCallback清單裡面的函數 
    // InventoryUI 一開始就有加入UpdateUI() // 呼叫 InventorySlot.AddItem(inventory.items)
	public delegate void OnItemChanged();
	public OnItemChanged onItemChangedCallback;

	public int space = 20;	// Amount of slots in inventory

	// Current list of items in inventory
	public List<Item> items = new List<Item>();

	// Add a new item. If there is enough room we
	// return true. Else we return false.
	public bool Add (Item item)
	{
		// Don't do anything if it's a default item
		if (!item.isDefaultItem)
		{
			// Check if out of space
			if (items.Count >= space)
			{
				Debug.Log("Not enough room.");
				return false;
			}

			items.Add(item);	// Add item to list

			// Trigger callback，呼叫onItemChangedCallback清單裡面的函數，下面的InventoryUI在Start() 時就加入UpdateUI()了，所以會呼叫，UpdateUI()函數
			if (onItemChangedCallback != null)
				onItemChangedCallback.Invoke();
		}

		return true;
	}

	// Remove an item
	public void Remove (Item item)
	{
		items.Remove(item);		// Remove item from list

		// Trigger callback
		if (onItemChangedCallback != null)
			onItemChangedCallback.Invoke();
	}

}
```



> InventoryUI.cs: 在跟物件互動時，會顯示在UI上面(利用UpdateUI()觸發InventorySlot)

```c#
using UnityEngine;

/* This object updates the inventory UI. */

public class InventoryUI : MonoBehaviour {

	public Transform itemsParent;	// The parent object of all the items//inventory_back
	public GameObject inventoryUI;	// The entire UI // 用按鍵控制Inventory是否顯示

	Inventory inventory;	// Our current inventory

	InventorySlot[] slots;	// List of all the slots

	void Start () {
		inventory = Inventory.instance; // 取得Inventory物件
        // 把UpdateUI加入清單
		inventory.onItemChangedCallback += UpdateUI;	// Subscribe to the onItemChanged callback 

		// Populate our slots array
		slots = itemsParent.GetComponentsInChildren<InventorySlot>();
	}
	
	void Update () {
		// Check to see if we should open/close the inventory
		if (Input.GetButtonDown("Inventory"))
		{
			inventoryUI.SetActive(!inventoryUI.activeSelf);
		}
	}

	// Update the inventory UI by:
	//		- Adding items
	//		- Clearing empty slots
	// This is called using a delegate on the Inventory.
	void UpdateUI ()
	{
		// Loop through all the slots
		for (int i = 0; i < slots.Length; i++)
		{
			if (i < inventory.items.Count)	// If there is an item to add
			{	// 按照順序加入
				slots[i].AddItem(inventory.items[i]);	// Add it
			} else
			{
				// Otherwise clear the slot
				slots[i].ClearSlot();
			}
		}
	}
}
```



>InventorySlot.cs: 增加移除UI上面的圖片和按鈕，透過 InventoryUI的UpdateUI() 觸發

```c#
using UnityEngine;
using UnityEngine.UI;

/* Sits on all InventorySlots. */

public class InventorySlot : MonoBehaviour {

	public Image icon;			// Reference to the Icon image
	public Button removeButton;	// Reference to the remove button

	Item item;  // Current item in the slot

	// 加入拿到的Item後放到 Image icon 並把 Button removeButton 打開，這裡是放入圖片和顯示
	public void AddItem (Item newItem)
	{
		item = newItem;

		icon.sprite = item.icon;
		icon.enabled = true;
		removeButton.interactable = true;
	}

	// Clear the slot
	public void ClearSlot ()
	{
		item = null;

		icon.sprite = null;
		icon.enabled = false;
		removeButton.interactable = false;
	}

	// Called when the remove button is pressed
	public void OnRemoveButton ()
	{
		Inventory.instance.Remove(item);
	}

	// Called when the item is pressed
	public void UseItem ()
	{
		if (item != null)
		{
			item.Use();
		}
	}

}
```





> 利用下面函數觸發物件加入

```c#
public Item item;

void PickUp ()
{
    Debug.Log("Picking up " + item.name);
    /* 加入物件到Inventory，這時會觸發裡面的
    public delegate void OnItemChanged();
	public OnItemChanged onItemChangedCallback;
	造成 InventoryUI 的 UpdateUI 觸發， 把 InventorySlot的圖示一一顯示*/
    bool wasPickedUp = Inventory.instance.Add(item);	

    // If successfully picked up
    if (wasPickedUp)
        Destroy(gameObject);	// Destroy item from scene
}

```

