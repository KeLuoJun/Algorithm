#include <stdio.h>
#include <math.h>
int main()
{
    double r,p,n;
    r=0.07;
    n=10;
    p=pow(1+r,n);
    printf("p=%.6lf\n",p);
    return 0;
}
