#include <stdio.h>
#include <math.h>
int main()
{
	int p; 
    double r5,r3,r2,r1,r0,p1,p2,p3,p4,p5;
    p=1000;
    r5=0.03;
    r3=0.0275;
    r2=0.021;
    r1=0.015;
    r0=0.0035;
    
    p1=p*(1+r5*5);
    p2=p*(1+r2*2)*(1+r3*3);
    p3=p*(1+r3*3)*(1+r2*2);
    p4=p*pow(1+r1,5);
    p5=p*pow(1+r0/4,4*5);
    printf("p1=%lf\n",p1);
    printf("p2=%lf\n",p2);
    printf("p3=%lf\n",p3);
    printf("p4=%lf\n",p4);
    printf("p5=%lf\n",p5);
    return 0;
}
