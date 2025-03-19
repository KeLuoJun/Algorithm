#include <stdio.h>
#include <windows.h>
int main()
{
	int a,b,n;
	scanf("%d",&n);
	a=0;
	while(a<=n){
		system("cls");
		
		b=1;
		while(b<=a){
			printf(" ");
			b++;
		}
		printf(" o\n");
		
		b=1;
		while(b<=a){
			printf(" ");
			b++;
		}
		printf("<H>\n");
		
		b=1;
		while(b<=a){
			printf(" ");
			b++;
		}
		printf("I I\n");
		
		Sleep(50);
		a++; 
	}
	return 0;
	
}
