//malloc 开辟的空间没有初始化，都是随机值 
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	scanf("%d",&n);
	int *p = (int *)malloc(n * sizeof(int));
	if(p == NULL)
		return -1;
	//输出未赋值前的值
	for(int i = 0; i < n; i++)
		printf("%d ",p[i]);
	printf("\n"); 
	//赋值 
	for(int i = 0; i < n; i++)
	{
		scanf("%d",p+i);
	}
	//输出赋值后的值 
	for(int i = 0; i < n; i++)
	{
		printf("%d ",p[i]);
	}
	free(p);  //释放内存空间，但p本身不会被释放 
	p = NULL;
	return 0;
 } 
