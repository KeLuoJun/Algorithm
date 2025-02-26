#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e6+10;
int a[MAXN];


int lowerbound(int *a,int x)
{
	int l = 0;
	int r = sizeof(a) / sizeof(a[0]);
	int ans = 0;
	while(l <= r)
	{
		int m = l + ((r - l) >> 1);
		if(x <= a[m])
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
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	while(m--)
	{
		int x;
		scanf("%d",&x);
		//int ans = lower_bound(a,a+n,x) - a;
		int ans = lowerbound(a,x);
		if(x != a[ans])
			printf("-1 ");
		else
			printf("%d ",ans+1);
	}
	return 0;
 } 
