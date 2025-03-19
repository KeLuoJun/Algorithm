#include <stdio.h>
int main()
{
    int n;
    int num[31][31] = {0};
    while(scanf("%d",&n) != EOF)
    {
        for(int i = 1; i <= n; i++)
        {
            num[i][1] = 1;
            for(int j = 2; j <= i; j++)
            {
                num[i][j] = num[i-1][j-1] + num[i-1][j];
            }
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
                printf("%d ",num[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
