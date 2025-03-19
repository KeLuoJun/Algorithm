#include <stdio.h>
#include <math.h>

int main()

{
	double Xa, Ya, Xb, Yb;
	scanf("%lf %lf", &Xa, &Ya);
	scanf("%lf %lf", &Xb, &Yb);
	
	double distance;
	distance = sqrt((Xa-Xb)*(Xa-Xb) + (Ya-Yb)*(Ya-Yb));
	
	printf("%.3lf",distance);
	return 0;

}
