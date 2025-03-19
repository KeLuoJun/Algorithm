#include <stdio.h>
int func(int n)
{
    int num = 0;
    int x = n;
    while(x)
    {
        num = num * 10 + x % 10;
        x /= 10;
    }
    return num;
}


int main()
{
    int n,num;
    int count;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    {
    	count = 0;
        scanf("%d",&num);
        while(func(num) != num)
        {
            num = num + func(num);
            count ++;
        }
        if(count <= 8)
            printf("%d\n",count);
        else
            printf("0\n");
    }
    return 0;
}
