//给你一个正整数数组 nums，请你移除 最短 子数组（可以为 空），
//使得剩余元素的 和 能被 p 整除。 不允许 将整个数组都移除。
//请你返回你需要移除的最短子数组的长度，如果无法满足题目要求，返回 -1 。
//测试链接：https://leetcode.cn/problems/make-sum-divisible-by-p/ 

#include <iostream>
using namespace std;
#include <map>
#include <climits>

int min(int a,int b)
{
	return a > b ? b : a;
}

int main()
{
	int n,p;
	cin >> n >> p;
	int *num = new int[n];
	
	int mod = 0;  //整体的模 
	for(int i = 0; i < n; i++)
	{
		cin >> num[i];
		mod = (mod + num[i]) % p;
		// 不是 mod += (mod + num[i]) % p; 
	}
	if(mod == 0) return 0;
	map<int,int> m;
	m[0] = -1;
	int ans = INT_MAX;
	for(int i = 0, cur = 0, find; i < n; i++)
	{
		cur = (cur + num[i]) % p;  //当前位置之前的子数组的模 
		find = cur >= mod ? (cur - mod) : (cur + p - mod);
		// find  = (cur + p - mod) % p;
		if(m.find(find) != m.end())
			ans = min(ans, i - m[find]);
		m[cur] = i; //更新模为cur的最右位置 
	}
	if(ans == n) ans = -1;
	cout << ans << endl;
	delete num; 
	return 0;
}
