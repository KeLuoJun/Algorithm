#include <stdio.h>
int main()

{
	int n, a, b, c;
	scanf("%d",&n);

	a = n / 100;  //��ȡ��λ�ϵ�����
	b = (n / 10) % 10;   //��ȡʮλ�ϵ�����
	c = n % 10;    //��ȡ��λ�ϵ�����
	
	int sum1, sum2, sum3;
	sum1 = a + b+ c;
	sum2 = sum1 * sum1;
	sum3 = sum2 * sum1;
	
	printf("%d %d %d", sum1, sum2, sum3);
return 0; 

}
