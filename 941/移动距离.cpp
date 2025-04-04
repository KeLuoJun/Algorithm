#include <stdio.h>
#include <math.h>
int main()
{
    int w,m,n;
    scanf("%d%d%d",&w,&m,&n);
    int x1,x2,y1,y2,len = 0;
    y1 = m / w;
    y2 = n / w;
    if(y1 % 2 == 0)
    {
        x1 = m % w;
        if(x1 == 0)
            x1 = 1;
        else
            x1 = w - x1 + 1;
    }
    else
    {
        x1 = m % w;
        if(x1 == 0)
            x1 = w;
    }
    if(y2 % 2 == 0)
    {
        x2 = n % w;
        if(x2 == 0)
            x2 = 1;
        else
            x2 = w - x2 + 1;
    }
    else
    {
        x2 = n % w;
        if(x2 == 0)
            x2 = w;
    }
    len = abs(y1-y2) + abs(x1-x2);
    printf("%d",len);
    return 0;
}
