// һ��ʼ1~n��Χ�ϵ����ֶ���0��һ����m��������ÿ�β���Ϊ(l,r,s,e,d)
// ��ʾ��l~r��Χ�����μ�������Ϊs��ĩ��Ϊe������Ϊd������
// �������� : https://www.luogu.com.cn/problem/P4231

#include <iostream>
#include <stdio.h>
using namespace std;
#define MAXN 100000005
#define ll long long

//����ĳ�ʼֵ����Ϊ0 
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
	//����ǰ׺�� 
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
	int l,r,s,e;  //sΪ�Ȳ����е����eΪĩ�����d = (e - s) / (r - l)
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
