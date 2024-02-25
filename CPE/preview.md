## CPE 2021-10-19
### `cin.ignore(int, char)`
> 字串處理: `cin.ignore(num, "str");`，輸入第num後或是偵測到字符"str"後才會存入

> 如果`cin.ignore()不給參數`，則默認參數為cin.ignore(1,EOF)

```c++
#include <iostream>
using namespace std;
int main()
{
    char array[8];
    cin.ignore(6,'a');
    cin.getline(array, 8);
    cout << array << endl;
    return 0;
}
/*
輸入：bcdefgk 輸出：k
輸入：bcagkld 輸出：gkld
*/
```

### `getline(cin, str)`
> https://vimsky.com/zh-tw/examples/usage/getline-string-c.html

> 接收一個字串，可以接收空格並輸出，需包含 `#include<string>`，遇到換行就停止接收
```c++
#include<iostream>
#include<string>
using namespace std;
main ()
{
    string str;
    getline(cin,str);
    cout<<str<<endl;
}

/*
輸入：jkljkljkl 輸出：jkljkljkl
輸入：jkl jfksldfj jklsjfl 輸出：jkl jfksldfj jklsjfl
*/
```
> `cin.getline(char[] or str, int)` 跟getline很像，不過他可以指定接收多少字元(int)

#### `cin.get()`
> 這個可以判斷換行，好用 

```c++
#include <iostream>
using namespace std;
int main(){
	char c, in;
	while(cin >> in){
		c = cin.get(); // 可以讀取一個字元，這裡是讀取空白和換行
		if(c == 10){  // 判斷是不是換行
			//...
		}	
	}
}
```

### else
> `unsign long long a` 可以取到很大的數!!!

#### 最大公因數(GCD)速求法
```c++
unsigned long long gcd(unsigned long long a, unsigned long long b) {
    return (b == 0) ? a : gcd(b, a % b);
}
```
> 最小公倍數: 兩數除以兩數的GCD

#### 字符轉小寫
```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    string words;
    getline(cin, words);
    for (int i = 0; i < words.size(); ++i) {
        if ('A' <= words[i] && words[i] <= 'Z'){
            words[i] += 32; // 轉小寫
        }
    }
    return 0;
}
```

#### prime
```c
bool IsPrime(int n){
    if(n < 2) return false;  // return 0

    for(int i = 2; i < n/2; i++){
        if(n%i == 0) return false;     
    }
    return true
}
```


#### ASCII
* 空白鍵: 32
* a: 65
* A: 97
* 單引號 : 34
* 雙引號 : 39
* LF換行 : 10

* 迭代取值用 *it

* 二階陣列初始化: `int a[10][10] = {0}` ， 如果是char的話，預設好像就是0
* cout 要控制位數可以用: `cout << fixed <<  setprecision(4) << float`， 需要 `include <iomanip>`
* 費式數列: https://www.csie.ntu.edu.tw/~b98902112/cpp_and_algo/cpp02/fibonacci.html
* 上下左右判斷可以用矩陣: `int arr[4] = {-1,0,1,0}`
