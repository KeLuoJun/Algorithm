#include <stdio.h>
int main()
{
    int k;
    scanf("%d",&k);
    int i;
    long long num[k];
    
    num[0]=1;
    num[1]=1;

    for(i=2;i<=k-1;i++){
        num[i] = num[i-1] + num[i-2];
    }
    printf("%lld",num[k-1]);
    return 0;
}
