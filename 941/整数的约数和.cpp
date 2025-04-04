#include <stdio.h>
#include <math.h>
int main()
{
    long long x,a,b;
    scanf("%lld",&x);
 
    long long sum = 0;
    for(a=1; a <= sqrt(x); a++)
        if(x%a==0){
        	b = x/a;
        	if(a != b) 
            	sum += a+b;
            else
            	sum += a;
    }
    
    printf("%lld",sum); 
    return 0;
}
