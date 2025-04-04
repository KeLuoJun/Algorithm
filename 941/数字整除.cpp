#include <stdio.h>
int main()
{
    long long n,m,sum = 0;
    scanf("%lld %lld",&n,&m);
    while(n % m != 0) n--;
    sum = n / m;
    printf("%lld",sum);
    return 0;
}
