/*
  1
 222
33333
 222
  1

*/

#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i ++)
    {
        //��ӡ�ո�
        for(int j = n - 1; j >= i; j--)
            printf(" ");
            
        //��ӡ����
        for(int k = 1; k <= 2 * i - 1; k++)
            printf("%d",i);
        printf("\n");
    }
    //��ӡ�°벿��
    int x = n - 1;
    for(int i = 1; i <= n - 1; i++)
    {
        //��ӡ�ո�
        for(int j = 1; j <= i; j++)
            printf(" ");
            
        //��ӡ����
        for(int k = 1; k <= 2 * x - 1; k++)
            printf("%d",x);
        x--;
        printf("\n");
    }
    return 0;
}
