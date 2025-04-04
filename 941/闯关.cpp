#include <cstdio>
using namespace std;
const int MAXN = 1e5;
int *a = new int[MAXN];
int *b = new int[MAXN];

int search(int *arr, int n, int num)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(num < arr[i])
			break;
	}
	return i;
}

int main()
{
	int n,t;
	scanf("%d%d",&n,&t);
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	for(int i = 0; i < n; i++)
	{
		if(i < n - 1)
			scanf("%d",&b[i]);
		if(i > 0)
		{
			a[i] -= b[i - 1];
			b[i] += b[i - 1];
		}			
	}
	int k,cur = 0;
	int *ans = new int[t];
	while(t--)
	{
		scanf("%d",&k);
		ans[cur++] = search(a,n,k);
	}
	for(int i = 0; i < cur; i++)
		printf("%d\n",ans[i]);
	return 0;
} 
