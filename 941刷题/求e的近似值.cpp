#include <stdio.h>
long long func(int n)
{
    long long sum = 1;
    for(int i = 1; i <= n; i++)
        sum *= i;
    return sum;
}


int main()
{
    int n;
    double total = 1.0;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    {
        total += 1.0 / func(i);
    }
    printf("%.8lf",total);
    return 0;
}
