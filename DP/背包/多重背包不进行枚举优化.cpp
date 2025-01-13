// 多重背包不进行枚举优化
// 宝物筛选
// 一共有n种货物, 背包容量为t
// 每种货物的价值(v[i])、重量(w[i])、数量(c[i])都给出
// 请返回选择货物不超过背包容量的情况下，能得到的最大的价值
// 测试链接 : https://www.luogu.com.cn/problem/P1776


#include <iostream>
using namespace std;
const int MAXN = 101;
const int MAXM = 1001;
int v[MAXN];
int w[MAXN];
int m[MAXN];
int n,t;


// 严格位置依赖的动态规划
// 时间复杂度O(n * t * 每种商品的平均个数)
int compute1()
{
	// dp[0][....] = 0，表示没有货物的情况下，背包容量不管是多少，最大价值都是0
	int (*dp)[MAXM] = new int[MAXN][MAXM];
	for(int j = 0; j <= t; j++)
		dp[0][j] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= t; j++){
			dp[i][j] = dp[i - 1][j];
			// 枚举当前物品的数量，但是拿的物品的总重量不能超过当前背包容量j 
			for(int k = 1; k <= m[i] && k * w[i] <= j; k++)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + k * v[i]);
		}
	}
	return dp[n][t];
}

// 空间压缩
// 部分测试用例超时
// 因为没有优化枚举
// 时间复杂度O(n * t * 每种商品的平均个数)
int compute2()
{
	int *dp = new int[t + 1];
	for(int i = 0; i <= t; i++)
		dp[i] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = t; j >= 0; j--){
			for(int k = 1; k <= m[i] && k * w[i] <= j; k++)
				dp[j] = max(dp[j], dp[j - k * w[i]] + k * v[i]);
		}
	}
	return dp[t];
}

int main()
{
	cin >> n >> t;
	int vv,ww,mm;
	for(int i = 1; i <= n; i++)
	{
		cin >> vv >> ww >> mm;
		v[i] = vv;
		w[i] = ww;
		m[i] = mm;
	}
	
	int ans1 = compute1();
	int ans2 = compute2();
	
	cout << ans1 << endl;
	cout << ans2 << endl;
	return 0;
}
