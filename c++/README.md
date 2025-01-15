* 施工中...



```c++
sort(ve.begin(), ve.end(), [] (const auto &x,const auto &y) {return x.second == y.second ? x.first < y.first : x.second > y.second;});
for(auto iter = ve.begin(); iter != ve.end(); iter++){
    if(iter->first < 91 && iter->first > 64){
        cout << iter->first << " " << (*iter).second << endl;
    }
}
```

`v->c `等於` (*v).c`，這個是縮寫

`[] (const auto &x,const auto &y) `等於 `[] (auto x,auto y) `，加上那些是為了提高效能，節省空間





class Constructor & Destructor: https://cpp2015.blogspot.com/2015/07/constructor-destructor.html (裡面講解 c++ 的 constructor 和 destructor 呼叫時間點，與在 copy constructor 需要用到的寫法，以及 pass by reference 與 pass by value constructor 呼叫的次數差異)
