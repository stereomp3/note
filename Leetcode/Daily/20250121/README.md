# [Grid Game](https://leetcode.com/problems/grid-game/)

給一個 二維 vector grid，他只會有兩個 row，我們有兩個機器人，都是從 `0,0` 走到 `1,n`，第一個機器人需要讓第二個機器人拿到的值最小，第二個機器人需要吃到最大的值 



![](https://assets.leetcode.com/uploads/2021/09/08/a1.png)

```
Input: grid = [[2,5,4],[1,5,1]]
Output: 4
Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
The cells visited by the first robot are set to 0.
The second robot will collect 0 + 0 + 4 + 0 = 4 points.
```



![](https://assets.leetcode.com/uploads/2021/09/08/a2.png)

```
Input: grid = [[3,3,1],[8,5,2]]
Output: 4
Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
The cells visited by the first robot are set to 0.
The second robot will collect 0 + 3 + 1 + 0 = 4 points.
```



![](https://assets.leetcode.com/uploads/2021/09/08/a3.png)

```
Input: grid = [[1,3,1,15],[1,3,3,1]]
Output: 7
Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
The cells visited by the first robot are set to 0.
The second robot will collect 0 + 1 + 3 + 3 + 0 = 7 points.
```

**Constraints:**

- `grid.length == 2`
- `n == grid[r].length`
- `1 <= n <= 5 * 104`
- `1 <= grid[r][c] <= 105`

> 我的解法

beat 5.4..

運用左右兩邊的概念，因為只有兩行，然後只能往兩個方向走，所以就 for 過 col 次，然後把所有可能列出來，一開始先創建一個上排由右到左的累加數列，下排由左到右的累加數列，計算最小值就是把尾端的值減去目前 index 那裏的數字，就可以知道會有多少 point，最後得到答案

被整數上限搞爛，因為我是使用累加，所以會超過 int，需要使用 unsigned long long (或是 long long 也可以)，然後要使用  unsigned long long 最大值就是呼叫 -1 (也可以使用 LLONG_MAX)

```c++
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int row = grid.size(); // 2
        int col = grid[0].size(); // n
        if(col <= 1) return 0;
        vector<vector<unsigned long long>> tmp_mp(row, vector<unsigned long long>(col, 0));
        grid[row-1][col-1] = 0;
        grid[0][0] = 0;

        for(int j=0; j<col-1; j++){
            tmp_mp[1][col-j-2] += (tmp_mp[1][col-j-1]+grid[1][col-j-2]);
            tmp_mp[0][j+1] += (tmp_mp[0][j]+grid[0][j+1]);
        }
        for(auto i:tmp_mp){
            for(auto y:i){
                cout << y << ", ";
            }
            cout << endl;
        }
        unsigned long long min=-1; // max for unsigned long long
        for(int i=0; i<col; i++){
            if(i==0){
                if(min > tmp_mp[1][0]) min = tmp_mp[1][0];
            }
            else if(i==col-1){
                if(min > tmp_mp[0][i]) min = tmp_mp[0][i];
            }
            else if(tmp_mp[1][0]-tmp_mp[1][i] >= tmp_mp[0][col-1]-tmp_mp[0][i] && min > tmp_mp[1][0]-tmp_mp[1][i]) min = tmp_mp[1][0]-tmp_mp[1][i];
            else if(tmp_mp[1][0]-tmp_mp[1][i] <= tmp_mp[0][col-1]-tmp_mp[0][i] && min > tmp_mp[0][col-1]-tmp_mp[0][i])min = tmp_mp[0][col-1]-tmp_mp[0][i];

        }

        return min;
    }
};
```



```
20,3,20,17,2,12,15,17,4,15
20,10,13,14,15,5,2,3,14,3

0, 105, 102, 82, 65, 63, 51, 36, 19, 15, 
96, 76, 66, 53, 39, 24, 19, 17, 14, 0, 
```

105 > 96

103 > 86+(105-103) = 88

86 < 73+(105-83) = 95

105-63=42

63+39=102



```
10,8,17,10,20,2,10,9,7,16
5,7,9,20,2,15,15,4,18,1

0, 99, 91, 74, 64, 44, 42, 32, 23, 16, 
95, 90, 83, 74, 54, 52, 37, 22, 18, 0, 

5+7+9+20+2 = 43
```



```
19,8,1,11,12
17,6,1,1,7
```



前面運算的屍體

從左到右，把數字依序加上去，然後創建一個新的陣列，根據這個陣列去清 0，然後再用 bot 2 去找最大值，後來因為判斷會很有問題所以換方法

```c++
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int row = grid.size(); // 2
        int col = grid[0].size(); // n
        if(col <= 1) return 0;

        vector<vector<int>> tmp_mp=grid;
        tmp_mp[row-1][col-1] = 0;
        grid[row-1][col-1] = 0;
        // set bot1 tmp mp
        for(int j=col-1; j>0; j--){
            tmp_mp[1][j-1] += tmp_mp[1][j];
            tmp_mp[0][j-1] += tmp_mp[0][j];
        }
        
        // boot1 clean mp
        grid[0][0] = 0;
        tmp_mp[0][0] = 0;
        for(auto i:tmp_mp){
            for(auto y:i){
                cout << y << ", ";
            }
            cout << endl;
        }
        bool is_down = false;
        int top_first = tmp_mp[0][1];
        int down_first = tmp_mp[1][0];
        cout << "top_first: "<< top_first << endl;
        cout << "down_first: "<< down_first << endl;
        for(int j=0; j<col-1; j++){
            // The sum of the numbers going down will be greater than the sum of the numbers going up
            if((top_first>tmp_mp[1][j]+tmp_mp[0][j] && j!=0) || (tmp_mp[0][j+1]<tmp_mp[1][j] && j==col-2) || down_first > top_first) is_down = true;
            cout << "tmp_mp[1][j]+tmp_mp[0][j]: " << tmp_mp[1][j]+tmp_mp[0][j] << endl;
            if(is_down) grid[1][j] = 0;
            else grid[0][j+1] = 0;
        }
        
        // set bot2 mp
        tmp_mp=grid;
        for(int j=col-1; j>0; j--){
            tmp_mp[1][j-1] += tmp_mp[1][j];
            tmp_mp[0][j-1] += tmp_mp[0][j];
        }
        int ans = 0;
        is_down = false;
        // boot1 collet point
        for(int j=0; j<col-1; j++){
            if(tmp_mp[0][j+1]<tmp_mp[1][j]) is_down = true;
            if(is_down) ans += grid[1][j];
            else ans += grid[0][j+1];
        }
        for(auto i:grid){
            for(auto y:i){
                cout << y << ", ";
            }
            cout << endl;
        }
        return ans;
    }
};
```

這個失敗



> 別人的最佳解

跟我的想法很像，不過他的寫法沒有創建 vector 而且 for 迴圈比我少，他只有一開始把上面的數字相加，然後比較上排數字與下排數字哪個比較大 (這邊跟我下面寫很醜的那段很像)，比較大的放入到 ans 裡面。

beat 100

- **Time Complexity:**

  - *O*(*n*), where (n) is the number of columns. We iterate over the grid columns once 🏃‍♂️.

- **Space Complexity:**

  - *O*(1), as only a few variables are used for calculations

  

```c++
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long top = 0;
        for (int i = 0; i < grid[0].size(); i++) {
            top += grid[0][i];
        }

        long long bottom = 0, res = LLONG_MAX;
        for (int i = 0; i < grid[0].size(); i++) {
            top -= grid[0][i]; // First robot picks from the top row 
            res = min(res, max(top, bottom)); // Minimize the maximum score for the second robot
            bottom += grid[1][i]; // Second robot picks from the bottom row 🤖
        }
        return res; 
    }
};
```

