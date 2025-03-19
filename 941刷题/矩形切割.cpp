#include <stdio.h>
int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	int count = 0,area = 0;
	int a = x,b = y; 
	while(area <= a*b)
	{
		if(x > y)
	{
		x -= y;
		count++;
		area += y*y;
		}
	else
	{
		y -= x;
		count++;
		area += x*x;
		}
	}
	printf("%d",count);
	return 0;
} 

