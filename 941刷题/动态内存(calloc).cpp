//calloc ���ٵĿռ��Զ���ʼ��Ϊ0
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	scanf("%d",&n);
	int *p = (int *)calloc(n,sizeof(int));
	if(p == NULL)
		return -1;
	//���δ��ֵǰ��ֵ
	for(int i = 0; i < n; i++)
		printf("%d ",p[i]);
	printf("\n");
	//��ֵ
	for(int i = 0; i < n; i++) 
		scanf("%d",p+i);
	for(int i = 0; i < n; i++)
		printf("%d ",p[i]);
	free(p);
	p = NULL;
	return 0;
 } 
