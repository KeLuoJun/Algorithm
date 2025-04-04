#include <stdio.h>
int main()
{
    int n,sum;
    scanf("%d",&n);
    for(int i = 1; i < n; i++)
    {
        sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += j;
            if(sum > n) break;
            else if(sum == n && j-i>1)
            {
                printf("%d %d\n",i,j);
                break;
            }
        }
    }
    return 0;
}
