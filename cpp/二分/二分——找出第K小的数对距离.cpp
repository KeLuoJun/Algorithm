// 找出第K小的数对距离
// 数对 (a,b) 由整数 a 和 b 组成，其数对距离定义为 a 和 b 的绝对差值。
// 给你一个整数数组 nums 和一个整数 k
// 数对由 nums[i] 和 nums[j] 组成且满足 0 <= i < j < nums.length
// 返回 所有数对距离中 第 k 小的数对距离。
// 测试链接 : https://leetcode.cn/problems/find-k-th-smallest-pair-distance/

#include <iostream>
#include <algorithm>
using namespace std;
int n,k;
int arr[100000];

// arr中任意两数的差值 <= limit
// 这样的数字配对，有几对？
int f(int limit)
{
	int ans = 0;
	//滑动窗口 
	for(int l = 0,r = 0; l < n; l++)
	{
		while(r + 1 < n && arr[r + 1] - arr[l] <= limit)
			r++;
		// arr[l...r]范围上的数差值的绝对值都不超过limit
		// arr[0...3]
		// 0,1
		// 0,2
		// 0,3
		ans += r - l;
	}
	return ans;
}


// 时间复杂度O(n * log(n) + log(max-min) * n)，额外空间复杂度O(1)
int smallestDistancePair()
{
	sort(arr, arr+n);
	int l = 0;
	int r = arr[n-1] - arr[0];
	int ans = 0;
	// [0, 最大-最小]，不停二分
	while(l <= r)
	{
		int m = l + ((r - l) >> 1);
		// 返回数字对的数量
		int cnt = f(m);
		if(cnt >= k)
		{
			ans = m;
			r = m - 1;
		}
		else
			l = m + 1;
	}
	return ans;
}


int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	int ans = smallestDistancePair();
	cout << ans << endl;
	return 0;
} 
