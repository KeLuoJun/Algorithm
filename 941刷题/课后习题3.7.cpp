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
    
    printf("圆周长: l=%.2lf\n",l);
    printf("圆面积: s=%.2lf\n",s);
    printf("圆球表面积: sq=%.2lf\n",sq);
    printf("圆球体积: vq=%.2lf\n",vq);
    printf("圆柱体积: vz=%.2lf\n",vz);
    
    return 0;
}
