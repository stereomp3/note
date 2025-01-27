# [Maximum Employees to Be Invited to a Meeting](https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/)

給一個一維 vector favorite，裡面的元素代表哪個人想和哪個人座，找出最大可以坐在同一個圓桌的數量



**Example 1:**

![](https://assets.leetcode.com/uploads/2021/12/14/ex1.png)

```
Input: favorite = [2,2,1,2]
Output: 3
Explanation:
The above figure shows how the company can invite employees 0, 1, and 2, and seat them at the round table.
All employees cannot be invited because employee 2 cannot sit beside employees 0, 1, and 3, simultaneously.
Note that the company can also invite employees 1, 2, and 3, and give them their desired seats.
The maximum number of employees that can be invited to the meeting is 3. 
```



**Example 2:**

```
Input: favorite = [1,2,0]
Output: 3
Explanation: 
Each employee is the favorite person of at least one other employee, and the only way the company can invite them is if they invite every employee.
The seating arrangement will be the same as that in the figure given in example 1:
- Employee 0 will sit between employees 2 and 1.
- Employee 1 will sit between employees 0 and 2.
- Employee 2 will sit between employees 1 and 0.
The maximum number of employees that can be invited to the meeting is 3.
```

**Example 3:**

![img](https://assets.leetcode.com/uploads/2021/12/14/ex2.png)

```
Input: favorite = [3,0,1,4,1]
Output: 4
Explanation:
The above figure shows how the company will invite employees 0, 1, 3, and 4, and seat them at the round table.
Employee 2 cannot be invited because the two spots next to their favorite employee 1 are taken.
So the company leaves them out of the meeting.
The maximum number of employees that can be invited to the meeting is 4.
```



想了很久後，這題我直接看答案

> 最佳解

使用 BFS 去找各種組合，這題難點我覺得就是要找各種組合 (Find all cycles)

![](https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/solutions/6323810/Figures/2127/diff_cases.png)

![](https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/solutions/6323810/Figures/2127/mutual_2nd_testcase.png)

![](https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/solutions/6323810/Figures/2127/mutual_favs.png)

```c++
class Solution {
public:
    int maximumInvitations(vector<int>& fav) {
        int n = fav.size();
        vector<int> inDeg(n, 0), depth(n, 1); // depth 紀錄 node 連線長度
        for (int i{0}; i < n; ++i) inDeg[fav[i]]++; // 紀錄 node 相連數量
        queue<int> q;
        // 這邊有點像是 20250124 使用 Kahn's Algorithm
        for (int i{0}; i < n; ++i) if (inDeg[i] == 0) q.push(i); // 沒有相連的設為 bfs 起點 
        while (!q.empty()) { // BFS 尋找每個節點連線長度
            int cur = q.front(); q.pop();
            int nxt = fav[cur];
            depth[nxt] = max(depth[nxt], depth[cur] + 1);
            if (--inDeg[nxt] == 0) q.push(nxt);
        }
        int maxCycle{0}, twoCycleSum{0};
        for (int i{0}; i < n; ++i) {
            if (inDeg[i] == 0) continue;
            int len{0}, cur = i;
            while (inDeg[cur] != 0) { // 前往下一個點
                inDeg[cur]=0; // 直接為 0 就代表跑一次就夠了
                len++;
                cur = fav[cur];
            }
            if (len == 2) { // 當兩個點相連接，計算兩點長度，關鍵點 (兩點互相指 len 就會為 2)
                twoCycleSum += depth[i] + depth[fav[i]];
            } else { // 直接計算長度
                maxCycle = max(maxCycle, len);
            }
        }
        return max(maxCycle, twoCycleSum);
    }
};
static auto init = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return nullptr; }();
```



