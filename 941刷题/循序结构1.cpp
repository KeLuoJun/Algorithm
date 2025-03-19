#include <stdio.h>

int main()

{
	double r;
	scanf("%lf", &r);
	
	double diameter, grith, area;
	diameter = r * 2;   //圆的直径
	grith = 2 * 3.14159 * r;  //圆的周长
	area = 3.14159 * r * r;   //圆的面积
	
	printf("%.4lf %.4lf %.4lf",diameter, grith, area);
	return 0; 

 } 


