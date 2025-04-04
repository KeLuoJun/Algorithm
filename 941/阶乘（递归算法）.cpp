#include <stdio.h>
double fact(int n)
{
    return n == 1 ? 1 : n*fact(n-1);
}

int main()
{
    int m,n,result;
    scanf("%d %d",&m,&n);
    result = fact(n) / (fact(m) * fact(n-m));
    printf("result = %d",result);
    return 0;
}
