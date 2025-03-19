#include <stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    
    while(n != 0){
        i = n % 10;
        printf("%d ",i);
        n /= 10;
    }
    return 0;
}
