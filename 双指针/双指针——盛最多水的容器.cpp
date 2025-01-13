// 盛最多水的容器
// 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
// 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水
// 返回容器可以储存的最大水量
// 说明：你不能倾斜容器
// 测试链接 : https://leetcode.cn/problems/container-with-most-water/

#include <iostream>
#include <algorithm>
using namespace std;
int height[10000];
int n;

// 时间复杂度O(n)，额外空间复杂度O(1)
void maxArea()
{
	int ans = 0;
	int l = 0, r = n-1;
	while(l < r)
	{
		ans = max(ans, min(height[l], height[r]) * (r - l));
		if(height[l] <= height[r]) l++;
		else r--;
	}
	cout << ans << endl;
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> height[i];
	maxArea();
	return 0;
 } 
