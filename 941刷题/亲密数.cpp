#include <stdio.h>
#include <math.h>
int main()
{
    int factor(int n);
    int n;
    scanf("%d",&n);
    int num1,num2;
    for(num1 >= 2; num1 <= n; num1++)
    {
        num2 = factor(num1);
        if(num2 > num1 && num1 == factor(num2))
            printf("%d %d ",num1,num2);
    }
    return 0;
    
}

int factor(int n)
{
    int total = 1;
    int a,b;
    for(a = 2; a <= sqrt(n); a++)
    {
        if(n % a == 0)
        {
            b = n / a;
            if(a == b)
                total += a;
            else 
                total += a+b;
        }
    }
    return total;
}
