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
		printf("H");
		Sleep(10);
		a++;
	}
	return 0;
}
