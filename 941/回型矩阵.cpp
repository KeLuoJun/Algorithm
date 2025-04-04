#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int count = 2*n-1;
    int i = 0,j = 0,m = 1;
    int num[19][19] = {0};
    for(int k = 1; k <= count; k++)
    {
        if(k % 4 == 1)
        {
            for(int t = 1; t <= n; t++)
            {
                num[i][j++] = m++;
                if(num[i][j] != 0 || j >= n) break;
            }
            j--,i++;
        }
        if(k % 4 == 2)
        {
            for(int t = 1; t <= n; t++)
            {
                num[i++][j] = m++;
                if(num[i][j] != 0 || i >= n) break;
            }
            i--,j--;
        }
        if(k % 4 == 3)
        {
            for(int t = 1; t <= n; t++)
            {
                num[i][j--] = m++;
                if(num[i][j] != 0 || j < 0) break;
            }
            i--,j++;
        }
        if(k % 4 == 0)
        {
            for(int t = 1; t <= n; t++)
            {
                num[i--][j] = m++;
                if(num[i][j] != 0 || i < 0) break;
            }
            i++,j++;
        }
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            printf("%d ",num[i][j]);
        printf("\n");
    }
    return 0;
}
