// 接雨水
// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水
// 测试链接 : https://leetcode.cn/problems/trapping-rain-water/

#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000];

// 辅助数组的解法（不是最优解）
// 时间复杂度O(n)，额外空间复杂度O(n)
// 提交时改名为trap
void trap1(int n)
{
	int *lmax = new int[n]; //从该位置到左侧的最高位 
	int *rmax = new int[n]; //从该位置到右侧的最高位 
	lmax[0] = arr[0];
	for(int i = 1; i < n; i++)
		lmax[i] = max(lmax[i-1],arr[i]);
	rmax[n-1] = arr[n-1];
	for(int i = n-2; i >= 0; i--)
		rmax[i] = max(rmax[i+1],arr[i]);
	int ans = 0;
	//只需遍历 1......n-1 
	for(int i = 1; i < n-1; i++)
	{
		ans += max(0, min(lmax[i-1], rmax[i+1]) - arr[i]);
	}
	cout << ans << endl;
	delete lmax,rmax;
}

// 双指针的解法（最优解）
// 时间复杂度O(n)，额外空间复杂度O(1)
// 提交时改名为trap
void trap2(int n)
{
	//对于l位置来说，lmax为l左侧的真实最高位 
	//对于r位置来说，rmax为r右侧的真实最高位 
	int lmax = arr[0];
	int rmax = arr[n-1];
	int l = 1;
	int r = n-2;
	int ans = 0;
	while(l <= r)
	{
		//左侧的最高位都低于右侧虚假的最高位
		//即对于l位置来说，右侧目前的最高值不一定是l右侧的总得最高值
		//可能右侧存在比目前rmax还高的数 
		if(lmax <= rmax)
		{
			ans += max(0, lmax - arr[l]);
			lmax = max(lmax, arr[l++]);
		}
		else
		{
			ans += max(0,rmax - arr[r]);
			rmax = max(rmax, arr[r--]);
		}
	}
	cout << ans << endl;
} 


int main()
{
	int n;
	cin >> n;
	for(int i = 0 ; i < n; i++)
		cin >> arr[i];
	//trap1(n);
	trap2(n);
	return 0;
}
