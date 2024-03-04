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
    - hashset.find; 如果 hashset.find == hashset.end() 就代表沒找到，找到傳回 iter 位置
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



* multiset 與 set 用法差不多，但會保留重複的元素，資料由小到大排序。

  ```c++
  multiset<int> ms;
  ms.erase(val); // 會刪除所有值為 val 的元素。
  ms.erase(st.find(val));
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

   - hashmap.erase(int); 刪除特定元素 delete key
   - hashmap.clear(); 全部刪掉

4. 獲取

   - hashmap.count(int); map 裡面是否有該 key，有的話回傳 0
   - hashmap.empty; 如果 map 為空 回傳非 0 值
   - hashmap.find; 如果 hashmap.find == hashmap.end() 就代表沒找到，找到傳回 iter 位置

5. 取得長度

   - hashmap.size();



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





# others

chatGPT

map: https://en.cppreference.com/w/cpp/container/map

pair: https://en.cppreference.com/w/cpp/utility/pair

In C++, the difference in usage between `pair` and `map` when accessing their elements is due to the way they are implemented and the syntax chosen for those implementations.

1. **Pair (`std::pair`)**: This is a simple data structure that holds two values. In a `pair`, you access its elements directly using the dot (`.`) operator because the elements are stored directly within the `pair` object.

   ```c++
   pair<int, int> a = make_pair(0, 0);
   printf("%d, %d", a.first, a.second); // Accessing elements using dot operator
   ```

2. **Map (`std::map`)**: This is an associative container that stores key-value pairs. In a `map`, each element is a key-value pair, and when you iterate over a `map`, you are iterating over these key-value pairs. Since each element is a pair itself, you access the key and value of each element using the arrow (`->`) operator because you're accessing a member of the pair (which is a pointer).

   ```c++
   map<int, int> m;
   m[0] = 1;
   for (auto i = m.begin(); i != m.end(); ++i) {
       printf("%d, %d", i->first, i->second); // Accessing elements using arrow operator
   }
   ```

In summary:

- For `pair`, elements are accessed directly using the dot (`.`) operator because the elements are stored directly within the `pair` object.
- For `map`, elements are accessed using the arrow (`->`) operator because each element is a pair, and you're accessing members of that pair through a pointer.



因為 map 的 pair 使用 [allocator pointer](https://zh.wikipedia.org/zh-tw/%E5%88%86%E9%85%8D%E5%99%A8_(C%2B%2B)) 讓 STL 變成模板 T，可以放入各種資料型態

In C++, `Allocator::pointer` refers to the type used to represent a pointer to an allocated memory block.

When you allocate memory dynamically using an allocator (such as `std::allocator`), the `pointer` type within that allocator specifies the type of pointer that is returned when memory is allocated.

For example, in the context of `std::allocator`, `std::allocator::pointer` is typically defined as `T*`, where `T` is the type of object being allocated. This means that when you allocate memory using `std::allocator`, you get back a pointer of type `T*`.

Here's a simple example:

```c++
cppCopy code#include <iostream>
#include <memory>

int main() {
    std::allocator<int> alloc;
    std::allocator<int>::pointer ptr = alloc.allocate(1); // Allocating memory for one integer
    *ptr = 42; // Assigning a value to the allocated memory
    std::cout << *ptr << std::endl; // Output: 42
    alloc.deallocate(ptr, 1); // Deallocating the allocated memory
    return 0;
}
```

In this example, `std::allocator<int>::pointer` is `int*`, which means `ptr` is a pointer to an integer. It's used to access the memory allocated by the allocator.
