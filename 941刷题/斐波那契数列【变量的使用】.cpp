#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    long long f1 = 1, f2 = 1, f3;
    if(n <= 2)
        printf("%d",f1);
    else
    {
        for(int i = 3; i <= n; i ++)
        {
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
        printf("%d",f3);
    }
    return 0;
}
