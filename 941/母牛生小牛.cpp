#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int total = 0,t1,t2,t3;
    for(int i = 1; i <= n; i++)
    {
        if(i < 4)
            total = t1 = t2 = t3 = 1;
        else
        {
            total = t1 + t3;
            t3 = t2;
            t2 = t1;
            t1 = total;
        }
    }
    printf("%d\n",total);
    return 0;
}
