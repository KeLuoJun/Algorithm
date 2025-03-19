#include <stdio.h>
int main()
{
    double h,sum=0.0;
    scanf("%lf",&h);
    
    sum += h;
    while(h > 0.00001){
    	h = h / 2;
        sum += h*2;
        
    }
    printf("%.8lf",sum);
    return 0;
}
