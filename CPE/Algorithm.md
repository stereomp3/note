# algorithm



## algorithm 常用功能
* sort(vec.begin(), vec.end()): 
   > 對vector進行升序排列
   > 後面可以再加上判斷條件，是使用function回傳布林值 `sort(vec.begin(), vec.end())`
```c
bool compare(int a, int b) {
    return a > b;
}

// ....
sort(vec.begin(), vec.end(), compare);

///////////////////////////////
compare裡面不可以用auto類型，需要傳入正確型態
bool compare(const pair< int, int > &x, const pair< int, int > &y){
	return x.second > y.second;
}

```


* reverse(vec.begin(), vec.end()): 
   > 對vector進行反轉


* for_each(vec.begin(), vec.end(), lambda運算式):
   > 可以對vector裡面的每個元素進行操作


* find(vec.begin(), vec.end(), search): 
   > 對vector進行查找，search可從終端輸入，可把find傳入迭代器裡或auto變數裡面 


* find_if(vec.begin(), vec.end(), lambda運算式): 
   > 對vector進行查找，找到條件滿足就回傳，可把find_if傳入迭代器或auto變數裡面


* copy_if(vec.begin(), vec.end(), 存放複製的第一個元素(如果存放陣列不夠大會報錯), lambda運算式 ):
   > 對vector進行複製，符合條件回傳陣列給vector，可把copy_if傳入迭代器裡或auto變數裡面 


* remove_if(vec.begin(), vec.end(), lambda運算式): 
   > remove_if 並不是真的把元素從原容器去除了，它只是將要去除的元素往後移，然後傳回這些元素的起點，如果這些元素你真的不要了，可以使用 vector 的 erase 方法


* transform(vec.begin(), vec.end(), 存放複製的第一個元素, lambda運算式);
   > 一級函式的語言中愛談的 map，在 C++ 中可以使用 tranform 來解決


## demo01: 陣列排序、尋找陣列、反轉陣列(sort、find、reverse)

input:
```c++
#include <algorithm> // sort、 find、reverse
#include <iostream> 
#include <vector>
using namespace std; 

int main() { 
    vector<int> number = {30, 12, 55, 31, 98, 11, 41, 80, 66, 21};

    // 排序 
    sort(number.begin(), number.end());
    for(auto n : number) {
        cout << n << " ";
    }
    cout << endl;

    cout << "輸入搜尋值：";
    int search = 0;
    cin >> search;

    // 尋找
    vector<int>::iterator it = find(number.begin(), number.end(), search);
    cout << (it != number.end() ? "找到" : "沒有")
         << "搜尋值" 
         << endl;

    // 反轉 
    reverse(number.begin(), number.end());
    for(auto n : number) {
        cout << n << " ";
    }
    cout << endl;

    return 0; 
}
```
output:
```c++
11 12 21 30 31 41 55 66 80 98
輸入搜尋值：22
沒有搜尋值
98 80 66 55 41 31 30 21 12 11
```

<hr>

## demo02: 尋找首個偶數(find_if)

input:
```c++
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> number = {11, 12, 21, 30, 31, 41, 55, 66, 80, 98};

    auto p = find_if(number.begin(), number.end(), [] (int n) { return n % 2 == 0; });  // return 判斷條件，符合就回傳

    if(p != number.end()) {  // 如果p在陣列裡，就打印
        cout << *p << endl;
    }
    else {
        cout << "no odd" << endl;
    }

    return 0;
}

```

output:
```c++
12
```

<hr>

## demo02: 複製、尋找元素 (copy_if)(類似python filter(函數, 可迭代對象)): 

input:
```c++
#include <algorithm>
#include <iostream> 
#include <vector>
using namespace std; 

int main() { 
    vector<int> number = {11, 12, 21, 30, 31, 41, 55, 66, 80, 98};
    vector<int> dest(number.size()); // 建立長度和number一樣的矩陣

    auto destEnd = copy_if(
        number.begin(), number.end(), dest.begin(), 
        [] (int n) { return n % 2; }   // 這邊把條件過濾，filter出來的條件保留在新容器
    ); 

    // 11 21 31 41 55
    for_each(dest.begin(), destEnd, [](int n) { cout << n << " "; }); //(容器開始, 容器結束, 函式)
   
    return 0; 
}
```

