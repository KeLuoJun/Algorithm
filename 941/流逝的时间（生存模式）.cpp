#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    
    int num[t];
    for(int i = 0; i < t; i ++)
    {
        scanf("%d",&num[i]);
    }
    
    for(int i = 0; i < t; i ++)
    {
        if(num[i] >= 0 && num[i] < 12000)
            printf("day\n");
        if(num[i] >= 12000 && num[i] < 13800)
            printf("sunset\n");
        if(num[i] >= 13800 && num[i] < 22200)
            printf("night\n");
        if(num[i] >= 22200 && num[i] < 24000)
            printf("sunrise\n");
        
    }
    return 0;
}
