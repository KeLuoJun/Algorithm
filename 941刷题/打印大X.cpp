#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char* argv[])
{
    int i = 0, j = 0;
    int n = 0, m = 0;
    scanf("%d%d", &m, &n);
    int k = n - m -1;//�м�ո�(���)���ֵ
    int t = m + n - 1;//����
    //�ϰ벿��
    for (i = 0; i < n / 2 + 1; i++)
    {
        for (j = 0; j < i; j++)//��߿ո�(���)
        {
            printf(".");
        }
        //��ȥÿ�����ߵĿո�(���)���ж��м�ʣ��λ�������Ƿ����2*m��������2*m���м仹�пռ��ӡ�ո�(���)
        if (t - i * 2 > 2 * m)//�м仹�ܴ�ӡ�ո�(���)
        {
            for (j = 0; j < m; j++)
            {
                printf("*");
            }
            for (j = k - i * 2; j > 0; j--)
            {
                printf(".");
            }
            for (j = 0; j < m; j++)
            {
                printf("*");
            }
        }
        else//�м䲻�ܴ�ӡ�ո�(���)
        {
            for (j = 0; j <t - i * 2; j++)
            {
                printf("*");
            }
        }
 
        for (j = 0; j < i; j++)//�ұ߿ո�(���)
        {
            printf(".");
        }
        printf("\n");
    }
    //�°벿��
    for (i = 0; i < n / 2; i++)
    {
        for (j = 0; j < n / 2 - 1 - i; j++)//��߿ո�(���)
        {
            printf(".");
        }
 
        if (t - (n / 2 - 1 - i) * 2 > 2 * m)//�м仹�ܴ�ӡ�ո�(���)
        {
            for (j = 0; j < m; j++)
            {
                printf("*");
            }
            for (j = 0; j < t - 2 * m - (n / 2 - 1 - i) * 2; j++)
            {
                printf(".");
            }
            for (j = 0; j < m; j++)
            {
                printf("*");
            }
        }
        else//�м䲻�ܴ�ӡ�ո�(���)
        {
            for (j = 0; j < t - (n / 2 - 1 - i) * 2; j++)
            {
                printf("*");
            }
        }
 
        for (j = 0; j < n / 2 - 1 - i; j++)
        {
            printf(".");
        }
        printf("\n");
    }
    // ���ڴ��������Ĵ���
    return 0;
}
