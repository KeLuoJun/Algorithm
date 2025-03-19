#include <stdio.h>
int main()
{
    char ch;
    scanf("%c", &ch);
    
    int count = 0;
    if(ch >= 'a' && ch <= 'z'){
        count = ch - 96;
    }
    if(ch >= 'A' && ch <= 'Z'){
        count = ch - 64;
    }
    printf("%c:%d",ch,count);
    return 0;
}
