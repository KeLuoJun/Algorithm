#include <stdio.h>
int main()
{
    int t,n,p,x;
    scanf("%d %d",&t,&n);
    int x0 = 0,x1 = 12000,x2 = 13800,x3 = 22200,x4 = 24000;
    
    for(int i = 1; i <= t; i++)
    {
        scanf("%d",&p);
        if(p == 3)
        {
            if(n >= x0 && n < x1)
                printf("day\n");
            if(n >= x1 && n < x2)
                printf("sunset\n");
            if(n >= x2 && n < x3)
                printf("night\n");
            if(n >= x3 && n < x4)
                printf("sunrise\n");
        }
        
        if(p == 1)
        {
            scanf("%d",&x);
            n += x;
            if(n >= x4)
                n -= x4;
        }
        
        if(p == 2)
        {
            scanf("%d",&x);
            n = x; 
        }
            
    }
    return 0;
}
