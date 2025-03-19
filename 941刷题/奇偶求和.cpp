#include <stdio.h>
int main()
{
    int m,n,sum=0;
    scanf("%d %d",&m,&n);
    for(int i=m; i<=n; i++)
        if(i%2!=0)
            sum=sum+i;
        else
            continue; 
    printf("%d",sum);
    return 0;
}
