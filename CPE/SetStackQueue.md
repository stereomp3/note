[圖論](https://www.srcmini.com/1635.html?fbclid=IwAR37orqfHu5gy3b3Xe-FpkuvOY03_by8RIRb8FyMEyfAKVdbNpn8C3y76EQ#:~:text=%E5%9B%BE%E8%AE%BA(graph%20theory)%E7%AE%97%E6%B3%95%E6%98%AF%E7%9B%B8%E5%BD%93%E6%A0%B8%E5%BF%83%E7%9A%84%E7%AE%97%E6%B3%95,%E5%A4%8D%E6%9D%82%EF%BC%8C%E5%86%85%E5%AE%B9%E4%B9%9F%E6%AF%94%E8%BE%83%E5%A4%9A%E3%80%82)
## Set

#### set特色

> 跟map很像，是他的簡化版

* set 內部資料結構為一顆紅黑樹
   * 內部是有排序的資料。
   * 對於搜尋和插入操作友善( O(logn) )。
* 集合，去除重複的元素，資料由小到大排序。
* 裡面的元素不可修改，但可以插入刪除


#### set用法
> `#include <set>`
1. 創建

   * `set <類型> 變量名;`
   * `set<int> myset{1, 2, 3, 4, 5};  // 集合初始化`
   * 使用矩陣初始化: 
      * `int arr[] = {1, 2, 3, 4, 5};`
      * `std::set<int> myset(arr, arr+5);`

2. 添加或或刪除

   * `myset.insert(var)`
   * `myset.erase(var); // 可傳入值或iterator`
   * `myset.clear();  // 清空set`

3. 獲取

   * `auto it = st.find(變數);  // 取得變量的迭代器` 
   * `變量名.count(變數);  // 變數是否存在set裡面`

vector to set
```c
vector<int> nums;
unordered_set<int> s(begin(nums), end(nums));   // insert every nums[i] in hashset
```



## Stack


#### stack特色

* **stack 和 queue都沒有支援隨機存取，所以沒有begin()和end()，也不能使用iterator做迭代**
* 只能操作頭, 不能取得中間或底下的值(根據LIFO特性)
* 在while迴圈裡面再度創立會讓資料全部清空

#### stack用法
> `include <stack>`

1. 創建

   * `stack <int> mystack;`

2. 添加或或刪除

   * `mystack.push(var)`
   * `mystack.pop();  // 移除最上層元素`
   * `myStack1.swap(myStack2) // 兩個堆疊內容互換` : 這個可以用在清空stack，創立一個空stack，需要清空就交換

3. 獲取

   * `stack.top()  // 取得最上層元素` 


## Queue


#### queue特色

* 能快速的把頭的值拿掉
* 只能操作頭跟尾, 不能取得中間的值(根據FIFO特性)


#### queue用法
> `include <queue>`

1. 創建

   * `queue <int> myqueue;`

2. 添加或或刪除

   * `myqueue.push(var)`
   * `myqueue.pop();  // 移除最上層元素`
   * `myqueue1.swap(myqueue) // 兩個queue內容互換` : 這個可以用在清空queue，創立一個空queue，需要清空就交換

3. 獲取

   * `myqueue.front()()  // 取得最前面的元素(最下面)` 


## bfs
> [詳細說明](https://mycollegenotebook.medium.com/%E5%9C%96%E7%9A%84%E8%B5%B0%E8%A8%AA-bfs-dfs-2-a5dd4b7bd701)、[程式碼](https://blog.csdn.net/weixin_30339457/article/details/97516243?utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_title~default-0.queryctrv4&spm=1001.2101.3001.4242.1&utm_relevant_index=3)、[思想](https://www.w3help.cc/a/202107/353154.html)、[樹的搜尋01](https://shubo.io/iterative-binary-tree-traversal/)、[樹的搜尋02](https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/)

> 重要處理步驟，求出最小路徑(bfs)

```c++
int step = 0;
while(!q.empty()){
    int s = q.size();  // 拿到目前size()，也就是下面有多少個節點要作搜尋
    step += 1;
    while(s--){
        // 使用for迴圈，+1-1走陣列，尋找目標
    }
    q.pop();
}

```

```c++
/*
    參考網站: https://mycollegenotebook.medium.com/%E6%BC%94%E7%AE%97%E6%B3%95-%E5%8B%95%E6%85%8B%E8%A6%8F%E5%8A%83-dp-2-86d9a740791
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define MAX 100

void add_edge(vector<int> vec[],int v1, int v2)
{
	vec[v1].push_back(v2);
}

//BFS搜尋方法
void BFS(vector<int> vec[], int start, int target)
{
	queue<int> q;

	//專門判斷有沒有找到target的變數
	bool flag = false;

	//一開始先push start這個node進來
	q.push(start);

	//進入主要運作區
	while(!q.empty())
	{
		//先pop出來，並檢查是否和target相同
		int node = q.front();
		q.pop();
        cout << "node: " << node << endl;
		if(node == target)
		{
			flag =true;
			cout << "find: " << target << endl;
			break;
		}

		for(auto it : vec[node])
		{
            q.push(it);
            cout << "current position: " << node << "\t";
            cout << "push: " << it << endl;
		}

	}
	if(!flag)
		cout << "can't find：" << target << endl;

}


int main()
{
    //存圖的工具
    vector<int> vec[MAX];
	//建立圖
	add_edge(vec, 1, 2);
	add_edge(vec, 1, 3);
	add_edge(vec, 2, 4);
	add_edge(vec, 2, 5);
	add_edge(vec, 3, 6);
	add_edge(vec, 3, 7);
	add_edge(vec, 4, 8);
	add_edge(vec, 4, 9);

	BFS(vec, 1, 6);

	return 0;
}

```

```sh
node: 1
current position: 1     push: 2
current position: 1     push: 3
node: 2
current position: 2     push: 4
current position: 2     push: 5
node: 3
current position: 3     push: 6
current position: 3     push: 7
node: 4
current position: 4     push: 8
current position: 4     push: 9
node: 5
node: 6
find: 6
```

## dfs
> [詳細說明01](https://mycollegenotebook.medium.com/%E5%9C%96%E7%9A%84%E8%B5%B0%E8%A8%AA-bfs-dfs-1-8a635ea89013)[詳細說明02](https://alrightchiu.github.io/SecondRound/graph-breadth-first-searchbfsguang-du-you-xian-sou-xun.html)

```c++
/*
    參考網站: https://mycollegenotebook.medium.com/%E5%9C%96%E7%9A%84%E8%B5%B0%E8%A8%AA-bfs-dfs-1-8a635ea89013
*/
#include<iostream>
#include<vector>
#include <stack>
using namespace std;
#define MAX 100 //最大100


//因為是有方向性的圖，所以只有單邊的關係
void add_edge(vector<int> vec[], int u, int v)
{
	vec[u].push_back(v);
}

// 深度優先搜尋法
void DFS(vector<int> vec[], int start, int target)
{
	stack<int> s;
	int flag = 0; // 記錄有沒有「子節點」，沒有的話就印出「沒有找到」

	//從start開始，所以要先push進去
	s.push(start);

	while(!s.empty())
	{
		int node = s.top();
		s.pop();  //先pop，然後檢查是否跟目標相同
        cout << "node: " << node << endl;
		//檢查是不是跟目標相同
		if(node == target)
		{
			flag = 1;
			cout << "find: " << target << endl;
			break;
		}
		// 把周圍的node push到stack裡面
		for(auto it : vec[node])
		{
			s.push(it);
			cout << "current position: " << node << "\t";
			cout << "push: " << it << endl;
		}
	}
	if(flag == 0)
		cout << "can't find：" << target << endl;

}

int main()
{
    //用vector來存，點跟點之間的關係
    vector<int> vec[MAX];
	//建立圖
	add_edge(vec, 1, 3);
	add_edge(vec, 1, 2);
	add_edge(vec, 2, 5);
	add_edge(vec, 2, 4);
	add_edge(vec, 3, 7);
	add_edge(vec, 3, 6);
    add_edge(vec, 4, 9);
	add_edge(vec, 4, 8);

	DFS(vec, 1, 6);

	return 0;
}
```

```sh
node: 1
current position: 1     push: 3
current position: 1     push: 2
node: 2
current position: 2     push: 5
current position: 2     push: 4
node: 4
current position: 4     push: 9
current position: 4     push: 8
node: 8
node: 9
node: 5
node: 3
current position: 3     push: 7
current position: 3     push: 6
node: 6
find: 6
```
## priority_queue

> 參考網站: 
>
> https://favtutor.com/blogs/dijkstras-algorithm-cpp
> 
> https://yuihuang.com/dijkstra-algorithm/

```c++
#include<iostream>
#include<climits>
using namespace std;

int miniDist(int distance[], bool Tset[]) // finding minimum distance
{
    int minimum=INT_MAX,ind;
              
    for(int k=0;k<6;k++) 
    {
        if(Tset[k]==false && distance[k]<=minimum)      
        {
            minimum=distance[k];
            ind=k;
        }
    }
    return ind;
}

void DijkstraAlgo(int graph[6][6],int src) // adjacency matrix 
{
    int distance[6]; // // array to calculate the minimum distance for each node                             
    bool Tset[6];// boolean array to mark visited and unvisited for each node
    
     
    for(int k = 0; k<6; k++)
    {
        distance[k] = INT_MAX;
        Tset[k] = false;    
    }
    
    distance[src] = 0;   // Source vertex distance is set 0               
    
    for(int k = 0; k<6; k++)                           
    {
        int m=miniDist(distance,Tset); 
        Tset[m]=true;
        for(int k = 0; k<6; k++)                  
        {
            // updating the distance of neighbouring vertex
            if(!Tset[k] && graph[m][k] && distance[m]!=INT_MAX && distance[m]+graph[m][k]<distance[k])
                distance[k]=distance[m]+graph[m][k];
        }
    }
    cout<<"Vertex\t\tDistance from source vertex"<<endl;
    for(int k = 0; k<6; k++)                      
    { 
        char str=65+k; 
        cout<<str<<"\t\t\t"<<distance[k]<<endl;
    }
}

int main()
{
    int graph[6][6]={
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0}};
    DijkstraAlgo(graph,0);
    return 0;                           
}
```

另一個寫法，根據下面的圖片做最小路徑分析

![image](https://user-images.githubusercontent.com/79676439/171440581-f6c88811-58d5-4e35-b882-5a0f50d516bc.png)

```c++
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define P pair<long long, int>  // <下一個點的距離，下一個點的編號>
#define F first
#define S second
int main(){
    int Start = 0, End = 5;
    priority_queue<P, vector<P>, greater<P> > pq;
    vector < pair<long long, int> > Graph[9]; // 圖形
    Graph[0].push_back({1, 3}); // 點0 到 點1 的距離為 3
    Graph[0].push_back({2, 5}); // 點0 到 點2 的距離為 5
    Graph[1].push_back({2, 2}); // 點1 到 點2 的距離為 2
    Graph[1].push_back({3, 9});
    Graph[1].push_back({4, 11});
    Graph[2].push_back({1, 2});
    Graph[2].push_back({3, 6});
    Graph[3].push_back({4, 2});
    Graph[3].push_back({5, 8});
    Graph[4].push_back({3, 2});
    Graph[4].push_back({5, 5});


    long long dist[6]; // 起點到各點的距離 0 ~ 5
    for(int i = 0; i < 6; i++) dist[i] = 9999;
    dist[Start] = 0;  // 從起點0開始計算，終點是5
    pq.push({0, 0}); // 第一個點開始
    while (!pq.empty()){
        P p = pq.top();
        pq.pop();
        if (dist[p.S] < p.F) continue;
        for (auto nxt: Graph[p.S]){
            if (dist[nxt.F] > dist[p.S] + nxt.S){
                dist[nxt.F] = dist[p.S] + nxt.S; // 存取最近的位置
                pq.push({dist[nxt.F], nxt.F});
            }
        }
        cout << p.S << ": "<< dist[p.S] << endl;
    }
    cout << dist[End] << endl;
}
```


## 參考網址
> 參考網址: [set](https://yuihuang.com/cpp-stl-set/) 、 [std-set](https://shengyu7697.github.io/std-set/) 、 [stack](https://yuihuang.com/cpp-stl-stack/)、 [queue](https://yuihuang.com/cpp-stl-queue/) 、 [priority_queue](https://yuihuang.com/cpp-stl-priority-queue/)