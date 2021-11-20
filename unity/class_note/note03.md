大寫是類，小寫是變數

* Time.Deltatime: 1/fps，每個遊戲都要加，固定每台電腦的速度
  
# transform: 每個元件都有的變數
    屬性:
    1. .Rotate(x,y,z) // 決定旋轉多少
    
    2. .Translate(x,y,z) // 決定怎麼移動
    	Translate(new Vector(x,y,z))
    
    3. .position = new Vector3(x,y,z) // 移動到哪裡
       .position += new Vector3(x,y,z) // 移動
    
    4. .localScale += new Vector3(0.1f * Time.deltaTime, 0, 0)

* Quaternion(x,y,z,w): 是轉置矩陣裡面的四個值，可以圖形變化大小
* transform.rotation = Quaternion.Euler(x,y,z): 才是轉角度 

>  **unity 裡面的小數都是用float，所以寫小數要在後面加上f，或是包float(數字)**

>  **要打印數據在控制台要用 Debug.Log();**

# 製作timers:
	timer += Time.deltaTime; // 把時間累加
	    if(timer>5)
	    {
	        做的事情
	    }

* 輸入增測
   * Input.GetMouseButtonDown
   * Input.GetMouseButtonUp
   * Input.GetKey(KeyCode.A) 

* 創造物件 
  	* Instantiate(object,position, location)