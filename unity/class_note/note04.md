>  Unity fire1 可以讓動作對應到不同的平台操作，如果是用getkey()之類的就只能在電腦

* 在編輯/專案設定/輸入管理器: 可以進入fire1看

* 可以把左側的物件拉入asset資料夾，變成一個字定義的物件，可以把這個object拉入GameObject裡面

  ## input.GetAxis

  ```c#
  Input.GetAxis 裡面的的定義都在編輯/專案設定/輸入管理器裡面，可以設定，讓所以平台適用
  ```

  | Input.GetAxis("Vertical")   | 讓物件z軸改變 預設鍵: (W、S)、(ArrowUp、ArrowDown)      |
  | --------------------------- | ------------------------------------------------------- |
  | Input.GetAxis("Horizontal") | 讓物件x軸改變 預設鍵: (A、D)、(ArrowLeft、ArrowRight)\| |
  |                             |                                                         |

  

  ### text

* canvus的白框對應到遊戲畫面的框框，test在選中心點按下alt，可以讓物件和center一起動

* test的文字大小(font size)可以不用調，調最佳適應(best fit)就好

* 使用一個程式碼取改text(cube_create)，用其他程式碼計算分數(cube_delete)



* 在unity使用圖片，要把圖片類型的default改成sprite

* 在建置和設定(built and setting)中，要加入目前的場景，才可以在script中使用
* skybox是一種環境，可以用material去設定(最簡單的是6面體)

> 在unity裡面要使用物件只要拿到他的控制權就好了



* relative position 可以先alien位置再調整margin



* public static float Score = 0 // static 多個程式使用，不會生成多個，只會有一個
* 要使用其他類的public變數時直接  -->  檔名.變數  就可以使用





## 

