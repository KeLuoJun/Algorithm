// 同时运行N台电脑的最长时间
// 你有 n 台电脑。给你整数 n 和一个下标从 0 开始的整数数组 batteries
// 其中第 i 个电池可以让一台电脑 运行 batteries[i] 分钟
// 你想使用这些电池让 全部 n 台电脑 同时 运行。
// 一开始，你可以给每台电脑连接 至多一个电池
// 然后在任意整数时刻，你都可以将一台电脑与它的电池断开连接，并连接另一个电池，你可以进行这个操作 任意次
// 新连接的电池可以是一个全新的电池，也可以是别的电脑用过的电池
// 断开连接和连接新的电池不会花费任何时间。
// 注意，你不能给电池充电。
// 请你返回你可以让 n 台电脑同时运行的 最长 分钟数。
// 测试链接 : https://leetcode.cn/problems/maximum-running-time-of-n-computers/

#include <iostream>
#include <algorithm>
using namespace std;

// 让num台电脑共同运行time分钟，能不能做到
bool f(int *arr, int num, int time)
{
	long sum = 0;
	for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		//直接让这块电池单独为一个电脑供电即可 
		if(arr[i] >= time)
			num--;
		else
		// x <= time，是碎片电池
			sum += arr[i];
	}
	if(sum >= (long)(num * time))
		return true;
	else
	 	return false;
}

// 单纯的二分答案法
// 提交时把函数名改为maxRunTime
// 时间复杂度O(n * log(sum))，额外空间复杂度O(1)
int maxRunTime1(int *arr,int n,int num)
{
	long sum = 0;
	for(int i = 0; i < n; i++)
		sum += arr[i];
	long l = 0,r = sum;
	int ans = 0;
	while(l <= r)
	{
		// m中点，让num台电脑共同运行m分钟，能不能做到
		int m = l + ((r - l) >> 1);
		if(f(arr,num,m))
		{
			ans = m;
			l = m + 1;
		}
		else
			r = m - 1;
	}
	return ans;
}


// 二分答案法 + 增加分析(贪心)
// 提交时把函数名改为maxRunTime
// 时间复杂度O(n * log(max))，额外空间复杂度O(1)
int maxRunTime2(int *arr, int n, int num)
{
	long sum = 0;
	int Max = 0;
	for(int i = 0; i < n; i++)
	{
		sum += arr[i];
		Max = max(Max, arr[i]);
	}
	// 所有电池的最大电量是max
	// 如果此时sum > (long) max * num，
	// 说明 : 最终的供电时间一定在 >= max，而如果最终的供电时间 >= max
	// 说明 : 对于最终的答案X来说，所有电池都是课上讲的"碎片拼接"的概念
	// 那么寻找 ? * num <= sum 的情况中，尽量大的 ? 即可
	// 即sum / num
	if(sum >= (long)(Max * num))
		return sum / num;
	// 最终的供电时间一定在 < max范围上
	// [0, sum]二分范围，可能定的比较粗，虽然不影响，但毕竟是有点慢
	// [0, max]二分范围！更精细的范围，二分次数会变少
	int l = 0,r = Max;
	int ans = 0;
	while(l <= r)
	{
		int m = l + ((r - l) >> 1);
		if(f(arr,num,m))
		{
			ans = m;
			l = r + 1;
		}
		else
			r = m - 1;
	}
	return ans;
} 


int main()
{
	int n,num;
	cin >> n >> num;
	int *arr = new int[n];
	for(int i = 0 ; i < n; i++)
		cin >> arr[i];
	//int ans = maxRunTime1(arr,n,num);
	int ans = maxRunTime2(arr,n,num);
	cout << ans << endl;
	delete arr;
	return 0;
} 
