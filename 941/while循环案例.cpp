#include <stdio.h>
int main()
{
	int a,b,n;
	scanf("%d",&n);
	a=1;
	while(a<=n){
		b=1;
		while(b<=a){
			printf("%d",a);
			printf(" ");
			b=b+1;
			}
		printf("\n");
		a=a+1;
}
	return 0;
	
 } 
