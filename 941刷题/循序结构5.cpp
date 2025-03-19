#include <stdio.h>

int main()
{
	double x;
	int n;
	scanf("%lf %d", &x, &n);

 	int i,a=1;
	for(i=1; i<=n; i++){   //将x的小数点后移n位 
		a *= 10;
	}
	x *= a;    //得到新的x的值 

	int b;
	b = (int) x % 10;  //提取x的个位上的数字 

 	printf("%d",b);
	return 0;

}
