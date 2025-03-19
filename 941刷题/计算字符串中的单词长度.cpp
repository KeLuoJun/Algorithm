#include <stdio.h>
int main()
{
	char ch[1000];
	gets(ch);
	int count = 0,flag = 1;
	for(int i = 0; ch[i] != '\0'; i++)
    {
        if(ch[i] != ' ')
            count++;
        if(ch[i] != ' ' && (ch[i+1] == ' ' || ch[i+1] == '\0'))
        {
            printf("%d ",count);
            count = 0;
        }
    }
    return 0;
}

