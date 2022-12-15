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

