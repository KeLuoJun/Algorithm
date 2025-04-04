#include <stdio.h>
#include <math.h>
int main()
{
    int num;
    scanf("%d",&num);
    long long a,w,m,k;
    for(int i = 1; i <= num/2; i++)
    {
        a = i;
        w = (2*a-1)*(2*a-1)+8*num;
        k = (int)sqrt(w);
        m = k-2*a+1;  //项数的两倍（必须是偶数） 
        if(k*k != w)
            continue;
        else
        {
            if(m%2 != 0)
                continue;
            else
            {
                printf("%d %d\n",i,i+m/2-1);    
            }
        }
    }
    return 0;
}
