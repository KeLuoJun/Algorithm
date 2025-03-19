#include <stdio.h>
int main()
{
	int func(int x,int y,int (*p)(int,int));
	int max(int x,int y);
	int min(int x,int y);
	int add(int x,int y);
	int a = 34,b = -21,n;
	printf("please choose 1,2 or 3:");
	scanf("%d",&n);
	if(n == 1) func(a,b,max);
	if(n == 2) func(a,b,min);
	if(n == 3) func(a,b,add);
	return 0;
}

int func(int x,int y, int (*p)(int,int))   //ÖØµã 
{
	int result = (*p)(x,y);
	printf("%d\n",result);
}
int max(int x,int y)
{
	printf("max = ");
	return x > y ? x : y;
}
int min(int x,int y)
{
	printf("min = ");
	return x < y ? x : y;
}
int add(int x,int y)
{
	printf("add = ");
	return x+y;
}
