#include <stdio.h>
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    int a[21][21];
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d",&a[i][j]);
    int flag = 0;
    for(int i = 2; i < m; i++)
    {
        for(int j = 2; j < n; j++)
        {
            if(a[i][j]>a[i-1][j] && a[i][j]>a[i+1][j] && a[i][j]>a[i][j-1] && a[i][j]>a[i][j+1])
            {    
                printf("%d %d %d\n",a[i][j],i,j);
                flag = 1;
            }
        }
    }
    if(flag == 0)
        printf("None\n");
    return 0;
}
