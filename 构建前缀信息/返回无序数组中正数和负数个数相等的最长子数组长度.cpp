// 返回无序数组中正数和负数个数相等的最长子数组长度
// 给定一个无序数组arr，其中元素可正、可负、可0
// 求arr所有子数组中正数与负数个数相等的最长子数组的长度
// 测试链接 : https://www.nowcoder.com/practice/545544c060804eceaed0bb84fcd992fb

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
		if(m.find(sum) != m.end()){
			ans = max(ans, i - m[sum]);
		}else{
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
		arr[i] = arr[i] != 0 ? (arr[i] > 0 ? 1 : -1) : 0;
	}
	cout << solve() << endl;
	return 0;
}
