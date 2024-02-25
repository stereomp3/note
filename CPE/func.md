> container.find(x);  // 尋找元素位置，傳回容器所在位置(int)

> container.size();  // 取得容器長度。

> container.begin();  // 指向容器第一個元素。

> container.end(); // 指向容器最尾端元素的下一個位置（請注意：它不是最末元素）。

> container.pop_back() // 刪除容器最後一個

> container.push_back() // 新增元素到容器的尾端

> container.clear() // 清除容器

> container.front() // 回傳第一個元素的值

> container.back() // 回傳最後一個元素的值

> container.erase()  // 可以填入(index)，或是(begin(),end())
```c
string& erase (size_t pos = 0, size_t len = npos);
iterator erase (iterator p);
iterator erase (iterator first, iterator last);
```

> container.empty()  // 如果容器為空，就傳回true

#### 容器迭代
```c++
for(auto it:container){
    cout << it << endl;
}

///////////////////////////////////

for(auto it = container.begin(); it != container.end(); it++){
    cout << it << endl;
}

////////////////////////////////////

for(vector<int>::iterator it = number.begin(); it != number.end(); it++) {
        cout << *it << endl;
}
```