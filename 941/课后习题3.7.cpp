#include <stdio.h>
int main()
{
    double h,r,pi = 3.1415926;
    scanf("%lf,%lf",&r,&h);
    
    double l,s,sq,vq,vz;
    l = 2 * pi * r;
    s = pi * r * r;
    sq = 4 * pi * r * r;
    vq = 4.0 / 3.0 * pi * r * r * r;
    vz = s * h;
    
    printf("Բ�ܳ�: l=%.2lf\n",l);
    printf("Բ���: s=%.2lf\n",s);
    printf("Բ������: sq=%.2lf\n",sq);
    printf("Բ�����: vq=%.2lf\n",vq);
    printf("Բ�����: vz=%.2lf\n",vz);
    
    return 0;
}
