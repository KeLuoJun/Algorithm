#include <stdio.h>
int main()
{
	int max(int a,int b);
	int n = 6;
	int a[n];
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	int lmax = a[0],rmax = a[n-1];
	int i = 1,j = n-2;   //左右指针 
	int sum = 0;
	while(i <= j)
	{
		if(lmax <= rmax)   //对于左边的数，左边的最大值是确定的 
		{                  //如果左边确定的最大值比右边不确定的最大值还小，
		                   //则右边指针所指的位置上方的雨水是可以确定的
			sum += max(0,lmax-a[i]);
			lmax = max(lmax,a[i++]);
		}
		else    //对于右边的痣，右边的最大值是确定的 
		{
			sum += max(0,rmax-a[j]);
			rmax = max(rmax,a[j--]);
		}
	}
	printf("%d",sum);
	return 0;
} 
int max(int a,int b)
{
	return a > b ? a : b;
}
