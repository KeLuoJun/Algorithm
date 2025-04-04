#include <stdio.h>
int main()
{
    int n,count,sign = 1;
    scanf("%d",&n);
    printf("%d=",n);
    while(n != 1)
    {
        for(int i = 2; i <= n; i++)
        {
            count = 0;
            while(n % i == 0)
            {
                count++;
                n /= i;
            }
            if(count != 0)
            {
            	if(sign == 1)
            	{
            		if(count == 1)
            			printf("%d",i);
            		else
            			printf("%d^%d",i,count);
            		sign = 0;
				}
				else
				{
					if(count == 1)
            			printf("*%d",i);
            		else
            			printf("*%d^%d",i,count);
				}		
			}  
        }
    }
    return 0;
}
