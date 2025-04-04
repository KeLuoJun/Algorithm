#include <stdio.h>
int main()
{
    int a,n,x=1;
    scanf("%d %d",&a,&n);
    for(int i=1; i<=n; i++)
        x=x*a;
    printf("%d",x);
    return 0;
}
