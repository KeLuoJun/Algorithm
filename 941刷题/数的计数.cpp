#include <stdio.h>
#define N 1000
int main()
{
    int n;
    scanf("%d",&n);
    int h[N];
    for(int i = 1; i <= n; i++)
    {
        h[i] = 1;
        for(int j = 1; j <= i/2; j++)
            h[i] += h[j];
    }
    printf("%d\n",h[n]);
    return 0;
}
