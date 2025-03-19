#include <stdio.h>
#include <string.h> 
#define N 1000000
int main()
{
    char s[N];
    scanf("%s",s);
    int len = strlen(s);
    int count;
    for(int i = 0; i < len; i++)
    {
        if(s[i] == s[i+1])
            count ++;
    }
    printf("%d",count);
    return 0;
}
