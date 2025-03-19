#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1001;
int mountains[MAXN];
int n,k;

int f(int num)
{
	int l = 0;
	int r = n - 1;
	int ans = -1;
	while(l <= r)
	{
		int m = l + ((r - l) >> 1);
		if(mountains[m] <= num)
		{
			ans = mountains[m];
			l = m + 1;
		}
		else
			r = m - 1;
	}
	return ans;
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i = 0; i < n; i++)
		scanf("%d",&mountains[i]);
	sort(mountains, mountains + n);
	printf("%d\n",f(k));
	return 0;
}
