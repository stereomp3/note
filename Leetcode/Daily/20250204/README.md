# [Maximum Ascending Subarray Sum](https://leetcode.com/problems/maximum-ascending-subarray-sum/)

簡單題目 easy

給定一個 vector nums，回傳裡面升序排列總和最大的數字

**Example 1:**

```
Input: nums = [10,20,30,5,10,50]
Output: 65
Explanation: [5,10,50] is the ascending subarray with the maximum sum of 65.
```

**Example 2:**

```
Input: nums = [10,20,30,40,50]
Output: 150
Explanation: [10,20,30,40,50] is the ascending subarray with the maximum sum of 150.
```

**Example 3:**

```
Input: nums = [12,17,15,13,10,11,12]
Output: 33
Explanation: [10,11,12] is the ascending subarray with the maximum sum of 33.
```

 

**Constraints:**

- `1 <= nums.length <= 100`
- `1 <= nums[i] <= 100`



> 自己的解法

很簡單，直接走過去然後紀錄最大值，然後回傳

```c++
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0];
        int max = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i]>nums[i-1]){
                max+=nums[i];
            }
            else{
                if(max > ans) ans = max;
                max = nums[i];
            }
        }
        if(max > ans) ans = max;
        return ans;
    }
};
```

這題太簡單所以不放最佳解