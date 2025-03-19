#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[19][19],i = 1,j = n;
    int k = 2*n - 1,c = 0;
    for(int t = 1; t <= k; t++)
    {
        if(t <= n)
        {
            while(i <= n && j <= n)
            {
                a[i][j] = ++c;
                i++,j++;
            }
            i = 1,j = n - t;
        }
        else
        {
            i = t - n + 1,j = 1;
            while(i <= n && j <= n)
            {
                a[i][j] = ++c;
                i++,j++;
            }
        }
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            printf("%4d",a[i][j]);
        printf("\n");
    }
    return 0;   
}
