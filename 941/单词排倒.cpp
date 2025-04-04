#include <stdio.h>
#include <string.h>
int main()
{
    char a[101];
    gets(a);
    int len = strlen(a);
    char b[100][101];
    int count1 = 0,count2 = 0;
    for(int i = 0; i < len; i++)
    {
        if(a[i] != ' ')
        {
        	b[count1][count2] = a[i];
        	count2++;
		}
            
        if(a[i] != ' ' && (a[i+1] == ' ' || a[i+1] == '\0'))
        {
            count1++;
            count2 = 0;
        }
    }
    count1 -= 1;
    for(int i = count1; i >= 0; i--)
    {
        printf("%s ",b[i]);
    }
    
    return 0;
}
