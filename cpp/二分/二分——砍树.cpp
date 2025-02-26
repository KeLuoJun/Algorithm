#include <iostream>
#include <algorithm>
using namespace std;

long long f(int *tree, int n, long long k)
{
	long long sum = 0;
	for(int i = n-1; i >= 0; i--)
	{
		if(tree[i] - k > 0)	
			sum += tree[i] - k;
		else
			break;
	}
	return sum;
}

int compute(int *tree, int n,long long m)
{
	int l = tree[0];
	int r = tree[n-1];
	long long ans = 0;
	while(l <= r)
	{
		long long k = l + ((r - l) >> 1);
		if(f(tree,n,k) >= m)
		{
			ans = k;
			l = k + 1;
		}
		else
			r = k - 1;
	}
	return ans;
}



int main()
{
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	int *tree = new int[n];
	for(int i = 0; i < n; i++)
		scanf("%d",&tree[i]);
	sort(tree, tree + n);
	int ans = compute(tree,n,m);
	printf("%d\n",ans);
	return 0;
 } 
