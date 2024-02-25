# unordered_set
不重複集合

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

