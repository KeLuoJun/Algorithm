// 水位上升的泳池中游泳
// 在一个 n x n 的整数矩阵 grid 中
// 每一个方格的值 grid[i][j] 表示位置 (i, j) 的平台高度
// 当开始下雨时，在时间为 t 时，水池中的水位为 t
// 你可以从一个平台游向四周相邻的任意一个平台，但是前提是此时水位必须同时淹没这两个平台
// 假定你可以瞬间移动无限距离，也就是默认在方格内部游动是不耗时的
// 当然，在你游泳的时候你必须待在坐标方格里面。
// 你从坐标方格的左上平台 (0，0) 出发
// 返回 你到达坐标方格的右下平台 (n-1, n-1) 所需的最少时间
// 测试链接 : https://leetcode.cn/problems/swim-in-rising-water/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 51;
int moves[] = {-1, 0, 1, 0, -1};


struct Compare{
	bool operator()(const vector<int>&a, const vector<int>&b){
		return a[2] > b[2];
	}
};

int swimInWater(vector<vector<int>>& grid)
{
	int n = grid.size();
	int m = grid[0].size();
	vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
	distance[0][0] = grid[0][0];
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	priority_queue<vector<int>, vector<vector<int>>, Compare> heap;
	heap.push({0, 0, grid[0][0]});
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
			return c;
		}
		for(int i = 0; i < 4; i++){
			int nx = x + moves[i];
			int ny = y + moves[i + 1];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]){
				int nc = max(c, grid[nx][ny]);
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
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		int x;
		vector<int>tmp;
		for(int j = 0; j < m; j++){
			cin >> x;
			tmp.push_back(x);
		}
		grid.push_back(tmp);
	}
	int ans = swimInWater(grid);
	cout << ans << endl;
	return 0;
}
