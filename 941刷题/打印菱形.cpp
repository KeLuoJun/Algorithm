#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    
    //打印上半部分
    int x = n;
    for(int i = 1; i <= n; i ++)
    {
        //打印空格
        for(int j = 1; j < x; j ++)
        {
            printf(" ");
        }
        x --;
        //打印*
        for(int j = 1; j <= 2*i-1; j ++)
            printf("*");
        printf("\n");
    }
    //打印下半个部分
    int y = 1;
    for(int i = n - 1; i > 0; i --)
    {
        for(int j = 1; j <= y; j ++)
        {
            printf(" ");
        }
        y ++;
        
        for(int k = 2*i-1; k > 0; k --)
            printf("*");
        printf("\n");
    }
    
    
    
    return 0;
}
