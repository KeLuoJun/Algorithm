#include <stdio.h>
int main()
{
    long long n,m,x;
    scanf("%lld %lld",&n,&m);
    if(n > 114515) //当n=1时，无法做成m层面包；当n>114514+1时
                             //面包会与面包相邻
        printf("NO");
    else
    {
        x = 2 * n - 1;   //计算有n块面包时所能做成的最大层数的面包
        if(m <= x)       //如果要求的层数少x，则能做成
            printf("YES");
        else
            printf("NO");
    }
    return 0;
}
