// 最低票价
// 在一个火车旅行很受欢迎的国度，你提前一年计划了一些火车旅行
// 在接下来的一年里，你要旅行的日子将以一个名为 days 的数组给出
// 每一项是一个从 1 到 365 的整数
// 火车票有 三种不同的销售方式
// 一张 为期1天 的通行证售价为 costs[0] 美元
// 一张 为期7天 的通行证售价为 costs[1] 美元
// 一张 为期30天 的通行证售价为 costs[2] 美元
// 通行证允许数天无限制的旅行
// 例如，如果我们在第 2 天获得一张 为期 7 天 的通行证
// 那么我们可以连着旅行 7 天(第2~8天)
// 返回 你想要完成在给定的列表 days 中列出的每一天的旅行所需要的最低消费
// 测试链接 : https://leetcode.cn/problems/minimum-cost-for-tickets/

#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 366;
int *days = new int[MAXN];
int *costs = new int[3];
int durations[3] = {1, 7, 30};

//暴力递归 
int mincostTickets1(int *days, int n, int *costs, int i)
{
	if(i == n) return 0;
	
	// i下标 : 第days[i]天，有一场旅行
	// i.... 最少花费是多少 
	int ans = INT_MAX;
	// days[i..... 最少花费是多少 
	for(int k = 0, j = i; k < 3; k++)
	{
		while(j < n && days[i] + durations[k] > days[j])
		// 因为方案2持续的天数最多，30天
		// 所以while循环最多执行30次
		// 枚举行为可以认为是O(1)
			j++;
		ans = min(ans, costs[k] + mincostTickets1(days, n, costs, j));
	}
	return ans;
}

int f2(int *days, int n, int *costs, int i, int *dp)
{
	if(i == n) return 0;
	if(dp[i] != INT_MAX) return dp[i];
	
	int ans = INT_MAX;
	for(int k = 0, j = i; k < 3; k++)
	{
		while(j < n && days[i] + durations[k] > days[j])
			j++;
		ans = min(ans, costs[k] + f2(days, n, costs, j, dp));
	}
	dp[i] = ans;
	return ans;
}
// 暴力尝试改记忆化搜索
// 从顶到底的动态规划
int mincostTickets2(int *days, int n, int *costs)
{
	int *dp = new int[n];
	for(int i = 0; i < n; i++)
		dp[i] = INT_MAX;
	int ans = f2(days, n, costs, 0, dp);
	delete[] dp;
	return ans;
}

// 严格位置依赖的动态规划
// 从底到顶的动态规划
int mincostTickets3(int *days, int n, int *costs)
{
	int *dp = new int[MAXN];
	for(int i = 0; i <= n; i++)
		dp[i] = INT_MAX;
	dp[n] = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		for(int k = 0, j = i; k < 3; k++)
		{
			while(j < n && days[i] + durations[k] > days[j])
				j++;
			dp[i] = min(dp[i], costs[k] + dp[j]);
		}
	}
	return dp[0];
}


int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> days[i];
	for(int i = 0; i < 3; i++)
		cin >> costs[i];
	int ans1 = mincostTickets1(days, n, costs, 0);
	int ans2 = mincostTickets2(days, n, costs);
	int ans3 = mincostTickets3(days, n, costs);
	
	cout << ans1 << endl;
	cout << ans2 << endl;
	cout << ans3 << endl;
	return 0;
}
