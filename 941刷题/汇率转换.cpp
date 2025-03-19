#include <stdio.h>

double mb_to_usd(long long rmb)
{   
    double exchange_rate = 6.798;
    return rmb / exchange_rate;
}

int main()
{
    long long rmb;
    scanf("%lld",&rmb);
    double usd = mb_to_usd(rmb);
    printf("%.14lf\n",usd);
    return 0;
}

