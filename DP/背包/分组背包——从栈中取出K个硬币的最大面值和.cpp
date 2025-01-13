// 从栈中取出K个硬币的最大面值和
// 一张桌子上总共有 n 个硬币 栈 。每个栈有 正整数 个带面值的硬币
// 每一次操作中，你可以从任意一个栈的 顶部 取出 1 个硬币，从栈中移除它，并放入你的钱包里
// 给你一个列表 piles ，其中 piles[i] 是一个整数数组
// 分别表示第 i 个栈里 从顶到底 的硬币面值。同时给你一个正整数 k
// 请你返回在 恰好 进行 k 次操作的前提下，你钱包里硬币面值之和 最大为多少
// 测试链接 : https://leetcode.cn/problems/maximum-value-of-k-coins-from-piles/

//非分组背包问题转化为分组背包问题 
#include <iostream>
using namespace std;
const int MAXN = 1001;
int n,k;  //k为操作次数，也即为背包的容量 
int m[MAXN];
int piles[MAXN][MAXN];

// piles是一组一组的硬币
// m是容量，表示一定要进行m次操作
// dp[i][j] : 1~i组上，一共拿走j个硬币的情况下，获得的最大价值
// 1) 不要i组的硬币 : dp[i-1][j]
// 2) i组里尝试每一种方案
// 比如，i组里拿走前k个硬币的方案 : dp[i-1][j-k] + 从顶部开始前k个硬币的价值和
// 枚举每一个k，选出最大值
int compute1()
{
	int dp[n + 1][k + 1];
	for(int j = 0; j <= k; j++)
		dp[0][j] = 0;
	for(int i = 0; i <= n; i++)
		dp[i][0] = 0;
		
	for(int i = 1; i <= n; i++)
	{
		int t = min(k, m[i]);  //求在这一组中操作的最大次数 
		// 每一组的前缀和即为最后在这一组所操作的最终次数 
		// 预处理前缀和，为了加速计算
		int *preSum = new int[t + 1];
		for(int j = 1, sum = 0; j <= t; j++){
			sum += piles[i][j];
			preSum[j] = sum;
		}
		
		// 更新动态规划表
		for(int j = 0; j <= k; j++){
			dp[i][j] = dp[i - 1][j];   //i为前i组，j为当前容量
			// 枚举在当前组中，所有小于当前背包容量的操作数的情况 
			for(int kk = 1; kk <= min(j, t); kk++){
				dp[i][j] = max(dp[i][j], dp[i - 1][j - kk] + preSum[kk]);
			}
		}
	}
	return dp[n][k];
}


int compute2()
{
	int dp[k + 1];
	for(int i = 0; i <= k; i++)
		dp[i] = 0;
		
	for(int i = 1; i <= n; i++)
	{
		int t = min(m[i], k);
		int *preSum = new int[t + 1];
		for(int j = 1, sum = 0; j <= t; j++){
			sum += piles[i][j];
			preSum[j] = sum;
		}
		
		for(int j = k; j >= 0; j--){
			for(int kk = 1; kk <= min(j,t); kk++)
				dp[j] = max(dp[j], dp[j - kk] + preSum[kk]); 
		}
	}
	return dp[k];
} 


int main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++)	
		cin >> m[i];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m[i]; j++)
			cin >> piles[i][j];
	
	int ans1 = compute1();
	int ans2 = compute2();
	
	cout << ans1 << endl;
	cout << ans2 << endl;
	return 0;
}
