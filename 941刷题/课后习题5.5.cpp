#include <stdio.h>
int main()
{
    int n;
    long long num = 1,s = 1;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    {
        num *= i;
        s += num;
    }
    printf("%lld",s);
    return 0;
}
