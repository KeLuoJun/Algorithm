#include <stdio.h>
int main()
{
    int m,sum,i,j,x;
    int count = 0;
    scanf("%d",&m);
    int n = m * m * m;
    for(i = (n/m-2*m); i <= n / m; i ++)
    {
    	sum = 0;
    	x = i;
        for(j = 1; j <= m; j++)
        {
        	sum += x;
        	x += 2;
		}
            
        if(sum == n)
            break;
    }
    printf("%d*%d*%d=%d=",m,m,m,n);
    for(int k = i; ; k +=2)
    {
        count ++;
        if(count == m){
        	printf("%d",k);
        	break;
		}
        else
            printf("%d+",k);
        
    }
    return 0;
        
}
