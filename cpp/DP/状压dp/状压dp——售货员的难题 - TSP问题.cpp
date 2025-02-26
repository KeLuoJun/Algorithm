// 售货员的难题 - TSP问题
// 某乡有n个村庄(1<=n<=20)，有一个售货员，他要到各个村庄去售货
// 各村庄之间的路程s(1<=s<=1000)是已知的
// 且A村到B村的路程，与B到A的路大多不同(有向带权图)
// 为了提高效率，他从商店出发到每个村庄一次，然后返回商店所在的村，
// 假设商店所在的村庄为1
// 他不知道选择什么样的路线才能使所走的路程最短
// 请你帮他选择一条最短的路
// 测试链接 : https://www.luogu.com.cn/problem/P1171

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20;
int n;
int graph[MAXN][MAXN];
int dp[1 << MAXN][MAXN];

void build()
{
	for(int i = 0; i < (1 << n); i++){
		for(int j = 0; j < n; j++){
			dp[i][j] = -1;
		}
	}
}

// s : 村里走没走过的状态，1走过了不要再走了，0可以走
// i : 目前在哪个村
int f(int s, int i)
{
	if(s == (1 << n) - 1)
	// n : 000011111
	// 返回 i 到 0 的路程 
		return graph[i][0];
	if(dp[s][i] != -1)
		return dp[s][i];
	int ans = INT_MAX;
	for(int j = 0; j < n; j++){
		// 0...n-1这些村，都看看是不是下一个落脚点
		if((s & (1 << j)) == 0){
			ans = min(ans, graph[i][j] + f(s | (1 << j), j));
		}
	}
	dp[s][i] = ans;
	return ans;
}


int compute()
{
	build();
	// s状态中，1代表已经走过，0代表还未走过 
	return f(1, 0);
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cin >> graph[i][j];
	}
	cout << compute() << endl;
	return 0;
 } 
