#include <stdio.h>
int main()
{
	char ch;
	int k;
	scanf("%d",&k);   //平移的位数 
	while(scanf("%c",&ch), ch != '\n')  //也可写成  ((c = getchar()) != '\n' 
	{
		if(ch >= 'a' && ch <= 'z')
			ch = ((ch - 'a' + k) % 26) + 'a';
		if(ch >= 'A' && ch <= 'Z')
			ch = ((ch - 'A' + k) % 26) + 'A';
			
		
		printf("%c",ch);
	}
	return 0;
 } 
