#include <stdio.h>
int main()
{
    int n,m,a,b,sum;
    int count;
    while(scanf("%d %d",&n,&m), n!=0 && m!=0)
    {
        int sign = 0;
        count = 0; 
        while(n && m)
        {
            a = n % 10;
            b = m % 10;
            sum = a + b;
            if(sign == 1)
            {
                sum += 1;
                sign = 0;
            }
            if(sum > 9)
            {
                count++;
                sign = 1;
            }
            n /= 10;
            m /= 10;
        }
        printf("%d\n",count);
    }
    return 0;
}

