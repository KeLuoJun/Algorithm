#include <stdio.h>
#include <math.h>
bool pr(int n)    //定义一个判断一个数是否为素数的函数 
{
    int count = 1;
    for(int i = 2; i < n; i++)
    {
        if(n % i == 0){
            count = 0;
            break;
        }
    }
    if(count == 1)
        return true;
    else
        return false;
}

int func(int n)    //定义一个求出一个数的最大素因子的函数 
{
    bool pr(int n);
    int a,b,max = 0;
    for(a = 1; a <= sqrt(n); a++)
    {
        if(n % a == 0){
            b = n / a;
            if(pr(b) && b > max)
                max = b;
            else{
                if(pr(a) && a > max)
                    max = a;
            }
        }
    }
    return max;
}

int main()
{
    int n;
    scanf("%d",&n);
    int num[n],M = 0,result,x;
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&num[i]);
        result = func(num[i]);
        if(result > M){
            M = result;
            x = num[i];
    	}	
    }
    printf("%d",x);
    return 0;
}
