# cout&cin

- `cout << "content"` ，把後面的內容放入 cout(呈現在螢幕上)
- `cin >> var` ，從終端取到值後，放入var
- 程式跑不夠快，可以用map，速度會提升(尤其是在for迴圈多的時候)
- cout 像是 printf()，下面是範例:  
  
- `long long 型態讀取: scanf("%lld", &n)、unsigned long long int 讀取 scanf("%ull", &n)`

1. input:

```c
#include <iostream>
#include <cstdlib>
using namespace std;
int main(void)
{
   int num1 = 5, num2 = 3;

   cout << "I love C++." << endl << "You love C++, too.\n"; //endl等價於\n
   cout << "We all love C++." << "\n";
   cout << " I have "<< num1 <<" books."<<endl;
   cout << "We have "<<(num1+num2)<<" books. "<<endl;
}
```

2. output:

```c
I love C++.
You love C++, too.
We all love C++.
 I have 5 books.
We have 8 books.
```

---

- cin 像是 scanf()，下面是範例:  
  

1. intput:

```c
#include <iostream>
#include <cstdlib>
using namespace std;
int main(void)
{
   int x, y;

   cout << "Input frist integer: ";
   cin >> x;                                //讀取鍵盤中的整數，並存放
   cout << "Input second integer: ";
   cin >> y;
   cout << x <<"+"<< y <<"="<< x+y <<endl;  //兩數相加

   cout << "Input two integer: ";
   cin >> x >> y;                           //連續輸入兩個
   cout << x <<"+"<< y <<"="<< x+y <<endl;  //兩數相加
   system("pause");
   return 0;
}
```

2. output:

```c
Input frist integer: 1
Input second integer: 2
1+2=3
Input two integer: 3 4
3+4=7
請按任意鍵繼續 . . .
```

#### math.h

- 使用次方: `pow(a, n)`
  
- 使用圓周率: `M_PI`
  
- 使用cos、sin: `cos(i * M_PI / 180), sin(i * M_PI / 180)`， i是度數
  
- 指標
  

```c
int *ptr, num = 20;
ptr = &num

// ptr是值(*ptr)的位置，&num是值(num)的位置
```

- 指標變數不論他只向的變數型態為何，都站4 bytes
  
- 導入所有 C++ STD lib
  

```c
#include <bits/stdc++.h>

using namespace std;

int main()
{

}  
```

- **遇到浮點數運算記得一定要使用 double 而不是 float**
- `c_str()` 可以把 c++ string 轉換成以NULL結尾的字串 EX: `str.c_str()`