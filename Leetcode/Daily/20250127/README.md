



使用 DFS 超時

```c++
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> mp;
        vector<bool> ans;
        for(int i=0; i<prerequisites.size(); i++){
            mp[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0; i<queries.size(); i++){
            bool is_pre = false;
            int cur;
            stack<int> s;
            s.push(queries[i][0]);
            while(!s.empty()){
                cur = s.top();
                s.pop();
                if(mp.count(cur)){
                    for(auto t : mp[cur]){
                        if(t == queries[i][1]){
                            is_pre = true;
                            break;
                        }
                        s.push(t);
                    }
                }
            }
            if(is_pre) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};
```







```
struct node{
    int v;
    vector<int> pre;
    node(int _v, vector<int>& _pre){
        v = _v;
        pre = _pre;
    }
};
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> pass(false);
        vector<bool> ans;
        unordered_map<int, int> mp;
        vector<vector<int>> vec(numCourses, vector<int>());
        for(int i=0; i<prerequisites.size(); i++){
            mp[prerequisites[i][0]] 
            pass[prerequisites[i][0]] = true; 
        } 
        queue<node> q;
        vector<int> tmp;
        for(int i=0; i<prerequisites.size(); i++){
            if(!pass[i]) q.push(node(i, tmp));
        }
        while(!q.empty()){
            node n = q.front(); q.pop();
            vector<int> v = n.pre;
            v.push_back(prerequisites[n.v][1]);
            vec[prerequisites[n.v][0]] = v;
            if(pass[prerequisites[n.v][0]]){
                q.push(node(prerequisites[n.v][0], v));
                pass[prerequisites[n.v][0]] = false;
            }
        }
        for(auto i : vec){
            for(auto y : i){
                cout << y << ", " << endl;
            }
            cout << endl;
        }
        return ans;
    }
};
```





一開始先建立所有可能的矩陣[0]，然後下去找有沒有相同的數字[1]，第二種寫法以為不會超時，結果還是超了

```c++
struct node{
    int v;
    vector<int> pre;
    node(int _v, vector<int>& _pre){
        v = _v;
        pre = _pre;
    }
};
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> pass_num(numCourses, 0);
        vector<bool> ans(queries.size(), false);
        unordered_map<int, vector<int>> mp;
        vector<vector<int>> vec(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
            pass_num[prerequisites[i][0]]++; 
        } 
        queue<node> q;
        vector<int> tmp;
        for(int i=0; i<numCourses; i++){
            if(pass_num[i]==0) q.push(node(i, tmp));
        }
        while(!q.empty()){
            node n = q.front(); q.pop();
            cout << n.v << endl;
            if(mp.count(n.v)){
                vector<int> tv = n.pre;
                tv.push_back(n.v);
                for(int z=0; z<mp[n.v].size(); z++){
                    for(auto i:tv){
                        vec[mp[n.v][z]].push_back(i);
                    }
                    if(pass_num[mp[n.v][z]]!=0){
                        q.push(node(mp[n.v][z], tv));
                        pass_num[n.v]--;
                    }
                }
                
            }
        }
        for(int i = 0; i < vec.size(); i++){
            if(vec[i].size() == 0) continue;
            cout << i << ": ";
            for(auto y:vec[i]){
                cout << y << ", ";
            }
            cout << endl;
        }
        for(int i = 0; i < queries.size(); i++){
            //cout << "queries[i][1]: " << queries[i][1] << endl;
            for(int y = 0; y < vec[queries[i][0]].size(); y++){
                if(vec[queries[i][0]][y] == queries[i][1]) ans[i] = true;
                //cout << vec[queries[i][0]][y] << ", ";
            }
            //cout << endl;
        }
        return ans;
    }
};
```



從後面開始建立

