// 节点数为n高度不大于m的二叉树个数
// 现在有n个节点，计算出有多少个不同结构的二叉树
// 满足节点个数为n且树的高度不超过m的方案
// 因为答案很大，所以答案需要模上1000000007后输出
// 测试链接 : https://www.nowcoder.com/practice/aaefe5896cce4204b276e213e725f3ea

#include <iostream>
using namespace std;
const int MOD = 1000000007;
const int MAXN = 1000;

int f1(int n, int m, long dp[][MAXN])
{
	if(n == 0) return 1;
	if(m == 0) return 0;
	if(dp[n][m] != -1) return dp[n][m];
	long ans = 0;
	for(int k = 0; k < n; k++)
	{
		ans = (ans + (long)(f1(k, m-1, dp) * f1(n-k-1, m-1, dp) % MOD)) % MOD;
	}
	dp[n][m] = ans;
	return (int)ans;
}
// 二叉树节点数为n
// 高度不能超过m
// 结构数返回
// 记忆化搜索
int compute1(int n, int m)
{
	long (*dp1)[MAXN] = new long[MAXN][MAXN];
	for(int i = 0; i < MAXN; i++)
		for(int j = 0; j < MAXN; j++)
			dp1[i][j] = -1;
	return f1(n, m, dp1);
}



// 严格位置依赖的动态规划
int compute2(int n, int m)
{
	long (*dp2)[MAXN] = new long[MAXN][MAXN];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			dp2[i][j] = 0;
	for(int j = 0; j < m; j++)
		dp2[0][j] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			dp2[i][j] = 0;
			for(int k = 0; k < i; k++)
			// 一共i个节点，头节点已经占用了1个名额
			// 如果左树占用k个，那么右树就占用i-k-1个
				dp2[i][j] = (dp2[i][j] + dp2[k][j - 1] * dp2[i - k - 1][j - 1] % MOD) % MOD;
				
		}
	}
	return (int)dp2[n][m];
}


int main()
{
	int n,m;
	cin >> n >> m;
	int ans1 = compute1(n,m);
	int ans2 = compute2(n,m);
	
	cout << ans1 << endl;
	cout << ans2 << endl;
	return 0;
} 
