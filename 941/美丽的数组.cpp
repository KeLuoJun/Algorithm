#include <iostream>
using namespace std;
const int MAXN = 1001;
int *arr = new int[MAXN];
int main()
{
	int n;
	scanf("%d",&n);
	int ans = 0;
	for(int i = 0; i< n; i++)
	{
		scanf("%d",&arr[i]);
		if(arr[i] % 42 != 0)
			ans++;
	}	
	printf("%d\n",ans);
	return 0;
} 
