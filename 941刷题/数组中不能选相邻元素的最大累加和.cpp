// 数组中不能选相邻元素的最大累加和
// 给定一个数组，可以随意选择数字
// 但是不能选择相邻的数字，返回能得到的最大累加和
// 测试链接 : https://leetcode.cn/problems/house-robber/

#include <iostream>
using namespace std;
const int MAXN = 101;
int *nums = new int[MAXN];
int n;

int rob1()
{
	if(n == 1)
		return nums[0];
	if(n == 2)
		return max(nums[0], nums[1]);
	int *dp = new int[n];
	dp[0] = nums[0];
	dp[1] = max(nums[0], nums[1]);
	// dp[i - 1] 表示不要当前位置的数
	// max(nums[i], dp[i - 2] + num[i]) 表示再要当前数字的情况下
	// 是要当前单独这个数字还是当前数字加上之前的最好请况 
	for(int i = 2; i < n; i++){
		dp[i] = max(dp[i - 1], max(nums[i], dp[i - 2] + nums[i]));
	}
	return dp[n - 1];
}

int rob2()
{
	if(n == 1)
		return nums[0];
	if(n == 2)
		return max(nums[0], nums[1]);
	int prepre = nums[0];
	int pre = max(nums[0], nums[1]);
	for(int i = 2, cur; i < n; i++){
		cur = max(pre, max(nums[i], prepre + nums[i]));
		prepre = pre;
		pre = cur;
	}
	return pre;
	
}



int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> nums[i];
	
	cout << rob1() << endl;
	cout << rob2() << endl;
	return 0;
}
