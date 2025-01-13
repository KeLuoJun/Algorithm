// 机器人跳跃问题
// 机器人正在玩一个古老的基于DOS的游戏
// 游戏中有N+1座建筑，从0到N编号，从左到右排列
// 编号为0的建筑高度为0个单位，编号为i的建筑的高度为H(i)个单位
// 起初机器人在编号为0的建筑处
// 每一步，它跳到下一个（右边）建筑。假设机器人在第k个建筑，且它现在的能量值是E
// 下一步它将跳到第个k+1建筑
// 它将会得到或者失去正比于与H(k+1)与E之差的能量
// 如果 H(k+1) > E 那么机器人就失去H(k+1)-E的能量值，否则它将得到E-H(k+1)的能量值
// 游戏目标是到达第个N建筑，在这个过程中，能量值不能为负数个单位
// 现在的问题是机器人以多少能量值开始游戏，才可以保证成功完成游戏
// 测试链接 : https://www.nowcoder.com/practice/7037a3d57bbd4336856b8e16a9cafd71

#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[10000];

bool f(int energy,int Max)
{
	// 注意！
	// 如果给的能量值很大，那么后续能量增长将非常恐怖
	// 完全有可能超出long的范围
	// 所以要在遍历时，一定要加入energy >= max的判断
	// 一旦能量超过高度最大值，后面肯定通关了，可以提前返回了
	// 这里很阴
	for(int i = 0; i < n; i++)
	{
		energy += energy - arr[i];
		if(energy >= Max)
			return true;
		if(energy < 0)
			return false;
	}
	return true;
}


// [l,r]通关所需最小能量的范围，不停二分
// max是所有建筑的最大高度
// 时间复杂度O(n * log(max))，额外空间复杂度O(1)
int computer()
{
	int l = 0,r = 0;
	for(int i = 0; i < n; i++)
		r = max(r,arr[i]);
	int Max = r;
	int ans = -1;
	while(l <= r)
	{
		// m中点，此时通关所需规定的初始能量
		int m = l + ((r - l) >> 1);
		if(f(m,Max))
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
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	int ans = computer();
	cout << ans << endl;
	return 0;
 } 
