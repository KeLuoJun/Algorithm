#include <stdio.h>
#include <math.h>
bool pr(long long n)
{
    int sign = 1;
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            sign = 0;
            break;
        }
    }
    if(sign == 1)
        return true;
    else
        return false;
}

int main()
{
    long long n,a,b,max = 0;
    scanf("%lld",&n);
    for(a = 1; a <= sqrt(n); a++)
    {
        if(n % a == 0){
        	b = n / a;
	        if(pr(b) && b > max)
	            max = b;
	        if(pr(a) && a > max)
	        	max = a;
        }
    }
    printf("%lld",max);
    return 0;
}
