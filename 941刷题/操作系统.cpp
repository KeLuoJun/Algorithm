#include <stdio.h>
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int a[100000];
    for(int i = 0; i < n; i++)
        scanf("%d",&a[i]);
        
    int max = 0,total = 0,sum,sign;
    if(n <= k)
    {
        for(int i = 0; i < n; i++)
        {
            if(a[i] > max)
                max = a[i];
        }
    }
    else
    {
        total = n - k + 1;
        for(int i = 0; i < total; i++)
        	max += a[i];
        	
        for(int i = 1; i < n-k; i++)
        {
        	sum = 0;
        	sign = 1;
            for(int j = i; j < i+total; j++)
                sum += a[j];
                
            for(int i = 0; i < n; i++)
            {
                if(sum < a[i])
                {
                    sign = 0;
                    break;
                }
            }
            if(sum < max && sign == 1)
                max = sum;
        }
            
    }
    printf("%d",max);
    return 0;
}