```c++
struct node{
    int v;
    vector<int> pre;
    node(int _v, vector<int>& _pre){
        v = _v;
        pre = _pre;
    }
};
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> pass_num(numCourses, 0);
        vector<bool> ans(queries.size(), false);
        unordered_map<int, vector<int>> mp;
        vector<vector<int>> vec(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
            pass_num[prerequisites[i][0]]++; 
        } 
        stack<node> s;
        vector<int> tmp;
        for(int i=0; i<numCourses; i++){
            if(pass_num[i]==0) s.push(node(i, tmp));
        }
        while(!s.empty()){
            node n = s.top(); s.pop();
            cout << n.v << endl;
            if(mp.count(n.v)){
                vector<int> tv = n.pre;
                tv.push_back(n.v);
                for(int z=0; z<mp[n.v].size(); z++){
                    if(tv.size() > vec[mp[n.v][z]].size()) vec[mp[n.v][z]] = tv;
                    if(pass_num[mp[n.v][z]]!=0){
                        s.push(node(mp[n.v][z], tv));
                        cout << "mp[n.v][z]: " << mp[n.v][z] << endl;
                        for(auto b:tv){
                            cout << b << ", ";
                        }
                        cout << endl;
                        pass_num[n.v]--;
                    }
                }
                
            }
        }
        for(int i = 0; i < vec.size(); i++){
            if(vec[i].size() == 0) continue;
            cout << i << ": ";
            for(auto y:vec[i]){
                cout << y << ", ";
            }
            cout << endl;
        }
        for(int i = 0; i < queries.size(); i++){
            //cout << "queries[i][1]: " << queries[i][1] << endl;
            for(int y = 0; y < vec[queries[i][0]].size(); y++){
                if(vec[queries[i][0]][y] == queries[i][1]) ans[i] = true;
                //cout << vec[queries[i][0]][y] << ", ";
            }
            //cout << endl;
        }
        return ans;
    }
};
```

使用 stack 從最開始建立，試好多次，放棄QQ

```c++
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> pass_num(numCourses, 0);
        vector<bool> ans(queries.size(), false);
        unordered_map<int, vector<int>> mp;
        vector<vector<int>> vec(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            vec[prerequisites[i][0]].push_back(prerequisites[i][1]);
            pass_num[prerequisites[i][1]]++; 
        }
        stack<int> s;
        vector<int> tmp;
        for(int i=0; i<numCourses; i++){
            int cur = i;
            if(vec[cur].size()!=0){
                for(auto v : vec[cur]){
                    s.push(v);
                }
                while(!s.empty()){
                    cur = s.top(); s.pop();
                    if(vec[cur].size()!=0){
                        for(auto v : vec[cur]){
                            s.push(v);
                            vec[i].push_back(v);
                        }
                    }
                }
            }
        }
        
        for(int i = 0; i < vec.size(); i++){
            if(vec[i].size() == 0) continue;
            cout << i << ": ";
            for(auto y:vec[i]){
                cout << y << ", ";
            }
            cout << endl;
        }
        for(int i = 0; i < queries.size(); i++){
            //cout << "queries[i][1]: " << queries[i][1] << endl;
            for(int y = 0; y < vec[queries[i][0]].size(); y++){
                if(vec[queries[i][0]][y] == queries[i][1]) ans[i] = true;
                //cout << vec[queries[i][0]][y] << ", ";
            }
            //cout << endl;
        }
        return ans;
    }
};
```





> 最佳解

這題很多解法，可以直接解或是用、Kahn's Algorithm，tree ，Floyd Warshall 

遞迴的 tree 解法，就 抽象

```c++
class Solution {
public:
    // Performs DFS and returns true if there's a path between src and target
    // and false otherwise.
    bool isPrerequisite(unordered_map<int, vector<int>>& adjList,
                        vector<bool>& visited, int src, int target) {
        visited[src] = 1;

        if (src == target) {
            return true;
        }

        int answer = false;
        for (auto adj : adjList[src]) {
            if (!visited[adj]) {
                answer =
                    answer || isPrerequisite(adjList, visited, adj, target);
            }
        }
        return answer;
    }

    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adjList;
        for (auto edge : prerequisites) {
            adjList[edge[0]].push_back(edge[1]); // 跟我前面寫的一樣
        }

        vector<bool> answer;
        for (auto q : queries) {
            // Reset the visited array for each query.
            vector<bool> visited(numCourses, false);
            answer.push_back(isPrerequisite(adjList, visited, q[0], q[1]));
        }

        return answer;
    }
};
```

 

