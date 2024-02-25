# hash_set

* [unordered_set](#unordered_set)
* [unordered_map](#unordered_map)

# unordered_set

不重複不排序集合

1. 創建
   
    - unordered_set<int> hashset;
    - unordered_set<int> hashset ({4, 3, 9, 2, 0, 6})
    - unordered_set<int> hashset(vector.begin(), vector.end());
2. 添加
   
    - hashset.insert(int); 插入特定元素
3. 刪除
   
    - hashset.erase(int); 刪除特定元素
    - hashset.clear(); 全部刪掉
1. 獲取
   
    - hashset.count(int); set 裡面是否有該元素，有的話回傳 0
    - hashset.empty; 如果 set 為空 回傳非 0 值
5. 取得長度
   
    - hashset.size();



Leetcode example: https://leetcode.com/explore/learn/card/hash-table/183/combination-with-other-algorithms/1130/

```c++
#include <unordered_set>                // 0. include the library

int main() {
    // 1. initialize a hash set
    unordered_set<int> hashset;   
    // 2. insert a new key
    hashset.insert(3);
    hashset.insert(2);
    hashset.insert(1);
    // 3. delete a key
    hashset.erase(2);
    // 4. check if the key is in the hash set
    if (hashset.count(2) <= 0) {
        cout << "Key 2 is not in the hash set." << endl;
    }
    // 5. get the size of the hash set
    cout << "The size of hash set is: " << hashset.size() << endl; 
    // 6. iterate the hash set
    for (auto it = hashset.begin(); it != hashset.end(); ++it) {
        cout << (*it) << " ";
    }
    cout << "are in the hash set." << endl;
    // 7. clear the hash set
    hashset.clear();
    // 8. check if the hash set is empty
    if (hashset.empty()) {
        cout << "hash set is empty now!" << endl;
    }
}
```



Leecode find duplicates: https://leetcode.com/explore/learn/card/hash-table/183/combination-with-other-algorithms/1102/

```c++
/*
 * Template for using hash set to find duplicates.
 */
bool findDuplicates(vector<Type>& keys) {
    // Replace Type with actual type of your key
    unordered_set<Type> hashset;
    for (Type key : keys) {
        if (hashset.count(key) > 0) {
            return true;
        }
        hashset.insert(key);
    }
    return false;
}
```





# unordered_map

不重複不排序的 map

1. 創建

   - unordered_map<int, int> hashmap;

   - ```c++
     // Initialize an array of pair 
     // of strings
     pair<string,string>old_arr[] = 
     {
     make_pair("Ground", "Grass"),
     make_pair("Floor", "Cement"),
     make_pair("Table", "Wood")
     };
     
     int n = (sizeof(old_arr) / sizeof(old_arr[0]));
     
     // Adding these key-value pairs using 
     // the pairs stored in the array of pairs    
     unordered_map<string, string>New_map(old_arr,old_arr + n);
     ```

2. 添加

   - hashmap[5] = 6 ; 插入特定元素
   - hashmap.insert(make_pair(0, 0))

3. 刪除

   - hashset.erase(int); 刪除特定元素 delete key
   - hashset.clear(); 全部刪掉

4. 獲取

   - hashset.count(int); set 裡面是否有該元素，有的話回傳 0
   - hashset.empty; 如果 set 為空 回傳非 0 值

5. 取得長度

   - hashset.size();



Leetcode example: https://leetcode.com/explore/learn/card/hash-table/184/comparison-with-other-data-structures/1129/

```c++
#include <unordered_map>                // 0. include the library

int main() {
    // 1. initialize a hash map
    unordered_map<int, int> hashmap;
    // 2. insert a new (key, value) pair
    hashmap.insert(make_pair(0, 0));
    hashmap.insert(make_pair(2, 3));
    // 3. insert a new (key, value) pair or update the value of existed key
    hashmap[1] = 1;
    hashmap[1] = 2;
    // 4. get the value of a specific key
    cout << "The value of key 1 is: " << hashmap[1] << endl;
    // 5. delete a key
    hashmap.erase(2);
    // 6. check if a key is in the hash map
    if (hashmap.count(2) <= 0) {
        cout << "Key 2 is not in the hash map." << endl;
    }
    // 7. get the size of the hash map
    cout << "the size of hash map is: " << hashmap.size() << endl; 
    // 8. iterate the hash map
    for (auto it = hashmap.begin(); it != hashmap.end(); ++it) {
        cout << "(" << it->first << "," << it->second << ") ";
    }
    cout << "are in the hash map." << endl;
    // 9. clear the hash map
    hashmap.clear();
    // 10. check if the hash map is empty
    if (hashmap.empty()) {
        cout << "hash map is empty now!" << endl;
    }
}
```

