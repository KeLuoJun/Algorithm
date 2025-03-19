#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[100];
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	int left = 0,right = n-1;
	while(left < right)
	{
		if(a[left]%2==0 && a[right]%2!=0)
		{
			int t = a[right];
			a[right] = a[left];
			a[left] = t;
			left++;
			right--;
		}
		else
		{
			if(a[left]%2!=0)
				left++;
			if(a[right]%2==0)
				right--;
		}
	}
	for(int i = 0; i < n; i++)
		printf("%d ",a[i]);
	return 0;
}
