# [Count Servers that Communicate](https://leetcode.com/problems/count-servers-that-communicate/)

給定一個 二維 vecter grid，找出 col 和 row，數量大於 2 的點 

EX:

![](https://assets.leetcode.com/uploads/2019/11/14/untitled-diagram-6.jpg)

```
Input: grid = [[1,0],[0,1]]
Output: 0
Explanation: No servers can communicate with others.
```

![](https://assets.leetcode.com/uploads/2019/11/13/untitled-diagram-4.jpg)

```
Input: grid = [[1,0],[1,1]]
Output: 3
Explanation: All three servers can communicate with at least one other server.
```

![](https://assets.leetcode.com/uploads/2019/11/14/untitled-diagram-1-3.jpg)

```
Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
Output: 4
Explanation: The two servers in the first row can communicate with each other. The two servers in the third column can communicate with each other. The server at right bottom corner can't communicate with any other server.
```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m <= 250`
- `1 <= n <= 250`
- `grid[i][j] == 0 or 1`



> 我的解法

這題想了蠻久的，想到 [First Completely Painted Row or Column](https://leetcode.com/problems/first-completely-painted-row-or-column/) 最佳解有使用 rolsum 和 colsum 紀錄 row和 col 總和，所以我也用這個方法做做看

先看 row，rowsum 大於 2，就加入到答案裡面，如果 rowsum 小於 2 就看 col 有沒有大於 2，有的話就加上去

```c++
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        // num, col or row num
        vector<int> rolsum(row, 0), colsum(col, 0);
        for(int x=0; x<row; x++){
            for(int y=0; y<col; y++){
                if(grid[x][y]==1){
                    rolsum[x]+=1;
                    colsum[y]+=1;
                }
            }
            
        }
        for(int x=0; x<row; x++){
            cout << "rolsum[x]: " << rolsum[x] << endl;
            if(rolsum[x] > 1) ans += rolsum[x];
            else{
                for(int y=0; y<col; y++){
                    if(colsum[y] > 1 && grid[x][y] == 1){
                        ans += 1;
                    }
                }
            }
        }
        
        
        return ans;
    }
};
```



```
[0,0,1,0,1],
[0,1,0,1,0],
[0,1,1,1,0],
[1,0,0,1,1],
[0,0,1,1,0]

row   2,0,0,0,0
col   0,0,1,0,1
ans + 2

row   2,2,0,0,0
col   0,1,1,1,1
ans + 2

row   2,2,3,0,0
col   0,2,2,2,1
ans + 1, ans + 1, ans + 1

row   2,2,3,3,0
col   1,2,2,3,2
ans + 1, ans + 1, ans + 1

row   2,2,3,3,2
col   1,2,3,4,2
ans + 1, ans + 1

```



> 別人最佳解

beat 100

跟我想法一樣，不過在最後找點他是用 1 和 colsum, rowsum 判斷

```c++
class Solution {
    public int countServers(int[][] grid) {
        int m=grid.length;
        int n=grid[0].length;
        int[] rowCnt=new int[m]; 
        int[] colCnt=new int[n];

        // Count servers in each row and column
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){                   
                    rowCnt[i]++;
                    colCnt[j]++;                    
                }
            }
        }

        int cnt=0;
        // Count communicating servers
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){                   
                    if(rowCnt[i]>1 || colCnt[j]>1){
                        cnt++;
                    }                 
                }
            }
        }

        return cnt;
    }
}
```

