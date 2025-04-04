#include <stdio.h>
int main()
{
    int a[10][10] = {0};
    int n;
    for(int i = 0; i < 10; i++)
        a[i][0] = 1;
    while(scanf("%d",&n) != EOF)
    {
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < i+1; j++)
            {
                a[i][j] = a[i-1][j] + a[i-1][j-1];
            }
        }
        for(int i = n-1; i >= 0; i--)
        {
            //打印空格
            for(int j = 0; j < n-i-1; j++)
                printf(" ");
            //打印数字
            for(int j = 0; j < i+1; j++)
            {
                if(j != i)
                    printf("%d ",a[i][j]);
                else
                    printf("%d",a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
