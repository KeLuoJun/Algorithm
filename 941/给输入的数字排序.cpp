#include <stdio.h>
int main()
{
	int n,num[1001],i,j,t;   //����0~1000��С���� 
	for(i=0; i<=1000; i++)
		num[i] = 0;    //��ʼÿ��С�����ֵΪ0
	
	scanf("%d",&n);
	for(i=1; i<=n; i++)
	{
		scanf("%d",&t);    //��������ķ�ΧΪ0~1000 
		num[t]++;
	}
	for(i=0; i<=1000; i++)
		for(j=1; j<=num[i]; j++)
			printf("%d ",i);
	return 0;
}
