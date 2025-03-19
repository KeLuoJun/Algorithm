#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int num[2000];
    for(int i = 0; i < n; i ++)
        scanf("%d",&num[i]);
        
    double sum,digit = 0;
    int a,b,t;
    for(int i = 0; i < n; i++)
    {
        sum = 0;
        a = 2;
        b = 1;
        for(int j = 1; j <= num[i]; j++)
        {
            digit =(double) a / b;
            t = a;
            a = a + b;
            b = t;
            sum += digit;
        }
        sum = (int)((sum * 100) + 0.5) / 100.0;
        printf("%.2lf\n",sum);
    }
    return 0;
}
