// 分割数组的最大值(画匠问题)
// 给定一个非负整数数组 nums 和一个整数 m
// 你需要将这个数组分成 m 个非空的连续子数组。
// 设计一个算法使得这 m 个子数组各自和的最大值最小。
// 测试链接 : https://leetcode.cn/problems/split-array-largest-sum/

#include <iostream>
using namespace std;
int nums[10000];
int n,k;

// 必须让数组arr每一部分的累加和 <= limit，请问划分成几个部分才够!
// 返回需要的部分数量
int f(int limit)
{
	int ans = 1;
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		if(nums[i] > limit)
			return INT_MAX;
		if(sum + nums[i] > limit)
		{
			ans++;
			sum = nums[i];
		}
		else
			sum += nums[i];
	}
	return ans;
}

// 时间复杂度O(n * log(sum))，额外空间复杂度O(1)
int splitArray()
{
	int sum = 0;
	// [0,sum]二分
	for(int i = 0; i < n; i++)
		sum += nums[i];
	int l = 0,r = sum;
	int m,need,ans;
	// 必须让数组每一部分的累加和 <= m，请问划分成几个部分才够!
	while(l <= r)
	{
		m = l + (r - l) / 2;
		need = f(m);
		if(need <= k)
		{
			// 达标
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
		cin >> nums[i];
	int ans = splitArray();
	cout << ans << endl;
	return 0;
}
