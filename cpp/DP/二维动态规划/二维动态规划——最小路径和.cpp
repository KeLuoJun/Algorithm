// 最小路径和
// 给定一个包含非负整数的 m x n 网格 grid
// 请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
// 说明：每次只能向下或者向右移动一步。
// 测试链接 : https://leetcode.cn/problems/minimum-path-sum/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 201;
int m,n;
int grid[MAXN][MAXN];

// 从(0,0)到(i,j)最小路径和
// 一定每次只能向右或者向下
int f1(int i, int j)
{
	if(i == 0 && j == 0)
		return grid[i][j];
	int up = INT_MAX;
	int left = INT_MAX;
	if(i - 1 >= 0)
		up = f1(i - 1, j);
	if(j - 1 >= 0)
		left  = f1(i, j - 1);
	return grid[i][j] + min(up, left);
}
//暴力递归 
int minPathSum1()
{
	return f1(m-1, n-1);
}


//记忆话搜索 
int f2(int i, int j, int dp[][MAXN])
{
	if(dp[i][j] != -1)
		return dp[i][j];
	int ans;
	if(i == 0 && j == 0)
		ans = grid[0][0];
	else
	{
		int up = INT_MAX;
		int left = INT_MAX;
		if(i - 1 >= 0)
			up = f2(i - 1, j, dp);
		if(j - 1 >= 0)
			left = f2(i, j - 1, dp);
		ans = grid[i][j] + min(up, left);
	 } 
	dp[i][j] = ans;
	return ans;
}
int minPathSum2()
{
	int (*dp)[MAXN] = new int[m][MAXN];
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			dp[i][j] = -1;
	return f2(m-1, n-1, dp);
}

// 严格位置依赖的动态规划
int minPathSum3()
{
	int (*dp)[MAXN] = new int[m][MAXN];
	dp[0][0] = grid[0][0];
	for(int i = 1; i < m; i++)
		dp[i][0] = dp[i - 1][0] + grid[i][0];
	for(int j = 1; j < n; j++)
		dp[0][j] = dp[0][j - 1] + grid[0][j];
	for(int i = 1; i < m; i++)
	{
		for(int j = 1; j < n; j++)
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
	}
	return dp[m - 1][n - 1];
}


// 严格位置依赖的动态规划 + 空间压缩技巧
int minPathSum4()
{
	int *dp = new int[n];
	dp[0] = grid[0][0];
	// 先让dp表，变成想象中的表的第0行的数据
	for(int j = 1; j < n; j++)
		dp[j] = dp[j - 1] + grid[0][j];
	for(int i = 1; i < m; i++)
	{
		// i = 1，dp表变成想象中二维表的第1行的数据
		// i = 2，dp表变成想象中二维表的第2行的数据
		// i = 3，dp表变成想象中二维表的第3行的数据
		// ...
		// i = n-1，dp表变成想象中二维表的第n-1行的数据
		dp[0] += grid[i][0];
		for(int j = 1; j < n; j++)
			dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
	}
	return dp[n - 1];
}


int main()
{
	cin >> m >> n;
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			cin >> grid[i][j];
	
	int ans1 = minPathSum1();
	int ans2 = minPathSum2();
	int ans3 = minPathSum3();
	int ans4 = minPathSum4();
	
	cout << ans1 << endl;
	cout << ans2 << endl;
	cout << ans3 << endl;
	cout << ans4 << endl;
	return 0;
} 
