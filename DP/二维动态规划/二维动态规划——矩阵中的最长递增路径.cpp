// 矩阵中的最长递增路径
// 给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度
// 对于每个单元格，你可以往上，下，左，右四个方向移动
// 你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）
// 测试链接 : https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/

#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1000;
int row,cow;

// 从(i,j)出发，能走出来多长的递增路径，返回最长长度
int f1(int grid[][MAXN], int i, int j)
{
	int next = 0;
	if(i > 0 && grid[i][j] < grid[i - 1][j])
		next = max(next, f1(grid, i-1, j));
	if(i + 1 < row && grid[i][j] < grid[i + 1][j])
		next = max(next, f1(grid, i+1, j));
	if(j > 0 && grid[i][j] < grid[i][j - 1])
		next = max(next, f1(grid, i, j-1));
	if(j + 1 < cow && grid[i][j] < grid[i][j + 1])
		next = max(next, f1(grid, i, j+1));
	return next + 1;
}
int longestIncreasingPath1(int grid[][MAXN], int n, int m)
{
	int ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			ans = max(ans, f1(grid, i, j));
	return ans;
}




int f2(int grid[][MAXN], int i, int j, int dp[][MAXN])
{
	if(dp[i][j] != 0)
		return dp[i][j];
	int next = 0;
	if(i > 0 && grid[i][j] < grid[i - 1][j])
		next = max(next, f2(grid, i-1, j, dp));
	if(i + 1 < row && grid[i][j] < grid[i + 1][j])
		next = max(next, f2(grid, i+1, j, dp));
	if(j < 0 && grid[i][j] < grid[i][j - 1])
		next = max(next, f2(grid, i, j-1, dp));
	if(j + 1 < cow && grid[i][j] < grid[i][j + 1])
		next = max(next, f2(grid, i, j+1, dp));
	dp[i][j] = next + 1;
	return next + 1;
}
int longestIncreasingPath2(int grid[][MAXN], int n, int m)
{
	int ans = 0;
	int (*dp)[MAXN] = new int[MAXN][MAXN];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			dp[i][j] = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			ans = max(ans, f2(grid, i, j, dp));
	return ans;
}


int main()
{
	cin >> row >> cow;
	int (*grid)[MAXN] = new int[MAXN][MAXN];
	for(int i = 0; i < row; i++)
		for(int j = 0; j < cow; j++)
			cin >> grid[i][j];
	int ans1 = longestIncreasingPath1(grid, row, cow);
	int ans2 = longestIncreasingPath2(grid, row, cow);
	
	cout << ans1 << endl;
	cout << ans2 << endl;
	return 0;
} 

