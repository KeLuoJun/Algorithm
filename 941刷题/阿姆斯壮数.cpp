#include <stdio.h>
int digist(int x)
{
    int count = 0; 
    while (x != 0)
    {
        ++count;
        x /= 10;
    }
    return count;
}

int power(int x, int y)
{
	int num = 1;
    for(int i = 1; i <= y; i++)
    {
        num *= x;
    }
    return num;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int num,count,total;
    int flag = 0;
    for(int i = n; i <= m; i++)
    {
        count = digist(i);
        int x = i;
        total = 0;
        for(int j = 1; j <= count; j++)
        {
        	num = x % 10;
            num = power(num,count);
            total += num;
            x /= 10;
        }
        if(i == total)
        {
        	printf("%d ",i);
        	flag = 1;
		}
            
    }
    if(flag == 0)
    	printf("none\n");
    return 0;
}
