#include <stdio.h>
int main()

{
	int n, a, b, c;
	scanf("%d",&n);

	a = n / 100;  //提取百位上的数字
	b = (n / 10) % 10;   //提取十位上的数字
	c = n % 10;    //提取个位上的数字
	
	int sum1, sum2, sum3;
	sum1 = a + b+ c;
	sum2 = sum1 * sum1;
	sum3 = sum2 * sum1;
	
	printf("%d %d %d", sum1, sum2, sum3);
return 0; 

}
