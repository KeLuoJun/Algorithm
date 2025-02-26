// Dijkstra算法模版（Leetcode）
// 网络延迟时间
// 有 n 个网络节点，标记为 1 到 n
// 给你一个列表 times，表示信号经过 有向 边的传递时间
// times[i] = (ui, vi, wi)，表示从ui到vi传递信号的时间是wi
// 现在，从某个节点 s 发出一个信号
// 需要多久才能使所有节点都收到信号
// 如果不能使所有节点收到信号，返回 -1
// 测试链接 : https://leetcode.cn/problems/network-delay-time



/*
                    Dijkstra算法文字描述 
1，distance[i]表示从源点到i点的最短距离，visited[i]表示i节点是否从小根堆弹出过
2，准备好小根堆，小根堆存放记录：(x点，源点到x的距离)，小根堆根据距离组织
3，令distance[源点]=0，(源点，0)进入小根堆
4，从小根堆弹出(u点，源点到u的距离)
   a. 如果visited[u] == true，不做任何处理，重复步骤4
   b. 如果visited[u] == false，令visited[u] = true，u就算弹出过了
      然后考察u的每一条边，假设某边去往v，边权为w
      1）如果visited[v] == false 并且 distance[u] + w < distance[v]
         令distance[v] = distance[u] + w，把(v, distance[u] + w)加入小根堆
      2）处理完u的每一条边之后，重复步骤4
5，小根堆为空过程结束，distance表记录了源点到每个节点的最短距离。
*/

// 时间复杂度 O(m * logm) 
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, k;
int edgeCnt;
vector<vector<int>> times;    // 相当于边 


struct Compare{
	bool operator()(const vector<int>&a, const vector<int>&b){
		return a[1] > b[1];    // 小根堆的比较器 
	}
};

// 动态建图+普通堆的实现
int networkDelayTime1()
{
	vector<vector<vector<int>>> graph(n + 1);    // 建立邻接表 
	for(vector<int> edge : times){
		graph[edge[0]].push_back({edge[1], edge[2]});
	}
	vector<int> distance(n + 1, INT_MAX); // 目前原点到第i个点的最短距离 
	distance[k] = 0;
	vector<bool> visited(n + 1, false);   // 被访问过的点 
	// 0 : 当前节点
	// 1 : 源点到当前点距离
	priority_queue<vector<int>, vector<vector<int>>, Compare> heap;
	heap.push({k, 0});    // 将原点先放入小根堆中 
	while(!heap.empty()){
		int u = heap.top()[0];   // 取与当前节点连接指向的节点 
		heap.pop();
		if(visited[u]){         
			continue;
		}
		visited[u] = true;
		for(const auto& edge : graph[u]){
			int v = edge[0];   // 当前点指向的下一个节点 
			int w = edge[1];
			if(!visited[v] && distance[u] + w < distance[v]){
				distance[v] = distance[u] + w;
				heap.push({v, distance[u] + w});
			}
		}
	}
	int ans = INT_MIN;
	for(int i = 1; i <= n; i++){
		// 如果distance中任存在 INT_MAX，则说明有些点无法到达 
		if(distance[i] == INT_MAX){
			return -1;
		}
		ans = max(ans, distance[i]);
	}	
	return ans;
}


int main()
{
	cin >> n >> edgeCnt >> k;
	int u, v, w;
	for(int i = 0; i < edgeCnt; i++){
		vector<int> tmp;
		cin >> u >> v >> w;
		tmp.push_back(u);
		tmp.push_back(v);
		tmp.push_back(w);
		times.push_back(tmp);
	}
	cout << networkDelayTime1() << endl;
	return 0;
}
