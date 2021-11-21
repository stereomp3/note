使用WebGL讓unity可以在網路上運行

1. 先到unityhub的安裝裡面，選擇版本(製作遊戲的版本)，在版本中新增模組(選擇 WebGl Build Support )
2. **專案放的位置一定要是英文路徑!!!!**，不然會建置失敗!!!!很重要!!!
3. 專案裡面UI的中文字不會再網路上顯示(除非是用圖片自己寫)

s



local run unity webgl 

1. 到firefox上面打about:config，進去後搜索privacy.file_unique_origin
2. 把那個值改成false(default: true)，就可以把index檔案放入看效果了!!
3. 如果還是不行就要改建置設定裡面的東西了

```
Other Settings
strip Engin code(剝離引擎程式碼) 不要勾
Managed Stripping Level(頂點壓縮) 從 Mixed 改成None
Optimize Mesh Data(最佳化網格資料) 不要勾

Publishing Settings
Compression Format(壓縮格式) 從 Gzip 改成 Disable

```



