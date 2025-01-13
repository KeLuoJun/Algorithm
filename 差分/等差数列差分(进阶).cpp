// 一群人落水后求每个位置的水位高度
// 问题描述比较复杂，见测试链接
// 测试链接 : https://www.luogu.com.cn/problem/P5026
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过

#include <iostream>
using namespace std;
#include <map>
#include <climits>
#define MAXN 1000001
const int OFFSET = 30000;
int arr[OFFSET + MAXN + OFFSET];
int n,m;

set(int l, int r, int s, int e, int d)
{
	arr[l + OFFSET] += s;
	arr[l + 1 + OFFSET] += d - s;
	arr[r + 1 + OFFSET] -= d + e;
	arr[r + 2 + OFFSET] += e;
}

void fall(int v,int x)
{
	set(x - 3 * v + 1, x - 2 * v, 1, v, 1);
	set(x - 2 * v + 1, x, v - 1, -v, -1);
	set(x + 1, x + 2 * v, -v + 1, v, 1);
	set(x + 2 * v + 1, x + 3 * v - 1, v - 1, 1, -1);
}

void build()
{
	for(int i = 1 + OFFSET; i <= n + OFFSET; i++)
		arr[i] += arr[i - 1];
	for(int i = 1 + OFFSET; i <= n + OFFSET; i++)
		arr[i] += arr[i - 1];
}

int main()
{
	scanf("%d%d",&m,&n);
	int v,x;
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d",&v,&x);
		fall(v,x);
	}
	build();
	for(int i = 1 + OFFSET; i <= n + OFFSET; i++)
		printf("%d ",arr[i]);
	return 0;
} 
