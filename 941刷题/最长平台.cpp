#include<stdio.h>
int main()
{
	int n,i,a[1000],len=1,max=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==a[i-1])
		{
			len=len+1;
		}
		else len=1;
		if(len>max)
		{
			max=len;
		}
	}
	printf("%d",max);
}
