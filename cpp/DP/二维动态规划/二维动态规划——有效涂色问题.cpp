// 有效涂色问题
// 给定n、m两个参数
// 一共有n个格子，每个格子可以涂上一种颜色，颜色在m种里选
// 当涂满n个格子，并且m种颜色都使用了，叫一种有效方法
// 求一共有多少种有效的涂色方法
// 1 <= n, m <= 5000
// 结果比较大请 % 1000000007 之后返回
// 对数器验证

#include <iostream> 
using namespace std;
const int MAXN = 500;
int MOD = 1000000007;

int way1(int n, int m)
{
	int dp[MAXN][MAXN] = {0};
	// dp[i][j]:
	// 一共有m种颜色
	// 前i个格子涂满j种颜色的方法数
	for(int i = 1; i <= n; i++)
		dp[i][1] = m;
	for(int i = 2; i <= n; i++)
	{
		for(int j = 2; j <= m; j++)
		{
			//前i-1个格子已经涂满j种颜色，则弟i个格子能涂j种颜色 
			dp[i][j] = (int)((long)(dp[i - 1][j] * j) % MOD);
			//前i-1个格子涂了j-1个颜色，则弟i个格子能涂剩下的颜色 
			// m - (j - 1) 
			dp[i][j] = (int)((long)(dp[i - 1][j - 1] * (m - j + 1) + dp[i][j]) % MOD);
		}
	}
	return dp[n][m];
}

int f(int *path, bool *set, int i, int n, int m)
{
	if(i == n){
		for(int j = 0; j <= m; j++){
			set[j] = false;
		}
		int colors = 0;
		for(int j = 0; j < n; j++){
			if(!set[path[j]]){
				set[path[j]] = true;
				colors++;
			}
		}
		// 最终n个格子涂色的数量应该在1-m都出现过 
		return colors == m ? 1 : 0;
	}else{
		int ans = 0;
		for(int j = 1; j <= m; j++){
			path[i] = j;
			ans += f(path, set, i + 1, n, m);
		}
		//return ans;
	}
}
// 暴力解法 
int way2(int n, int m)
{
	int path[n];
	bool set[m + 1] = {false};
	return f(path, set, 0, n, m);
}

int main()
{
	int n,m;
	cin >> n >> m;
	//cout << way1(n, m) << endl;
	cout << way2(n, m) << endl;
	return 0;
}
