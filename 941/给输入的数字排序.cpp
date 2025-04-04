#include <stdio.h>
int main()
{
	int n,num[1001],i,j,t;   //定义0~1000个小房间 
	for(i=0; i<=1000; i++)
		num[i] = 0;    //初始每个小房间的值为0
	
	scanf("%d",&n);
	for(i=1; i<=n; i++)
	{
		scanf("%d",&t);    //输入的数的范围为0~1000 
		num[t]++;
	}
	for(i=0; i<=1000; i++)
		for(j=1; j<=num[i]; j++)
			printf("%d ",i);
	return 0;
}
