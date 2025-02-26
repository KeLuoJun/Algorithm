// 每个人戴不同帽子的方案数
// 总共有 n 个人和 40 种不同的帽子，帽子编号从 1 到 40
// 给你一个整数列表的列表 hats ，其中 hats[i] 是第 i 个人所有喜欢帽子的列表
// 请你给每个人安排一顶他喜欢的帽子，确保每个人戴的帽子跟别人都不一样，并返回方案数
// 由于答案可能很大，请返回它对10^9+7取余后的结果
// 测试链接 : https://leetcode.cn/problems/number-of-ways-to-wear-different-hats-to-each-other

#include <iostream>
using namespace std;
const int MAXN = 41;
const int MOD = 1e9 + 7;
int n, maxx = 0;
int m[MAXN];
int arr[MAXN][MAXN];

// m : 帽子颜色的最大值, 1 ~ m
// n : 人的数量，0 ~ n-1
// i : 来到了什么颜色的帽子
// s : n个人，谁没满足状态就是0，谁满足了状态就是1
// dp : 记忆化搜索的表
// 返回 : 有多少种方法
int f(int *hats, int m, int n, int i, int s, int (*dp)[11])
{
	if(s == (1 << n) - 1)
		return 1;
	// 还有人没满足
	if(i == m + 1)
		return 0;
	if(dp[i][s] != -1)
		return dp[i][s];
	// 可能性1 : i颜色的帽子，不分配给任何人
	int ans = f(hats, m, n, i + 1, s, dp);
	// 可能性2 : i颜色的帽子，分配给可能的每一个人
	int cur = hats[i];
	// 用for循环从0 ~ n-1枚举每个人
	for(int p = 0; p < n; p++){
		// (s & (1 << p)) == 0 这个人之前没有被满足过 
		if((cur & (1 << p)) != 0 && (s & (1 << p)) == 0){
			ans = (ans + f(hats, m, n, i + 1, s | (1 << p), dp)) % MOD;
		}
	}
	dp[i][s] = ans;
	return ans;
}


int compute()
{
	int hats[maxx + 1];
	// 1 ~ m 帽子，能满足哪些人，状态信息 -> int
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m[i]; j++){
			hats[arr[i][j]] |= 1 << i;
		}
	}
	int (*dp)[11] = new int[maxx + 1][11];
	for(int i = 0; i <= maxx; i++){
		for(int j = 0; j <= 11; j++)
			dp[i][j] = -1;
	}
	return f(hats, maxx, n, 1, 0, dp);
} 


int main()
{
	cout << "请输入有多少个人：" ;
	cin >> n;
	for(int i = 0; i < n; i++){
		cout << "请输入第" << i+1 << "个人喜欢帽子的数量：";
		cin >> m[i];
		cout << "请输入第" << i+1 << "个人喜欢帽子的编号："; 
		for(int j = 0; j < m[i]; j++){
			cin >> arr[i][j];
			maxx = max(maxx, arr[i][j]);
		}
	}
	cout << compute() << endl;
	return 0;
 } 
