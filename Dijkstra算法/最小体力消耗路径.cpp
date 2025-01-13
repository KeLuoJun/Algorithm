// 最小体力消耗路径
// 你准备参加一场远足活动。给你一个二维 rows x columns 的地图 heights
// 其中 heights[row][col] 表示格子 (row, col) 的高度
// 一开始你在最左上角的格子 (0, 0) ，且你希望去最右下角的格子 (rows-1, columns-1) 
// （注意下标从 0 开始编号）。你每次可以往 上，下，左，右 四个方向之一移动
// 你想要找到耗费 体力 最小的一条路径
// 一条路径耗费的体力值是路径上，相邻格子之间高度差绝对值的最大值
// 请你返回从左上角走到右下角的最小 体力消耗值
// 测试链接 ：https://leetcode.cn/problems/path-with-minimum-effort/

#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
const int N = 101;
// 0:上，1:右，2:下，3:左
int moves[] = {-1, 0, 1, 0, -1};

struct Compare{
	// 根据源点到当前格子的代价来排序 
	bool operator()(const vector<int>&a, const vector<int>&b){
		return a[2] > b[2];
	}
};

int minimumEffortPath(vector<vector<int>>& heights)
{
	// (0,0)源点
	// -> (x,y)
	int n = heights.size();
	int m = heights[0].size();
	// 二维vector数组初始化 
	vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
	distance[0][0] = 0;
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	// 0 : 格子的行
	// 1 : 格子的列
	// 2 : 源点到当前格子的代价
	priority_queue<vector<int>, vector<vector<int>>, Compare> heap;
	heap.push({0, 0, 0});
	while(!heap.empty()){
		int x = heap.top()[0];
		int y = heap.top()[1];
		int c = heap.top()[2];
		heap.pop();
		if(visited[x][y]){
			continue;
		}
		visited[x][y] = true;
		if(x == n - 1 && y == m - 1){
			// 常见剪枝
			// 发现终点直接返回
			// 不用等都结束
			return c;
		}
		
		for(int i = 0; i < 4; i++){
			int nx = x + moves[i];
			int ny = y + moves[i + 1];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]){
				// 与模版的区别 
				int nc = max(c, abs(heights[x][y] - heights[nx][ny]));
				if(nc < distance[nx][ny]){
					distance[nx][ny] = nc;
					heap.push({nx, ny, nc});
				}
			}
		}
	}
	return -1;
}



int main()
{
	int n, m;
	vector<vector<int>> heights;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		vector<int>tmp;
		int x;
		for(int j = 0; j < m; j++){
			cin >> x;
			tmp.push_back(x);
		}
		heights.push_back(tmp);
	}
	int ans = minimumEffortPath(heights);
	cout << ans << endl;
	return 0;
} 
