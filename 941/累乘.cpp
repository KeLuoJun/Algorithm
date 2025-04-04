#include <stdio.h>
int main()
{
    int a,b;
    long long sum = 1;
    scanf("%d %d", &a, &b);
    int x = b - a;
    if(x >= 0 && x < 15)
        for(int i = a; i <= b; i++){
            sum *= i;
        }
    printf("%lld",sum);
    return 0;
}
