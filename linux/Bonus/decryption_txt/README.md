#### c.txt

內容:  `SXQgcmFpbnMgY2F0cyBhbmQgZG9ncy4=` 

使用base64解密

得到: `It rains cats and dogs.`  (anwser)





#### b.txt

內容:   `VGhpcyBpcyBhbiBhcHBsZS4=` 

使用base64解密

得到: `VGhpcyBpcyBhbiBhcHBsZS4=` 

後面有等號，判斷要再次使用base64解密

得到: `This is an apple.`  (anwser)



#### a.txt

`JTY4JTc0JTc0JTcwJTNhJTJmJTJmJTc3JTc3JTc3JTJlJTZlJTcxJTc1JTJlJTY1JTY0JTc1JTJlJTc0JTc3`

使用base64解密

得到: `%68%74%74%70%3a%2f%2f%77%77%77%2e%6e%71%75%2e%65%64%75%2e%74%77`

上面形式為 "%xx"，數字範圍在0~F之間，判斷要使用Escape解密

得到:  `http://www.nqu.edu.tw` (anwser)



使用解密網站: [base64](https://toolbox.googleapps.com/apps/encode_decode/?lang=zh-TW)、[Escape](https://tool.chinaz.com/tools/escape.aspx)

