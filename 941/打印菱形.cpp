#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    
    //��ӡ�ϰ벿��
    int x = n;
    for(int i = 1; i <= n; i ++)
    {
        //��ӡ�ո�
        for(int j = 1; j < x; j ++)
        {
            printf(" ");
        }
        x --;
        //��ӡ*
        for(int j = 1; j <= 2*i-1; j ++)
            printf("*");
        printf("\n");
    }
    //��ӡ�°������
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
