#include <stdio.h>
int main()
{
    int num[10001];
    int count = 1;
    for(int i = 1; i <= 10001; i++)
        num[i] = count ++;
        
    int n;
    scanf("%d",&n);
    int sign = n;
    for(int j = 1; j <= n; j++)
    {
        if(j % 2 != 0)
        {
            for(int k = sign - n + 1; k <= sign; k++)
                printf("%d ",num[k]);
            printf("\n");
            sign += n;
        }
        else
        {
            for(int k = sign; k > sign - n; k--)
                printf("%d ",num[k]);
            printf("\n");
            sign += n;
        }
    }
    return 0;
}
