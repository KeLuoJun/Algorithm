#include <stdio.h>
int main()
{
	int min(int a,int b);
	int n = 6;
	int a[n];
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	int lmax[n],rmax[n];
	lmax[0] = a[0];
	rmax[n-1] = a[n-1];
	for(int i = 1; i < n; i++)
	{
		if(a[i] > a[i-1]) lmax[i] = a[i];
		else lmax[i] = a[i-1];
	}
	for(int i = n-2; i >= 0; i--)
	{
		if(a[i] > a[i+1]) rmax[i] = a[i];
		else rmax[i] = a[i+1];
	}
	int sum = 0;
	for(int i = 1; i < n-1; i++)
	{
		int num = min(lmax[i-1],rmax[i+1]) - a[i];
		if(num < 0) continue;
		else sum += num;
	}
	printf("%d",sum);
	return 0;
} 
int min(int a,int b)
{
	return a>b ? b : a;
}
