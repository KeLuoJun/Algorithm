#include <stdio.h>
int main()
{
    int n=1,k; 
    scanf("%d",&k);
    
    double Sn=0.0;
    while(Sn < k){
        Sn += 1.0/n;
        n++;
    }
    printf("%d",n-1);
    return 0;
}
