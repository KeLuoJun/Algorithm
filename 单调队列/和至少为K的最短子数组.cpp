// 和至少为K的最短子数组
// 给定一个数组arr，其中的值有可能正、负、0
// 给定一个正数k
// 返回累加和>=k的所有子数组中，最短的子数组长度
// 测试链接 : https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/

#include <iostream>
using namespace std;
typedef long long ll;
const int N = 100001;
int n, k;
int arr[N];
ll sum[N];
int dq[N];
int h,t;

int shortestSubarray()
{
	// sum[0] : 前0个数的前缀和
	// sum[i] : 前i个数的前缀和
	sum[0] = 0;
	for(int i = 0; i < n; i++){
		// [3,4,5]
		//  0 1 2
		// sum[0] = 0
		// sum[1] = 3
		// sum[2] = 7
		// sum[3] = 12
		sum[i + 1] = sum[i] + arr[i];
	}
	h = t = 0;
	int ans = INT_MAX;
	for(int i = 0; i <= n; i++){
		// 前0个数前缀和
		// 前1个数前缀和
		// 前2个数前缀和
		// ...
		// 前n个数前缀和
		while(h != t && sum[i] - sum[dq[h]] >= k){
			// 如果当前的前缀和 - 头前缀和，达标！
			ans = min(ans, i - dq[h++]);
		}
		// 前i个数前缀和，从尾部加入
		// 小 大
		while(h != t && sum[dq[t - 1]] >= sum[i]){
			t--;
		}
		dq[t++] = i;
	}
	return ans != INT_MAX ? ans : -1;
}


int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int ans = shortestSubarray();
	cout << ans << endl;
	return 0;
}
