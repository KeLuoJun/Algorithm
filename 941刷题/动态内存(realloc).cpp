#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	scanf("%d",&n);
	int *p = (int *)calloc(n,sizeof(int));
	if(p == NULL)
		return -1;
	printf("%d\n",p);
	int i;
	for(i = 0; i < n; i++)
		p[i] = i;
	int *ptr = (int *)realloc(p,20*sizeof(int));
	if(ptr == NULL)
		return -1;
	printf("%d\n",ptr);
	for( ; i < 20; i++)
		p[i] = i;
	for(i = 0; i < 20; i++)
		printf("%d ",p[i]);
	free(p);
	p = NULL;
	return 0;
}
