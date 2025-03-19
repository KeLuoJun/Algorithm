#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[700][700] = {0};
    int i = 1,j = n/2+1;
    a[1][j] = 1;
    for(int t = 2; t <= n*n; t++)
    {
        i--,j++;
        if(i < 1 && j > n)
        {
            i +=2;
            j--;
        }
        else
        {
            if(i < 1) i = n;
            if(j > n) j = 1;
        }
        if(a[i][j] == 0)
            a[i][j] = t;
        else
        {
            i += 2;
            j--;
            a[i][j] = t;
        }
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            printf("%03d ",a[i][j]);
        printf("\n");
    }
    return 0;
}
