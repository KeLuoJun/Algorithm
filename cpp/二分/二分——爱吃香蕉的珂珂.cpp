// 爱吃香蕉的珂珂
// 珂珂喜欢吃香蕉。这里有 n 堆香蕉，第 i 堆中有 piles[i] 根香蕉
// 警卫已经离开了，将在 h 小时后回来。
// 珂珂可以决定她吃香蕉的速度 k （单位：根/小时)
// 每个小时，她将会选择一堆香蕉，从中吃掉 k 根
// 如果这堆香蕉少于 k 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉
// 珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。
// 返回她可以在 h 小时内吃掉所有香蕉的最小速度 k（k 为整数）
// 测试链接 : https://leetcode.cn/problems/koko-eating-bananas/

#include <iostream>
using namespace std;
int piles[10000];
int n,h;

// 香蕉重量都在piles
// 速度就定成speed
// 返回吃完所有的香蕉，耗费的小时数量
int f(int speed)
{
	int ans = 0;
	for(int i = 0; i < n; i++)
	// (a/b)结果向上取整，如果a和b都是非负数，可以写成(a+b-1)/b
	// "讲解032-位图"讲了这种写法，不会的同学可以去看看
		ans += (piles[i] + speed - 1) / speed;
	return ans;
}

// 时间复杂度O(n * log(max))，额外空间复杂度O(1)
int minEatingSpeed()
{
	int ans;
	// 最小且达标的速度，范围[l,r]
	int l = 1;
	int r = 0;
	for(int i = 0; i < n; i++)
		r = max(r, piles[i]);
	// [l,r]不停二分
	while(l <= r)
	{
		int m = l + ((r - l) >> 2);
		if(f(m) <= h)
		{
			// 达标！
			// 记录答案，去左侧二分
			ans = m;
			// l....m....r
			// l..m-1
			r = m - 1;
		}
		else
			l = m + 1;
	}
	return ans;
}




int main()
{
	cin >> n >> h;
	for(int i = 0; i < n; i++)
		cin >> piles[i];
	int ans = minEatingSpeed();
	cout << ans << endl;
	return 0;
}
