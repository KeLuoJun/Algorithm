// 分组背包(模版)
// 给定一个正数m表示背包的容量，有n个货物可供挑选
// 每个货物有自己的体积(容量消耗)、价值(获得收益)、组号(分组)
// 同一个组的物品只能挑选1件，所有挑选物品的体积总和不能超过背包容量
// 怎么挑选货物能达到价值最大，返回最大的价值
// 测试链接 : https://www.luogu.com.cn/problem/P1757

#include <iostream>
using namespace std;
const int MAXN = 1001;
int n,m;   //n为物品数量， m为总重量 
int (*arr)[3] = new int[MAXN][3];


int compute1()
{
	int teams = 1;
	// 组数 
	for(int i = 2; i <= n; i++){
		if(arr[i - 1][2] != arr[i][2])
			teams++;
	}
	// 组的编号1~teams
	// dp[i][j] : 1~i是组的范围，每个组的物品挑一件，容量不超过j的情况下，最大收益
	int (*dp)[MAXN] = new int[MAXN][MAXN];
	// dp[0][....] = 0
	for(int j = 0; j <= m; j++) dp[0][j] = 0;
	// start ... end-1 -> i组
	int start = 1, end = 2; 
	for(int i = 1; start <= n; i++)
	{
		// end为当前组的末尾 
		while(end <= n && arr[end][2] == arr[start][2])
			end++;
		for(int j = 0; j <= m; j++){
			// arr[start...end-1]是当前组，组号一样
			// 其中的每一件商品枚举一遍
			dp[i][j] = dp[i-1][j];
			for(int k = start; k < end; k++){
				// k是组内的一个商品编号
				if(j - arr[k][0] >= 0)
					dp[i][j] = max(dp[i][j], dp[i-1][j - arr[k][0]] + arr[k][1]);
			}
		}
		// start去往下一组的第一个物品
		// 继续处理剩下的组
		start = end++;
	}
	return dp[teams][m];
}

//空间压缩 
int compute2()
{
	int *dp = new int[MAXN];
	for(int i = 0; i <= m; i++)
		dp[i] = 0;
	for(int start = 1, end = 2; start <= n; ){
		while(end <= n && arr[end][2] == arr[start][2])
			end++;
		//从右往左更新 
		for(int j = m; j >= 0; j--){
			for(int k = start; k < end; k++){
				if(j - arr[k][0] >= 0)
					dp[j] = max(dp[j], dp[j - arr[k][0]] + arr[k][1]);
			}
		}
		start = end++;
	}
	return dp[m];
} 



int main()
{
	cin >> m >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < 3; j++)
			cin >> arr[i][j];
	//arr[i][0]表示重量   arr[i][1]表示价值  arr[i][2]表示组号 
	//根据组的大小进行排序 
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n-i; j++)
		{
			if(arr[j][2] >= arr[j + 1][2])
			{
				for(int k = 0; k < 3; k++)
				{
					int t = arr[j][k];
					arr[j][k] = arr[j + 1][k];
					arr[j + 1][k] = t;
				}
			}
		}
	}
	
	int ans1 = compute1();
	int ans2 = compute2();
	
	cout << ans1 << endl;
	cout << ans2 << endl;
	return 0; 
 } 
