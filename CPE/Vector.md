# vector

![vector](https://github.com/stereomp3/note/raw/main/picture/c%2B%2B/vector01.png)

## vector特色

- 可以儲存任意類型的變數，包括使用者自定義的資料型態
- 支援隨機存取
- 尾端增刪元素很快
- 中間增刪元素比較費時
- vector不保證stable iterator。因此存在一些造成 vector iterator 失效的操作。

## vector用法

1. 創建
   
    - vector myvector = {10, 20, 30};
    - vector myvector(10); // 建立長度為 10 的 vector，初始值為0
    - vector myvector(10, 5); // 建立長度為 10 的 vector，初始值為5
    - vector v2 = v1; // 指定v1複製到v2 (v1必須要是vector)
    - vector v2 = (v1.begin() + 2, v1.end()); // 指定v1的指定元素([2-end])複製到v2
2. 添加
   
    - myvector.push_back() - 新增元素至 vector 的尾端，必要時會進行記憶體配置。
    - myvector.insert() - 插入一個或多個元素至 vector 內的任意位置。
    - myvector.insert(myvector.begin()+i,a); - 在第 i+1 元素前面插入a
3. 刪除
   
    - myvector.pop_back() - 刪除 vector 最尾端的元素。
    - myvector.erase() - 刪除 vector 中一個或多個元素。
    - myvector.clear() - 清空所有元素。
4. 獲取
   
    - myvector[i] - 存取索引值為 i 的元素值。
    - myvector.at(i) - 存取索引值為 i 的元素的值，
    - myvector.front() - 回傳 vector 第一個元素的值。
    - myvector.back() - 回傳 vector 最尾元素的值。
5. 取得長度
   
    - myvector.empty() - 如果 vector 內部為空，則傳回 true 值。
    - myvector.size() - 取得 vector 目前持有的元素個數。
    - myvector.resize() - 改變 vector 目前持有的元素個數。
    - myvector.capacity() - 取得 vector 目前可容納的最大元素個數。這個方法與記憶體的配置有關，它通常只會增加，不會因為元素被刪減而隨之減少。
    - myvector.reserve() - 如有必要，可改變 vector 的容量大小（配置更多的記憶體），不會初始化。在眾多的 STL 實做，容量只能增加，不可以減少。(重新配置／重設長度)
6. 迭代(迭代器是一種資料形態，其意義為記憶空間位址，使用方法如指標)
   
    - 迭代器宣告 - vector::iterator 變量名 = 下面的都可以填
    - myvector.begin() - 回傳一個 iterator，它指向 vector 第一個元素。
    - myvector.end() - 回傳一個 iterator，它指向 vector 最尾端元素的下一個位置（請注意：它不是最末元素）。
    - myvector.rbegin() - 回傳一個反向 iterator，它指向 vector 最尾端元素的。
    - myvector.rend() - 回傳一個 iterator，它指向 vector 的第一個元素。 // r是使用在逆向迭代器

## demo01: 訪問容器成員

input:

```c
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> number = {10, 20, 30}; //建立容器 

    for(auto n : number) {     // 利用 for range，可以循序地走訪 vector 中的元素，
        cout << n << endl;
    }
    /*for(int i = 0; i < number.size(); i++) {  // 也可以這樣寫，跟上面的效果一樣，number.size()可以取出陣列長度，跟python裡面len()用法很像
        cout << number[i] << endl;
    }*/

    return 0;
}

```

output:

```c
10
20
30
```

---

## demo02: 可變動陣列

input:

```c
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> number;

    for(int i = 0; i < 10; i++) {
        number.push_back(i);  // 新增元素至最尾端
    }

    while(!number.empty()) {
        int n = number.back();  // 把最後一個元素存到n
        number.pop_back();  // 把最後一個元素刪除
        cout << n << endl;
    }

    return 0;
}
```

output:

```c
9
8
7
6
5
4
3
2
1
0
```

---

## demo03: 使用迭代訪問容器成員

input:

```c
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> number = {10, 20, 30};

    for(vector<int>::iterator it = number.begin();  // 建立一個迭代器，從number的第一個位置開始
        it != number.end(); it++) {
        auto n = *it;  // 取迭代器裡面的值 &是取地址
        cout << n << endl;
    }
   // for(auto n : number) { cout << n << endl;}   這個也等價於上面for迴圈

   // 如果使用 #include<algorithm>可以寫成這樣
   // for_each(number.begin(), number.end(), [](int n) { cout << n << endl; });

    return 0;
}
```

output:

```c
10
20
30
```



# 初始化 vector

ref : https://clay-atlas.com/blog/2021/12/17/cpp-2-dimension-vector-initialization/

可以控制多行的初始化，與一行就初始化，但是只能填入同個值

```c++
#include <iostream>
#include <vector>
using namespace std;


int main() {
    // Settints
    int m = 3;
    int n = 4;

    // Init
    vector<vector<int>> matrix(m);

    for (int i=0; i<m; ++i) {
        matrix[i].resize(n, i+1);
    };
    // 輸出
    //1 1 1 1 
    //2 2 2 2 
    //3 3 3 3 
	
    vector<vector<int>> matrix(m, vector<int>(n, 1));
    // 輸出
    //1 1 1 1 
    //1 1 1 1 
    //1 1 1 1
    
    vector<int> matrix(3, 4) // 一維初始化 // 4 4 4
}
```

