#include <stdio.h>
#include <string.h>
void capitalize(char str[])
{
    str[0] = str[0] - 32;
    for(int i = 1; str[i] != '\0'; i++)
    {
        if(str[i] == ' ' && (str[i+1]>='a' && str[i+1]<='z'))
            str[i+1] = str[i+1] - 32;
    }
}

int main()
{
    char str[101];
    gets(str);
    capitalize(str);
    int len = strlen(str);
    for(int i = 0; i < len; i++)
        printf("%c",str[i]);
    return 0;
}
