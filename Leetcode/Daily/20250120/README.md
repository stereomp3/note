# [First Completely Painted Row or Column](https://leetcode.com/problems/first-completely-painted-row-or-column/)

> 問題

給定一個一維 vector arr 和 二維 vector mat，arr 和 mat 裡面的數字總量一樣，並且數字也都一樣，但是順序不同，回傳 arr 最快讓 mat col 或是 rol 走過的 index



EX:

<img alt="image explanation for example 1" src="https://assets.leetcode.com/uploads/2023/01/18/grid1.jpg" style="width: 321px; height: 81px;">

```
Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
Output: 2
Explanation: The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].
```

<img alt="image explanation for example 2" src="https://assets.leetcode.com/uploads/2023/01/18/grid2.jpg" style="width: 601px; height: 121px;">

```
Input: arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
Output: 3
Explanation: The second column becomes fully painted at arr[3].
```

- **Constraints:**
  - `m == mat.length`
  - `n = mat[i].length`
  - `arr.length == m * n`
  - `1 <= m, n <= 105`
  - `1 <= m * n <= 105`
  - `1 <= arr[i], mat[r][c] <= m * n`
  - All the integers of `arr` are **unique**.
  - All the integers of `mat` are **unique**.



> 我的解法

想法是先由 arr 創建一個對應 mat 的 二維遍歷 map，裡面的值對應到 arr 的 index (這步驟要 `mat(n*m) * arr(n)` 個複雜度)，然後再根據 col 和 row 找出最小 index，沒意外果然超時

Time Limit Exceeded ...

最後沒解出來

```c++
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int length = mat.size();
        int width = mat[0].size();
        vector<vector<int>> times_map(length, vector<int>(width, 0));
        queue<int> q;
        for(auto i : arr){
            q.push(i);
        }
        int step = 0;
        while(!q.empty()){
            int num = q.front();
            for(int x = 0; x < length; x++){
                for(int y = 0; y < width; y++){
                    if(num == mat[x][y]){
                        times_map[x][y] = step;
                        step += 1;
                    }
                }
            }
            q.pop();
        }

        
        int min = INT_MAX;
        for(int x = 0; x < length; x++){
            int tmp = 0;
            int max_num = -1;
            for(int y = 0; y < width; y++){
                if(times_map[x][y] > max_num) max_num = times_map[x][y];
            }
            if(min > max_num && max_num!=-1){
                min = max_num;
            }
        }
        for(int x = 0; x < width; x++){
            int tmp = 0;
            int max_num = -1;
            for(int y = 0; y < length; y++){
                if(times_map[y][x] > max_num) max_num = times_map[y][x];
            }
            if(min > max_num && max_num!=-1){
                min = max_num;
            }
        }
        return 0;
    }
};
```





直接看別人的解法

使用 map: https://leetcode.com/problems/first-completely-painted-row-or-column/solutions/6304385/simple-count-of-coloured-row-column-detailed-solution/

先把 mat 轉成 unorder_map，用 index 方式可以找出元素在哪個位置 (row, col)，然後使用兩個 vector 紀錄目前 row 和 col 總共有幾個必須要上色的數量。開始遍歷 arr，取出對應的 mat index，對應的 rowCount 和 colCount 都減一，當其中一個 count 為 0，就回傳 index

```c++
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        unordered_map<int, pair<int, int>> positionMap;
        // Tracking Uncolored Cells
        vector<int> rowCount(rows, cols), colCount(cols, rows);
		// Mapping Cell Values to Indices
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                positionMap[mat[r][c]] = {r, c};
            }
        }

        for (int idx = 0; idx < arr.size(); ++idx) {
            int val = arr[idx];
            auto [row, col] = positionMap[val];

            if (--rowCount[row] == 0 || --colCount[col] == 0) {
                return idx;
            }
        }

        return -1;
    }
};
```



