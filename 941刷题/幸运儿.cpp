#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[51],count;
    for(int i = 1; i <= n; i++)
        a[i] = i;
    while(n > 2)
    {
        count = 1;
        for(int i = 2; i <= n; i+=2)
        {
            printf("%d ",a[i]);
        }
        for(int i = 1; i <= n; i+=2)
        {
            a[count++] = a[i];
        }
        if(n%2==0)
            n /= 2;
        else
            n = n/2 + 1;
    }
    printf("\n"); 
    for(int i = 1; i <= n; i++)
        printf("%d ",a[i]);
    return 0;
}
