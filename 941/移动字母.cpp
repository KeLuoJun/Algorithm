#include <stdio.h>
#include <string.h>
int main()
{
	char a[100];
	int i,j;
	scanf("%s",a);
	int len = strlen(a);
	char b = a[0];
	for(j = 0; a[j+1] != '\0'; j++)
		a[j] = a[j+1];
	a[j] = b;
	
	
	for(i = 0; i < len; i++)
		printf("%c",a[i]);
		
	return 0;
}
