#include <stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    int a=x/100;
    int b=(x/10)%10;
    int c=x%10;
    printf("%d%d%d",c,b,a);
    return 0;
    
}

