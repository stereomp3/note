## lambda運算式
* 抓取方式
   > []：只有兩個中括號，完全不抓取外部的變數。

   > [=]：所有的變數都以傳值（by value）的方式抓取。

   > [&]：所有的變數都以傳參考（by reference）的方式抓取。

   > [x, &y]：x 變數使用傳值、y 變數使用傳參考。

   > [=, &y]：除了 y 變數使用傳參考之外，其餘的變數皆使用傳值的方式。

   > [&, x]：除了 x 變數使用傳值之外，其餘的變數皆使用傳參考的方式。

```c++

// 不寫參不傳參
[](void) { cout << "Hello, Lambda" << endl; };  //void可寫可不寫


int n;
cout << n << endl;
// 變成lambda 運算式 // 寫參傳參
[](int n) { cout << n << endl; }
```


* 字符強制轉換型態:`(int)a`在誇號選擇要轉換的型態，char轉int會直接轉ascll
* 字串轉int(適用於char): `int num = '5' - '0'`， 這個答案會是 5
* 如果是兩個字符連在一起，轉成int，會把兩個轉成8bytes的2進位合併後，轉十進位
* int轉字串: `to_string(int)`
* while的好用功能:
```c++
while(cin >> 變數)
{
    每次輸入變數時，要做什麼事...
}
////////////////////////////////////
while(cin >> n, n)
{
    n為0時跳出迴圈
}
///////////////////////////////////
while((ch=cin.get())!=EOF)  // get all char and output
{
    cout<<(char)ch;
}
```

* `i=func();`呼叫func()函數，並將回傳值給i存放 
* `sizeof(array)` 可以表示矩陣數目，這個也可以判斷變數在記憶體裡面的大小(byte)
* `#include<string>`
    * `stoi()`: string 轉 int
    * `stoll()`: string 轉 long long int