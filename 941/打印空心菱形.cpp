#include <stdio.h>
int main() {
	int i,j,k;
	scanf("%d",&k); 
	k = k + 1; 
	//打印上半部分 
    for(i=1;i<=k;i++)
	{
		for(j=1;j<=k-i;j++)
			printf(" ");
		printf("*");
		for(j=1;j<=2*i-3;j++)
			printf(" ");
		if(i!=1)
			printf("*");
		printf("\n");
	}
	//打印下半部分 
	for(i=2;i<=k;i++)
	{
		for(j=1;j<=i-1;j++)
			printf(" ");
		printf("*");
		for(j=1;j<=2*(k-i)-1;j++)
			printf(" ");
		if(i!=k)
			printf("*");
		printf("\n");
	}
    return 0;
}