```c++
#include <algorithm>
#include <iostream> 
#include <vector>
#include <iterator> /* 使用 iterator 的 back_inserter，這會包裹目標容器，目標容器必須支援 push_back 方法（例如 vector），
                       傳回的迭代器若被用來指定值至對應位置時，底層會呼叫 push_back 方法在目標容器新增元素(使用這個是因為容量會影響copy_if的操作)。*/
using namespace std; 

int main() {    // 也可以使用這種寫法，輸出不變
    vector<int> number = {11, 12, 21, 30, 31, 41, 55, 66, 80, 98};
    vector<int> dest;

    copy_if(
        number.begin(), number.end(), 
        back_inserter(dest), [] (int n) { return n % 2; }
    );

    // 11 21 31 41 55
    for_each(dest.begin(), dest.end(), [](int n) { cout << n << " "; });

    return 0; 
}
```

output:
```c++
11 21 31 41 55
```

> 也可以用vector的迭代功能和erase，打印所有奇數(但erase會刪除到原先的矩陣)
```c++
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> number = {11, 12, 21, 30, 31, 41, 55, 66, 80, 98};

    for(vector<int>::iterator it = number.begin(); it != number.end(); it++){
        auto p = find_if(number.begin(), number.end(), [] (int n) { return n % 2; });
        if(p != number.end()) {
            cout << *p << endl;
            number.erase(p);
        }
        else {
            cout << "no odd" << endl;
        }
    }
    return 0;
}
```

## demo03: 去除元素(remove_if)

> 去除單個元素

input:
```c++
#include <algorithm>
#include <iostream> 
#include <vector>
#include <iterator>
using namespace std; 

int main() { 
    vector<int> number = {11, 12, 21, 30, 31, 41, 55, 66, 80, 98};

    auto removeStart = remove_if(
        number.begin(), number.end(), 
        [] (int n) { return n % 2; }
    );

    // 12 30 66 80 98
    for_each(number.begin(), removeStart, [](int n) { cout << n << " "; });
    cout << endl;

    // 12 30 66 80 98 41 55 66 80 98
    for_each(number.begin(), number.end(), [](int n) { cout << n << " "; });

    return 0; 
}
```

output:
```c++
12 30 66 80 98
12 30 66 80 98 41 55 66 80 98
```

> 去除多個元素

input:
```c++
#include <algorithm>
#include <iostream> 
#include <vector>
#include <iterator>
using namespace std; 

int main() { 
    vector<int> number = {11, 12, 21, 30, 31, 41, 55, 66, 80, 98};

    auto removeStart = remove_if(
        number.begin(), number.end(), 
        [] (int n) { return n % 2; }
    );
    number.erase(removeStart, number.end());  // 利用erase拿掉所有元素

    // 12 30 66 80 98
    for_each(number.begin(), removeStart, [](int n) { cout << n << " "; });

    return 0; 
}

output:
```c++
12 30 66 80 98
```

## demo04: 對每個元素進行操作(transform)

```c++
#include <algorithm>
#include <iostream> 
#include <vector>
#include <iterator>
using namespace std; 

int main() { 
    vector<int> number = {11, 12, 21, 30, 31, 41, 55, 66, 80, 98};
    vector<int> dest;

    transform(
        number.begin(), number.end(), 
        back_inserter(dest), [] (int n) { return n * 10; }  //把每個元素的值 * 10
    );

    // 110 120 210 300 310 410 550 660 800 980
    for_each(dest.begin(), dest.end(), [](int n) { cout << n << " "; });

    return 0; 
}
```

output:
```
110 120 210 300 310 410 550 660 800 980
```

