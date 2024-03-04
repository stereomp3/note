# map

![map01](https://github.com/stereomp3/note/blob/main/picture/c%2B%2B/map01.png)

> map usage: https://yuihuang.com/cpp-stl-map/

> unordermap: `#include <unordered_map>`

> **map 就像是 python 裡面的字典一樣，有key和value，key無法修改，只可以改value**

> 通常要資料排序會用map，但如果是查找東西就會用unordered_map

## map特色
* map 內部資料結構為一顆紅黑樹 (red-black tree)，因此：
   * 內部是有排序的資料。
   * 對於搜尋和插入操作友善( O(logn) )。
* 可以修改 value 值、不能修改 key 值。
* 以模板（泛型）方式實現，可以儲存任意類型的變數，包括使用者自定義的資料型態。

## map用法

1. 創建
   * map<類型(key), 類型(value)> 變量名 -  創建字典，可以在裡面放入鍵和值

2. 添加
   * 矩陣添加: 變量名[key] = value
   * 變量名.insert(pair<類型(key), 類型(value)>(變量, 變量));

3. 獲取

![map02](https://github.com/stereomp3/note/blob/main/picture/c%2B%2B/map02.png)

   * 變量名.find(key):  var = map.find(key)
     > 用 var->first 找到key

     > 用 var->second 找到value

```c++
iter = mapStudent.find("r123");

if(iter != mapStudent.end()) // find in map
       cout<<"Find, the value is"<<iter->second<<endl; // find value
else
   cout<<"Do not Find"<<endl;
```

```c++
for (auto it = mp.begin(); it != mp.end(); ++it){
    cout << it->first << " => " << it->second << '\n';
}
 
for (auto it = mp.begin(); it != mp.end(); ++it){
    cout << (*it).first << " => " << (*it).second << '\n';
}
```

4. 刪除


```c++
//迭代器刪除
iter = mapStudent.find("r123");
mapStudent.erase(iter);

//用關鍵字刪除
int n = mapStudent.erase("r123"); // 如果刪除了會返回1，否則返回0

//用迭代器範圍刪除 : 把整個map清空
mapStudent.erase(mapStudent.begin(), mapStudent.end());
//等同於mapStudent.clear()
```


## demo01: Map 整體操作

input:

```c++
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){

    //declaration container and iterator
    map<string, string> mapStudent;
    map<string, string>::iterator iter;
    map<string, string>::reverse_iterator iter_r;

    //insert element
    mapStudent.insert(pair<string, string>("r000", "student_zero"));

    mapStudent["r123"] = "student_first";
    mapStudent["r456"] = "student_second";

    //traversal
    for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
                //r000 student_zeror   123 student_firstr   456 student_second
                cout<<iter->first<<" "<<iter->second<<endl;

    for(iter_r = mapStudent.rbegin(); iter_r != mapStudent.rend(); iter_r++)
                //456 student_second   123 student_firstr   r000 student_zeror
                cout<<iter_r->first<<" "<<iter_r->second<<endl;

    //find and erase the element
    iter = mapStudent.find("r123");
    mapStudent.erase(iter); // erase("r123", student_firstr)

    iter = mapStudent.find("r123");

    if(iter != mapStudent.end())
       cout<<"Find, the value is "<<iter->second<<endl;
    else
       cout<<"Do not Find"<<endl;

    return 0;
}
```

output:

```c++
r000 student_zero
r123 student_first
r456 student_second
r456 student_second
r123 student_first
r000 student_zero
Do not Find
```

### map sort
```c++
#include <iostream>
#include <map>
#include <vector>

using namespace std;
int main(){
    map<string, string> veggy_map = {{"1", "Yam",},{"2", "Pumpkin",},{"3", "Ginger",},{"4", "Melon",},{"5", "Beetroot",},{"6", "Spinach",}};

    cout << "Unsorted - " << endl;
    for (const auto & [key, value] : veggy_map) {  // const 會比較快也會比較安全
        cout << key << " : " << value << endl;
    }

    vector<pair<string, string> > arr;
    for (const auto &item : veggy_map) {
        arr.emplace_back(item);  // 也可以用push_back()
    }

    sort(arr.begin(), arr.end(),[] (const auto &x, const auto &y) {return x.second < y.second;});

    cout << "Sorted - " << endl;
    for (const auto & [key, value] : arr) {
        cout << key << " : " << value << endl;
    }
}
```


* `mp.count(key);` : 檢查 key 是否存在 map 中，如果有 return 1，反之 return 0

* pair 取值是使用 .

```c++
int main()
{
    multimap<int, int> map_a;
    iMap[1] = 1;
    iMap[2] = 2;
    iMap[5] = 3;
    iMap[4] = 4;

    vector<pair<int, int>> map_b;
    for (auto it = map_a.begin(); it != map_a.end(); it++)
        map_b.push_back(make_pair(it->first, it->second));

    sort(map_b.begin(), map_b.end(), 
        [](const pair<int, int> &x, const pair<int, int> &y) -> int {
        return x.second < y.second;
    });

    for (auto it = map_b.begin(); it != map_b.end(); it++)
        cout << it->first << ':' << it->second << '\n';
    return 0;
}
```

