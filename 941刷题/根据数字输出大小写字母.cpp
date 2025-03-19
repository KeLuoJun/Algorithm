#include <stdio.h>
int main()
{
    int x;
    scanf("%d", &x);
    
    char count1,count2;
    count1 = x + 96;
    count2 = x + 64;
    
    printf("%d:%c%c",x,count1,count2);
    return 0;
}
