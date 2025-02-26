// 完全背包(模版)
// 给定一个正数t，表示背包的容量
// 有m种货物，每种货物可以选择 任意个
// 每种货物都有体积costs[i]和价值values[i]
// 返回在不超过总容量的情况下，怎么挑选货物能达到价值最大
// 返回最大的价值
// 测试链接 : https://www.luogu.com.cn/problem/P1616


#include <iostream>
using namespace std;
const int MAXN = 10001;
const int MAXT = 1e7 + 1;
int t,m;
int *cost = new int[MAXN];
int *val = new int[MAXN];

// 严格位置依赖的动态规划
// 会空间不够，导致无法通过全部测试用例
int compute1()
{
	int dp[m + 1][t + 1];
	for(int j = 0; j <= t; j++)
		dp[0][j] = 0;
	for(int i = 0; i <= m; i++)
		dp[i][0] = 0;
	
	for(int i = 1; i <= m; i++){
		for(int j = 0; j <= t; j++){
			dp[i][j] = dp[i-1][j];
			if(j - cost[i] >= 0)
			//与01背包的区别在于 不需要用之前i-1的情况来讨论 
				dp[i][j] = max(dp[i][j], dp[i][j - cost[i]] + val[i]);
		}
	}
	return dp[m][t];
}

// 空间压缩 
int compute2()
{
	int dp[t + 1];
	for(int i = 0; i <= t; i++)
		dp[i] = 0;
	for(int i = 1; i <= m; i++){
		// 注意这里相当于
        // for(int j = 0; j <= t; j++)
		//		if(j - cost[i] >= 0) 
		// 从左往右
		// 因为不完全依赖于前i-1种物品的情况 
		//只要当前背包还有容量就能一直放当前物品而不用考虑当前物品的数量 
		// 此时 dp[j - cost[i]] 已经是当前行已经更新过的值 
		for(int j = cost[i]; j <= t; j++){
			dp[j] = max(dp[j], dp[j - cost[i]] + val[i]);
		}
	}
	return dp[t];
 } 

int main()
{
	cin >> t >> m;
	int a,b;  //分别表示采摘第 i 种草药的时间和该草药的价值
	for(int i = 1; i <= m; i++){
		cin >> a >> b;
		cost[i] = a;
		val[i] = b;
	} 
	
	int ans1 = compute1();
	int ans2 = compute2();
	
	cout << ans1 << endl;
	cout << ans2 << endl;
	return 0;
 } 
