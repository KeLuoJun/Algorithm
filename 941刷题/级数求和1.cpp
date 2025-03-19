#include <stdio.h>
int main()
{
    int n,y;
    double s = 0;
    n = 1;
    
    scanf("%d",&y);
    
    while(s <= y){
        s = s + 1.0 / n;
        n++;
    }
    printf("%d",n-1);
    return 0;
}
