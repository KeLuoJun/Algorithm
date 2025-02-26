// 一开始1~n范围上的数字都是0，一共有m个操作，每次操作为(l,r,s,e,d)
// 表示在l~r范围上依次加上首项为s、末项为e、公差为d的数列
// 测试链接 : https://www.luogu.com.cn/problem/P4231

#include <iostream>
#include <stdio.h>
using namespace std;
#define MAXN 100000005
#define ll long long

//数组的初始值必须为0 
ll arr[MAXN] = {0};

void set(int l,int r,int s,int e,int d)
{
	arr[l] += s;
	arr[l + 1] += (d - s);
	arr[r + 1] -= (e + d);
	arr[r + 2] += e;
}

void build(int n)
{
	//两次前缀和 
	for(int i = 1; i <= n; i++)
		arr[i] += arr[i-1];
	for(int i = 1; i <= n; i++)
		arr[i] += arr[i-1];
	
}

int main()
{
	int n;
	scanf("%d",&n);
	int m;
	scanf("%d",&m);
	int l,r,s,e;  //s为等差数列的首项，e为末项，公差d = (e - s) / (r - l)
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d%d%d",&l,&r,&s,&e);
		set(l, r, s, e, (e-s)/(r-l));
	} 
	build(n);
	for(int i = 1; i <= n; i++)
		printf("%lld ",arr[i]);
	return 0;
} 
