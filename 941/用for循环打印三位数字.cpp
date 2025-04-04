#include <stdio.h>
int main()
{
	int i,j,k;
	for(i=1;i<=9;i++){
		for(j=1;j<=9;j++){
			for(k=1;k<=9;k++){
				printf("%d",i*100+j*10+k);
				printf(" ");
			}
	}
}
	return 0;
}