直接解，因為他是使用 unorder set，所以元素不會重複，但這個寫法不會像是 BFS 與 DFS 重複運算

```c++
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Step 1: Initialize the reachability map
        unordered_map<int, unordered_set<int>> reachable;

        // Step 2: Build direct reachability chains
        for (auto& prereq : prerequisites) {
            reachable[prereq[1]].insert(prereq[0]);
        }

        // Step 3: Propagate reachability to account for indirect prerequisites
        for (int i = 0; i < numCourses; ++i) {
            for (int j = 0; j < numCourses; ++j) {
                if (reachable[j].count(i)) {
                    reachable[j].insert(reachable[i].begin(), reachable[i].end());
                }
            }
        }

        // Step 4: Answer the queries
        vector<bool> result;
        for (auto& query : queries) {
            result.push_back(reachable[query[1]].count(query[0]) > 0);
        }
        return result;
    }
};
```

Kahn's Algorithm

```c++
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adjList;
        vector<int> indegree(numCourses, 0);
        for (auto edge : prerequisites) {
            adjList[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (!indegree[i]) {
                q.push(i);
            }
        }

        // Map from the node as key to the set of prerequisite nodes.
        unordered_map<int, unordered_set<int>> nodePrerequisites;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto adj : adjList[node]) {
                // Add node and prerequisite of node to the prerequisites of adj
                nodePrerequisites[adj].insert(node);
                for (auto prereq : nodePrerequisites[node]) {
                    nodePrerequisites[adj].insert(prereq);
                }

                indegree[adj]--;
                if (!indegree[adj]) {
                    q.push(adj);
                }
            }
        }

        vector<bool> answer;
        for (auto q : queries) {
            answer.push_back(nodePrerequisites[q[1]].contains(q[0]));
        }

        return answer;
    }
};
```







Floyd Warshall (弗洛伊德演算法)是計算點距離演算法，好處是建立一次表格(二維距離表(X到Y距離))之後都可以使用，但是為 O(n^3) 複雜度，，虛擬碼如下

```c++
FloydWarshallAlgorithm(){
  for k in 0 to n - 1{ // 中點
    for i in 0 to n - 1{ // 起點
      for j in 0 to n - 1{ // 終點
          // 目前距離      >      起點到中點再到終點
        if (distance[i][j] > distance[i][k] + distance[k][j]){
          distance[i][j] = distance[i][k] + distance[k][j]
}}}}}
```

起點到終點 > 起點到中點 + 中點到終點

起點到中點 + 中點到終點 就比目前路徑短，算到最後可以得到最小路徑

因為每發現一個新的 中點，就可能會讓路徑變更短，所以要 for 三次

這題使用 bool 代表兩點可不可以連接到

```c++
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        vector<vector<bool>> isPrerequisite(numCourses,
                                            vector<bool>(numCourses, false));
        for (auto edge : prerequisites) {
            isPrerequisite[edge[0]][edge[1]] = true;
        }

        for (int intermediate = 0; intermediate < numCourses; intermediate++) {
            for (int src = 0; src < numCourses; src++) {
                for (int target = 0; target < numCourses; target++) {
                    // If src -> intermediate & intermediate -> target exists
                    // then src -> target will also exist.
                    isPrerequisite[src][target] =
                        isPrerequisite[src][target] ||
                        (isPrerequisite[src][intermediate] &&
                         isPrerequisite[intermediate][target]);
                     // A -> B -> C ; A -> C 一個迴圈可以連接這樣的一組一次，最大數量為 numCourses，只要重複這個動作 numCourses 一定可以完成整個表格
                }
            }
        }

        vector<bool> answer;
        for (auto q : queries) {
            answer.push_back(isPrerequisite[q[0]][q[1]]);
        }

        return answer;
    }
};
```