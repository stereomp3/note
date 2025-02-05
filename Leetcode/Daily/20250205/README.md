# [Check if One String Swap Can Make Strings Equal](https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/)

簡單題目 easy

給兩個 string s1, s2，只能最多對 string 裡面的 char swap 一次，如果交換完成後 s1 = s2，就回傳 true。反之 false

**Example 1:**

```
Input: s1 = "bank", s2 = "kanb"
Output: true
Explanation: For example, swap the first character with the last character of s2 to make "bank".
```

**Example 2:**

```
Input: s1 = "attack", s2 = "defend"
Output: false
Explanation: It is impossible to make them equal with one string swap.
```

**Example 3:**

```
Input: s1 = "kelb", s2 = "kelb"
Output: true
Explanation: The two strings are already equal, so no string swap operation is required.
```

 

**Constraints:**

- `1 <= s1.length, s2.length <= 100`
- `s1.length == s2.length`
- `s1` and `s2` consist of only lowercase English letters.

> 我的解法

用兩個 string 存最開始兩個不一樣的 char，然後比對他們兩個是否相同，一樣救回傳 true。

```c++
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int len = s1.size();
        string s01 = "12", s02 = "34";
        int index = 0;
        for(int i = 0; i < len; i++){
            if(s1[i] != s2[i]){
                if(index == 0){
                    s01[0] = s1[i];
                    s01[1] = s2[i];
                }
                if(index == 1){
                    s02[0] = s1[i];
                    s02[1] = s2[i];
                }
                index++;
            }
            if(index > 2) return false;
        }
        if((s01[0] == s02[1] && s02[0] == s01[1]) || index == 0) return true;
        return false;
    }
};
```



這題太簡單所以不放最佳解
