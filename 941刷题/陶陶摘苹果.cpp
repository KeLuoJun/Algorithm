#include <stdio.h>
int main()
{
    int num[10];
    int h,i;
    
    for(i=0; i<=9; i++)
        scanf("%d",&num[i]);
    scanf("%d",&h);
    
    int count=0;
    for(i=0; i<=9; i++)
    {
        if(num[i] <= (h+30)){
            count++;
        }
    }
    printf("%d",count);
    return 0;
    
}
