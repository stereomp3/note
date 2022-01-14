## 製作小地圖

> 參考 [[Tutorial] implementing a Minimap in Unity](https://blog.theknightsofunity.com/implementing-minimap-unity/)、https://www.youtube.com/watch?v=28JTTXqMvOU

先設定一台小地圖專用的Camera，把他從透視改成正交，因為會有平坦的感覺

創建一個渲染器貼圖，維度設在2D，把他放入Camera裡面的目標貼圖裡面

之後渲染器貼圖就會跟者Camera移動了!

接下來創建UI的原始影像(不能用影像)，然後把渲染器貼圖丟進去



使用 UI image 當作mask 可以把UI的邊框換成想要的形狀， UI image裡面的sprite就是要限制的形狀，注意，image裡面要加上Mask，這樣才可以!!



可以在物件裡面創建球體，讓小地圖顯示更清楚，再創建新的一層MiniMap，利用Camera讓主Camera看不到，SmallMap只看到那一層，就可以實現小地圖的效果!!



Camera使純色，讓地圖顏色是Mask的顏色

