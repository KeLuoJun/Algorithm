#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main()
{	system("color 6");

	int second; 
	printf("�����뵹��ʱʱ�䣨��λ��S����");
	scanf("%d",&second); 
	
	while(second>0){
		system("cls");
		printf("%d",second);
		Sleep(1000);
		second=second-1;
	}
	system("cls");
	printf("OVER_����ʱ����");	
	return 0;
 } 
 
