#include <stdio.h>
int main()
{
    float x;
    int n;
    scanf("%f %d",&x, &n);
    
    float sum = 1,count = 1;
    for(int i = 1; i <= n; i++){
        count *= x;
        sum += count;
    }
    printf("%.2f",sum);
    return 0;
}
