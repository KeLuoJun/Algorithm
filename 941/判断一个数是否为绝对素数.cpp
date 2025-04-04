#include <stdio.h>
#include <math.h>
bool func(int n)
{
    int flag = 1;
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            flag = 0;
            break;
        }
    }
    if(flag == 1)
        return true;
    else
        return false;
}

int main()
{
    int n;
    scanf("%d",&n);
    int num,a,x = n;
    while(x)
    {
        a = x % 10;
        num = num * 10 + a;
        x /= 10;
    }
    if(func(n) && func(num) && n != 1)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
    
}
