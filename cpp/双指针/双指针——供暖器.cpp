// 供暖器
// 冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。
// 在加热器的加热半径范围内的每个房屋都可以获得供暖。
// 现在，给出位于一条水平线上的房屋 houses 和供暖器 heaters 的位置
// 请你找出并返回可以覆盖所有房屋的最小加热半径。
// 说明：所有供暖器都遵循你的半径标准，加热的半径也一样。
// 测试链接 : https://leetcode.cn/problems/heaters/

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int n,m;
int houses[10000];
int heaters[10000];

// 这个函数含义：
// 当前的地点houses[i]由heaters[j]来供暖是最优的吗？
// 当前的地点houses[i]由heaters[j]来供暖，产生的半径是a
// 当前的地点houses[i]由heaters[j + 1]来供暖，产生的半径是b
// 如果a < b, 说明是最优，供暖不应该跳下一个位置
// 如果a >= b, 说明不是最优，应该跳下一个位置
bool best(int i,int j)
{
	if(j == m-1)
		return true;
	else
	{
		if(abs(houses[i] - heaters[j]) <= abs(houses[i] - heaters[j+1]))
			return true;
		else
			return false;
	}
}


// 时间复杂度O(n * logn)，因为有排序，额外空间复杂度O(1)
void findRadius()
{
	int ans = 0;
	sort(houses, houses + n);
	sort(heaters, heaters + m);
	int i = 0,j = 0;  //i代表房屋  j代表供暖器 
	for( ; i < n; i++)
	{
		while(!best(i,j))
			j++;
		ans = max(ans, abs(houses[i] - heaters[j]));
	}
	cout << ans << endl; 
}

int main()
{
	cin >> n >> m;
	for(int i = 0 ; i < n; i++)
		cin >> houses[i];
	for(int i = 0 ; i < m; i++)
		cin >> heaters[i];
	findRadius();
	return 0;
 } 
