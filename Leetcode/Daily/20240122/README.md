# [Map of Highest Peak](https://leetcode.com/problems/map-of-highest-peak/)

給定一個二維 vector isWater，0 代表有水， 1 代表陸地，陸地會根據離水源的距離決定高度

EX:

![](https://assets.leetcode.com/uploads/2021/01/10/screenshot-2021-01-11-at-82045-am.png)

```
Input: isWater = [[0,1],[0,0]]
Output: [[1,0],[2,1]]
Explanation: The image shows the assigned heights of each cell.
The blue cell is the water cell, and the green cells are the land cells.
```

![](https://assets.leetcode.com/uploads/2021/01/10/screenshot-2021-01-11-at-82050-am.png)

```
Input: isWater = [[0,0,1],[1,0,0],[0,0,0]]
Output: [[1,1,0],[0,1,1],[1,2,2]]
Explanation: A height of 2 is the maximum possible height of any assignment.
Any height assignment that has a maximum height of 2 while still meeting the rules will also be accepted.
```



```
# ex3
isWater =
[[0,0,1,0],[1,0,0,0],[0,0,0,0],[0,0,0,1]]
output = 
[[1,1,0,1],[0,1,1,2],[1,2,2,1],[2,2,1,0]]
# ex4
isWater =
[[0,0,1,0],[0,0,0,0],[0,0,0,1]]
output = 
[[2,1,0,1],[3,2,1,1],[3,2,1,0]]
```





> 我的解法

Beat 75

把開始有 1 的點資訊 push 進去 queue，然後根據點看向四周，沒填入過的點為 -1，慢慢延伸到整個 isWater vector。

可能因為最近的題目太多 BFS，所以我這題寫很快，直接搞定

```c++
struct node{
    int x, y, v;
    node(int _x=0, int _y=0, int _v=0){
        x = _x;
        y = _y;
        v = _v;
    }
};
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<node> q;
        int row = isWater.size();
        int col = isWater[0].size();

        for(int i = 0; i < row; i++){
            for(int y = 0; y < col; y++){
                if(isWater[i][y] == 1){
                    isWater[i][y] = 0;
                    q.push(node(i, y, 0));
                }
                else{
                    isWater[i][y] = -1;
                }
            }
        }
        while(!q.empty()){
            node n = q.front();
            if(n.x > 0){
                if(isWater[n.x-1][n.y]==-1){
                    q.push(node(n.x-1, n.y, n.v+1));
                    isWater[n.x-1][n.y] = n.v+1;
                }
            }
            if(n.x < row-1){
                if(isWater[n.x+1][n.y]==-1){
                    q.push(node(n.x+1, n.y, n.v+1));
                    isWater[n.x+1][n.y] = n.v+1;
                }
            }
            if(n.y > 0){
                if(isWater[n.x][n.y-1]==-1){
                    q.push(node(n.x, n.y-1, n.v+1));
                    isWater[n.x][n.y-1] = n.v+1;
                }
            }
            if(n.y < col-1){
                if(isWater[n.x][n.y+1]==-1){
                    q.push(node(n.x, n.y+1, n.v+1));
                    isWater[n.x][n.y+1] = n.v+1;
                }
            }
            q.pop();
        }
        return isWater;
    }
};
```



> 別人的最佳解

很多都是 BFS 這邊就不放了