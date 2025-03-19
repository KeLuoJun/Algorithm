//calloc 开辟的空间自动初始化为0
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	scanf("%d",&n);
	int *p = (int *)calloc(n,sizeof(int));
	if(p == NULL)
		return -1;
	//输出未赋值前的值
	for(int i = 0; i < n; i++)
		printf("%d ",p[i]);
	printf("\n");
	//赋值
	for(int i = 0; i < n; i++) 
		scanf("%d",p+i);
	for(int i = 0; i < n; i++)
		printf("%d ",p[i]);
	free(p);
	p = NULL;
	return 0;
 } 
