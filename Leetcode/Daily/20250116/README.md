# [Bitwise XOR of All Pairings](https://leetcode.com/problems/bitwise-xor-of-all-pairings/)

> 問題

給定兩個 vector num1 和 num2，這兩個 list 兩個兩個 element 做 XOR 變成一個 vector num3，把 num3 裡面所有元素在做 XOR 之後回傳這個數字



EX:

```
# Example 1:

Input: nums1 = [2,1,3], nums2 = [10,2,5,0]
Output: 13
Explanation:
A possible nums3 array is [8,0,7,2,11,3,4,1,9,1,6,3].
The bitwise XOR of all these numbers is 13, so we return 13.

# Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 0
Explanation:
All possible pairs of bitwise XORs are nums1[0] ^ nums2[0], nums1[0] ^ nums2[1], nums1[1] ^ nums2[0],
and nums1[1] ^ nums2[1].
Thus, one possible nums3 array is [2,5,1,6].
2 ^ 5 ^ 1 ^ 6 = 0, so we return 0.
```

**Constraints:**

- `1 <= num1, num2 <= 109`

> 我的解法



每個元素去 XOR，需要用到兩個 for 會 Time Limit Exceeded

```c++
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        for(auto x:nums1){
            for(auto y:nums2){
                int tmp = x^y;
                ans ^= tmp;
            }
        }
        return ans;
    }
};
```



0ms, Beats 100.00%

運用 XOR 特性，重複 XOR 會變成自己，所以判斷兩個 vector 的 size，決定需要回傳的答案。

```c++
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int ans = 0;
        if((size1 % 2)==0 && (size2 % 2)==0) return 0;
        if((size1 % 2)==1 && (size2 % 2)==0) {
            for(auto i : nums2){
                ans^=i;
            }
        }
        if((size1 % 2)==0 && (size2 % 2)==1){
            for(auto i : nums1){
                ans^=i;
            }
        }
        if((size1 % 2)==1 && (size2 % 2)==1){
            for(auto i : nums1){
                ans^=i;
            }
            for(auto i : nums2){
                ans^=i;
            }
        }
        return ans;
    }
};
```





> 最佳解

 基本上和我的想法是一樣的

```c++
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int c1 = nums1.size();
        int c2 = nums2.size();
        int x1 = 0, x2 = 0;
        
        if (c1 % 2 != 0) {
            for (int num : nums2) {
                x2 ^= num;
            }
        }
        if (c2 % 2 != 0) {
            for (int num : nums1) {
                x1 ^= num;
            }
        }
        return x1 ^ x2;
    }
};
```

