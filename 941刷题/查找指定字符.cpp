#include <stdio.h>
int main()
{
    char c,s;
    scanf("%c",&c);
    getchar();
    int index = -1,i = -1;
    while((s = getchar()) != '\n')
    {
        i++;
        if(s == c)
            index = i;
    }
    if(index == -1)
        printf("Not Found");
    else
        printf("index = %d",index);
    return 0;
}
