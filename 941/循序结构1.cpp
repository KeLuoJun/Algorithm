#include <stdio.h>

int main()

{
	double r;
	scanf("%lf", &r);
	
	double diameter, grith, area;
	diameter = r * 2;   //Բ��ֱ��
	grith = 2 * 3.14159 * r;  //Բ���ܳ�
	area = 3.14159 * r * r;   //Բ�����
	
	printf("%.4lf %.4lf %.4lf",diameter, grith, area);
	return 0; 

 } 


