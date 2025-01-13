// 01背包(模版)
// 给定一个正数t，表示背包的容量
// 有m个货物，每个货物可以选择一次
// 每个货物有自己的体积costs[i]和价值values[i]
// 返回在不超过总容量的情况下，怎么挑选货物能达到价值最大
// 返回最大的价值
// 测试链接 : https://www.luogu.com.cn/problem/P1048

#include <iostream>
using namespace std;
#include <algorithm>
const int MAXN = 1001;
int *value = new int[MAXN];
int *cost = new int[MAXN];

//i代表物品编号，j代表当前的背包容量 
int compute1(int t, int m)
{
	int (*dp)[MAXN] = new int[m + 1][MAXN];
	// 设置dp表的初始状态 
	for(int i = 0; i <= m; i++)
		for(int j = 0; j <= t; j++)
			dp[i][j] = 0;
	for(int i = 1; i <= m; i++)
	{
		for(int j = 0; j <= t; j++)
		{
			// 不要当前物品 
			dp[i][j] = dp[i-1][j];
			// 要当前物品，但是得保证在当前背包容量为j的情况下能容纳当前物品 
			if(j - cost[i] >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + value[i]);
		}
	}
	return dp[m][t];
}


// 空间压缩
int compute2(int t, int m)
{
	int *dp = new int[t+1];
	for(int i = 0; i <= t; i++)
		dp[i] = 0;
	for(int i = 1; i <= m; i++)
	//dp[i][j] = dp[i-1][j];
	//此语句当 j < cost[i] 时不需要更新 
	//相当于保持在二维表中的上一行的值 
	//此时dp[j]的值还未更新，直接不更新，相当于依旧等于dp[i-1][j]的值 
	//相当于dp[i][j] = dp[i-1][j]; 
		for(int j = t; j >= cost[i]; j--)
		//满足条件 
		//因为是依赖左上的格子，而当前行左边未更新的格子相当于左上角的格子，所以从右往左更新
		//j - cost[i] 表示之前的商品花费不超过装下当前商品所需的最大容量 
		// 此时 dp[j - cost[i]] 其实还是 dp[i - 1][j - cost[i]] 处的值，因为还未更新到 
			dp[j] = max(dp[j], dp[j - cost[i]] + value[i]);
	return dp[t];
}

int main()
{
	int t,m; // t为背包容量，m为物品数量 
	cin >> t >> m;
	for(int i = 1; i <= m; i++)
		cin >> cost[i] >> value[i];
	cout << compute1(t,m) << endl;
	cout << compute2(t,m) << endl;
	return 0;
}
