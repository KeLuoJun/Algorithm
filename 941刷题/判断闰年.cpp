#include <stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    if(a%4==0 && a%100!=0)
        printf("Y");
    else
        if(a%400==0)
            printf("Y");
        else
            printf("N");
    return 0;
}
