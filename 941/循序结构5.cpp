#include <stdio.h>

int main()
{
	double x;
	int n;
	scanf("%lf %d", &x, &n);

 	int i,a=1;
	for(i=1; i<=n; i++){   //��x��С�������nλ 
		a *= 10;
	}
	x *= a;    //�õ��µ�x��ֵ 

	int b;
	b = (int) x % 10;  //��ȡx�ĸ�λ�ϵ����� 

 	printf("%d",b);
	return 0;

}
