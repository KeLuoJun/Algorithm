#include <stdio.h>
int main()
{
    int x,y;
    scanf("%d",&x);
    int a=x/100;
    int b=(x/10)%10;
    int c=x%10;
    y=a*a*a+b*b*b+c*c*c;
    if(x==y)
        printf("TRUE");
    else
        printf("FLASE");
    return 0;
}
