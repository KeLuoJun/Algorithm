// 电动车游城市
// 小明的电动车电量充满时可行驶距离为 cnt，每行驶 1 单位距离消耗 1 单位电量，且花费 1 单位时间
// 小明想选择电动车作为代步工具。地图上共有 N 个景点，景点编号为 0 ~ N-1
// 他将地图信息以 [城市 A 编号,城市 B 编号,两城市间距离] 格式整理在在二维数组 paths，
// 表示城市 A、B 间存在双向通路。
// 初始状态，电动车电量为 0。每个城市都设有充电桩，
// charge[i] 表示第 i 个城市每充 1 单位电量需要花费的单位时间。
// 请返回小明最少需要花费多少单位时间从起点城市 start 抵达终点城市 end
// 测试链接 : https://leetcode.cn/problems/DFPeFJ/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Compare{
	bool operator()(const vector<int>&a, const vector<int>&b){
		return a[2] > b[2];
	}
};

int electricCarPlan(vector<vector<int>>& paths, int cnt, int start, int end, vector<int>& charge)
{
	int n = charge.size();
	vector<vector<vector<int>>> graph;
	for(const auto&path : paths){
		graph[path[0]].push_back({path[1], path[2]});
		graph[path[1]].push_back({path[0], path[2]});
	}
	vector<vector<int>> distance(n, vector<int>(cnt + 1, INT_MAX));
	distance[start][0] = 0;
	vector<vector<bool>> visited(n, vector<bool>(cnt + 1, false));
	priority_queue<vector<int>, vector<vector<int>>, Compare> heap;
	heap.push({start, 0, 0});
	while(!heap.empty()){
		int cur = heap.top()[0];
		int power = heap.top()[1];
		int cost = heap.top()[2];
		if(visited[cur][power]){
			continue;
		}
		visited[cur][power] = true;
		if(cur == end){
			return cost;
		}
		if(power < cnt){
			if(!visited[cur][power + 1] && cost + charge[cur] < distance[cur][power + 1]){
				distance[cur][power + 1] = cost + charge[cur];
				heap.push({cur, power + 1, distance[cur][power + 1]});
			}
			
		}
		for(const auto& edge : graph[cur]){
			int nextCity = edge[0];
			int restPower = power - edge[1];
			int nextCost = cost + edge[1];
			if(restPower >= 0 && !visited[nextCity][restPower] && nextCost < distance[nextCity][restPower]){
				distance[nextCity][restPower] = nextCost;
				heap.push({nextCity, restPower, nextCost});
			}
		}
	}
	return -1;
}

int main()
{
	int n, m;
	int cnt, start, end;
	m = 3;
	cin >> n;
	cin >> cnt >> start >> end;
	vector<vector<int>> paths(n, vector<int>(m));
	vector<int> charge(n);

	for(int i = 0; i < n; i++){
		vector<int> tmp;
		int x;
		for(int j = 0; j < m; j++){
			cin >> x;
			tmp.push_back(x);
		}
		paths.push_back(tmp);
	}
	for(int i = 0; i < n; i++){
		cin >> charge[i];
	}
	
	int ans = electricCarPlan(paths, cnt, start, end, charge);
	cout << ans << endl;
	return 0;
}
