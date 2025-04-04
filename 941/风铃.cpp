#include <stdio.h>
#include <math.h>
bool func(int n)
{
    int flag = 1,a,b,count = 0;
    for(a = 2; a <= sqrt(n); a++)
    {
        if(n%a == 0)
        {
        	count++;
            b = n / a;
            if(a != b)
            {
                flag = 0;
                break;
            }
        }
    }
    if(count == 0)
    	flag = 0;
    if(flag == 1)
        return true;
    else
        return false;
}
int main()
{
    int n;
    scanf("%d",&n);
    int num,max = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&num);
        if(func(num) && num > max)
            max = num;
    }
    printf("%d",max);
    return 0;
}
