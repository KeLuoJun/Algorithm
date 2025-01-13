// 字典序最小的拓扑排序
// 要求返回所有正确的拓扑排序中 字典序最小 的结果
// 建图请使用链式前向星方式，因为比赛平台用其他建图方式会卡空间
// 测试链接 : https://www.luogu.com.cn/problem/U107394

// 邻接表 
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20001;
//小根堆 
priority_queue<int, vector<int>, greater<int>>heap;
// 拓扑排序，入度表
int indegree[MAXN];
// 收集拓扑排序的结果
int ans[MAXN];
int n,m;

void build(vector<vector<int>> &graph)
{
	memset(indegree, 0, sizeof(indegree));
	graph.resize(n + 1);
}

// 有拓扑排序返回true
// 没有拓扑排序返回false
void topoSort(vector<vector<int>> &graph)
{
	for(int i = 1; i <= n; i++){
		if(indegree[i] == 0){
			heap.push(i);
		}
	}
	int fill = 0;
	while(!heap.empty()){
		int cur = heap.top();
		heap.pop();
		ans[fill++] = cur;
		for (int next : graph[cur]) {  
            if (--indegree[next] == 0) {  
                heap.push(next);  
            }  
        } 
	}
}

int main()
{
	cin >> n >> m;
	vector<vector<int>> graph;
	build(graph);
	int from,to;
	for(int i = 0; i < m; i++){
		cin >> from >> to;
		graph[from].push_back(to);
		indegree[to]++;
	}
	topoSort(graph);
	for(int i = 0; i < n; i++){
		cout << ans[i] << " ";
	}
	return 0;
 } 
