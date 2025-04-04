#include <stdio.h>
#include <string.h>
#define N 101
void capitalize(char str[])
{
	int word = 0; 
	for(int i = 0; str[i] != '\0'; i++)
	{
		if(str[i] == ' ') word = 0;
		else if(word == 0)
		{
			str[i] -= 32;
			word = 1;
		}
	}
}
int main()
{
	char str[N];
	gets(str);
	capitalize(str);
	printf("%s",str);
	return 0;
}
