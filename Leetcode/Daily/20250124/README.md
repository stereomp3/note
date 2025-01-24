# [Find Eventual Safe States](https://leetcode.com/problems/find-eventual-safe-states/)

給定二維 vector graph，每個數字代表連線到哪個 index，找出 save node，也就是沒有陷入無限循環的點

EX:

![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/03/17/picture1.png)

```
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
Example 2:
```



```
Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
Output: [4]
Explanation:
Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.
```

**Constraints:**

- `n == graph.length`
- `1 <= n <= 104`
- `0 <= graph[i].length <= n`
- `0 <= graph[i][j] <= n - 1`
- `graph[i]` is sorted in a strictly increasing order.
- The graph may contain self-loops.
- The number of edges in the graph will be in the range `[1, 4 * 104]`.



> 沒解出來QQ

解題失敗，嘗試使用 BFS，但會太消耗效能，而且使用 map 紀錄需要花費超多記憶體 ...，結果竟然是要使用 BFS 好兄弟 DFS

```c++
class node{
    int x;
    unordered_map<int, int> mp;
    node(int _x, unordered_map _mp){
        x = _x;
        mp = _mp
    }
};
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int len = graph.size();
        vector<int> recorder(len, 0); // -1 -> safe node, -2 -> is not safe node
        vector<int> ans;
        queue<int> q;
        for(int x=0; x < len; x++){
            if(graph[x].size() == 0){ // is safe node
                recorder[x] = -1;
            }
            if(recorder[x] == -1){
                continue;
            }
            vector<unordered_map<int, int>> vmp;
            q.push(x); // first node
            bool is_not_save = false;
            while(!q.empty()){
                node n = q.front();
                if(n.mp.cout(n)){ // is not safe node
                    is_not_save = true;
                    mp = n.mp;
                    break;
                }
                n.mp[n] = 0;
                mp[n] = 0;
                for(int i=0; i < graph[n.x].size(); i++){
                    q.push(graph[n.x][i], n.mp); // next node
                }
                
                q.pop();
            }
            if(is_not_save){
                for(auto & [k, v] : mp){
                    if(recorder[k]==2) break;
                    recorder[k] = -2;
                }
            }
            else{
                for(auto & [k,v] : mp){
                    if(recorder[k]==1) break;
                    recorder[k] = -1;
                }
            }
            
        }
        for(int i = 0; i < len; i++){
            if(recorder[i]==-1)ans.push_back(i);
        }
        return ans;
    }
        
};
```



> 最佳解

只能加上註解學一下別人的解法了 QQ

Kahn's Algorithm: 先找出第一點，然後再慢慢找出後面的點，第一點只要找沒有任何連線到 node 的點，下圖的左上數字就是連線的點，找出點後把點刪除，然後繼續找

參考網站: https://web.ntnu.edu.tw/~algo/DirectedAcyclicGraph.html

![](https://web.ntnu.edu.tw/~algo/TopologicalOrdering7.png)

```c++
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indegree(n);
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (auto node : graph[i]) { 
                adj[node].push_back(i); // adj 紀錄 node 有哪幾個點相連
                indegree[i]++; // 紀錄點連接的數量，也就是上圖左上的數字
            }
        }

        queue<int> q;
        // Push all the nodes with indegree zero in the queue.
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) { // 沒有點連接，那就是 save node
                q.push(i); // save node 就是 Kahn's Algorithm 的起始點
            }
        }

        vector<bool> safe(n);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true;
			// 把上圖左上的數字減掉，如果該點已經被減到剩下 0 就代表他只有和 save node 連線，所以可以把它加入倒 save node
            for (auto& neighbor : adj[node]) {
                // Delete the edge "node -> neighbor".
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
		
        vector<int> safeNodes;
        for (int i = 0; i < n; i++) {
            if (safe[i]) {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};
```





也可以使用 DFS 解法: 用遞迴，因為是要判斷從一開始到最後有沒有進入迴圈，所以用 DFS 可以直接判斷，這個跟我想法基本上一樣，但是使用 BFS 會導致無法判斷 visit

```c++
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visit,
             vector<bool>& inStack) {
        // If the node is already in the stack, we have a cycle.
        if (inStack[node]) {
            return true;
        }
        if (visit[node]) {
            return false;
        }
        // Mark the current node as visited and part of current recursion stack.
        visit[node] = true;
        inStack[node] = true;
        for (auto neighbor : adj[node]) {
            if (dfs(neighbor, adj, visit, inStack)) {
                return true;
            }
        }
        // Remove the node from the stack.
        inStack[node] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visit(n), inStack(n);

        for (int i = 0; i < n; i++) {
            dfs(i, graph, visit, inStack);
        }

        vector<int> safeNodes;
        for (int i = 0; i < n; i++) {
            if (!inStack[i]) {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};
```

