// 环形数组的子数组最大累加和
// 给定一个数组nums，长度为n
// nums是一个环形数组，下标0和下标n-1是连在一起的
// 返回环形数组中，子数组最大累加和
// 测试链接 : https://leetcode.cn/problems/maximum-sum-circular-subarray/


#include <iostream>
using namespace std;
const int MAXN = 1e5;
int *nums = new int[MAXN];
int n;

int maxSubarraySumCircular()
{
	int all = nums[0], maxsum = nums[0], minsum = nums[0];
	for(int i = 1, premax = 0, premin = 0; i < n; i++){
		all += nums[i];
		premax = max(nums[i], premax + nums[i]);
		maxsum = max(maxsum, premax);
		premin = min(nums[i], premin + nums[i]);
		minsum = min(minsum, premin);
	}
	return all == minsum ? maxsum : max(maxsum, all - minsum);
}


int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)	
		cin >> nums[i];
	cout << maxSubarraySumCircular() << endl;
	return 0;
}
