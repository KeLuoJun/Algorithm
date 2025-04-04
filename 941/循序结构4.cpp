#include <stdio.h>

int main()

{
	int a,b;
	double c,d = 1.9;
	scanf("%d %d", &a, &b);
	c = (double)a + b * 0.1;
	
	int n;
	n = c / d;
	
	printf("%d", n);
	return 0;
}
