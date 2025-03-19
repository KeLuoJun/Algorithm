#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main()
{	system("color 6");

	int second; 
	printf("请输入倒计时时间（单位：S）：");
	scanf("%d",&second); 
	
	while(second>0){
		system("cls");
		printf("%d",second);
		Sleep(1000);
		second=second-1;
	}
	system("cls");
	printf("OVER_倒计时结束");	
	return 0;
 } 
 
