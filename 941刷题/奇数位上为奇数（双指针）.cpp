//当a[i]为奇数时，i也为奇数
//当a[i]为偶数时，i也为偶数 

#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[100];
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	int even = 0,odd = 1,t;
	while(even<n && odd<n)
	{
		if(a[n-1]%2==0 && a[even]%2!=0)
		{
			t = a[even];
			a[even] = a[n-1];
			a[n-1] = t;
		}
		else if(a[n-1]%2!=0 && a[odd]%2==0)
		{
			t = a[odd];
			a[odd] = a[n-1];
			a[n-1] = t;
		}
		else if(a[even]%2==0)
		{
			even += 2;
		}
		else if(a[odd]%2!=0)
		{
			odd += 2;
		}
	 } 
	 for(int i = 0; i < n; i++)
	 	printf("%d ",a[i]);
	return 0; 
	
}
