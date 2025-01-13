// 子数组最大累加和
// 给你一个整数数组 nums
// 返回非空子数组的最大累加和
// 测试链接 : https://leetcode.cn/problems/maximum-subarray/

#include <iostream>
using namespace std;
const int MAXN = 1e5 + 1;
int *arr = new int[MAXN];
int n;

int maxSubArray1()
{
	int *dp = new int[n];
	int ans = arr[0];
	dp[0] = arr[0];
	for(int i = 1; i < n; i++){
		dp[i] = max(arr[i], dp[i - 1] + arr[i]);
		ans = max(ans, dp[i]);
	}
	return ans;
}

int maxSubArray2()
{
	int ans = arr[0];
	for(int i = 1, pre = arr[0]; i < n; i++){
		pre = max(arr[i], pre + arr[i]);
		ans = max(ans, pre);
	}
	return ans;
}



int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	
	cout << maxSubArray1() << endl;
	cout << maxSubArray2() << endl;
	return 0;
}
