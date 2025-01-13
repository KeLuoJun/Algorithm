// 地图分析
// 你现在手里有一份大小为 n x n 的 网格 grid
// 上面的每个 单元格 都用 0 和 1 标记好了其中 0 代表海洋，1 代表陆地。
// 请你找出一个海洋单元格，这个海洋单元格到离它最近的陆地单元格的距离是最大的
// 并返回该距离。如果网格上只有陆地或者海洋，请返回 -1。
// 我们这里说的距离是「曼哈顿距离」（ Manhattan Distance）：
// (x0, y0) 和 (x1, y1) 这两个单元格之间的距离是 |x0 - x1| + |y0 - y1| 。
// 测试链接 : https://leetcode.cn/problems/as-far-from-land-as-possible/

#include <iostream>
using namespace std;
const int MAXN = 1001;
int grid[MAXN][MAXN];
int vis[MAXN][MAXN] = {0};
int n,m;
int Queue[MAXN * MAXN][2];
int l,r;
int moved[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int maxDistance()
{
	l = r = 0;
	int seas = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j] == 1){
				vis[i][j] = 1;
				Queue[r][0] = i;
				Queue[r++][1] = j;
			}else{
				seas++;
			}
		}
	}
	if(seas == 0 || seas == n * m){
		return -1;
	}
	int level = 0;
	while(l < r)
	{
		level++;
		int size = r - l;
		for(int k = 0, x, y, nx, ny; k < size; k++){
			x = Queue[l][0];
			y = Queue[l++][1];
			for(int i = 0; i < 4; i++){
				nx = x + moved[i][0];
				ny = y + moved[i][1];
				if(nx >= 0 && nx < n && ny >=  0 && ny < m && !vis[nx][ny]){
					vis[nx][ny] = 1;
					Queue[r][0] = nx;
					Queue[r++][1] = ny;
				}
			}
		}
	}
	// 题目规定第一层为0，但此解法是从1开始的 
	return level - 1;
}



int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> grid[i][j];
		}
	}
	cout << maxDistance() << endl;
	return 0;
	
}
