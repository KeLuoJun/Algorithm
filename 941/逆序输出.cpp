#include <stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    int num[n];
    
    for(i=1; i<=n; i++)
        scanf("%d",&num[i]);
    for(i=n; i>0; i--)
        printf("%d",num[i]);
        
    return 0;
}
