// 表现良好的最长时间段
// 给你一份工作时间表 hours，上面记录着某一位员工每天的工作小时数
// 我们认为当员工一天中的工作小时数大于 8 小时的时候，那么这一天就是 劳累的一天
// 所谓 表现良好的时间段 ，意味在这段时间内，「劳累的天数」是严格 大于 不劳累的天数
// 请你返回 表现良好时间段 的最大长度
// 测试链接 : https://leetcode.cn/problems/longest-well-performing-interval/

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
int arr[MAXN];
int n;

int solve()
{
	int ans = 0;
	map<int, int> m;
	m.insert({0, -1});
	for(int i = 0, sum = 0; i < n; i++){
		sum += arr[i];
		if(sum > 0){
			ans = i + 1;
		}else{
			if(m.find(sum - 1) != m.end())
				ans = max(ans, i - m[sum - 1]);
		}
		if(m.find(sum) == m.end()){
			m.insert({sum, i});
		}
	}
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		arr[i] = arr[i] > 8 ? 1 : -1;
	}
	cout << solve() << endl;
	return 0;
}
