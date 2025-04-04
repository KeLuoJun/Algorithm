#include <stdio.h> 
int main()
{
	int n;
	scanf("%d",&n);
	int i, row=1; //row记录行数
	for( ; row<=n; row++ ){
		for( i=1; i<=n-row; i++ ){
			printf(" ");
		} //输出数字前空格，共n-row个
		if(row==1)
			printf("1"); //第一行只有1个数字，单独输出
		else if(row>1&&row<n){
			printf("%d", row); //输出中间某行第一个数字
			for(i=1; i<=2*row-3; i++){
				printf(" ");
			} //输出两数字之间空格，共2row-3项
			printf("%d", row); //输出中间某行第二个数字
		}else if(row==n){
			for(i=1; i<=2*row-1; i++){
				printf("%d", row);
			} //输出第n行数字
		}
		printf("\n");
	}
}
