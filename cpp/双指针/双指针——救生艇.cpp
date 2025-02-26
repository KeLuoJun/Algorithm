// 救生艇
// 给定数组 people
// people[i]表示第 i 个人的体重 ，船的数量不限，每艘船可以承载的最大重量为 limit
// 每艘船最多可同时载两人，但条件是这些人的重量之和最多为 limit
// 返回 承载所有人所需的最小船数
// 测试链接 : https://leetcode.cn/problems/boats-to-save-people/

#include <iostream>
#include <algorithm>
using namespace std;
int n,limit;
int people[10000];

// 时间复杂度O(n * logn)，因为有排序，额外空间复杂度O(1)
void numRescueBoats() 
{
	sort(people,people+n);
	int l = 0,r = n-1;
	int ans = 0;
	while(l <= r)
	{
		int sum = l == r ? people[l] : people[l] + people[r];
		if(sum <= limit)
			l++,r--;
		else
			r--;
		ans++;
	}
	cout << ans << endl;
}

int main()
{
	cin >> n >> limit;
	for(int i = 0; i < n; i++)
		cin >> people[i];
	numRescueBoats();
	return 0;
}
