#include <stdio.h>
int main()
{
    int n,m;
    int avg,sum = 0,count = 0;
    
    while(scanf("%d%d",&n,&m) != EOF)
    {
        for(int i = 2; i <= 2*n; i += 2)
        {
            sum += i;
            count++;
            if(count == m)
            {
                avg = sum / m;
                sum = 0;
                count = 0;
                printf("%d ",avg);
            }
            else
            {
                if(count != m && i == 2*n)
                {
                    avg = sum / count;
                    sum = 0;
                	count = 0;
                    printf("%d ",avg);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
