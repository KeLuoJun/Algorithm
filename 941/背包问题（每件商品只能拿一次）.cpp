#include <stdio.h>
#include <stdlib.h>
#define MAX_M 1000
#define MAX_N 100

int n,m;   //�ֱ�Ϊ��Ʒ�����ͱ������
int w[MAX_N],p[MAX_N];   //����w[]��ʾ��Ʒ��������p[]��ʾ��Ʒ�ļ�ֵ
int f[MAX_M+1];    //����¼���飨�������Ϊ����¼������±꣩���洢���������װ��Ʒ������ֵ��

int max(int a,int b)
{
    return a > b ? a : b;
}

int main()
{
    scanf("%d %d",&m,&n);
    for(int i = 0; i < n; i++) 
        scanf("%d %d",&w[i],&p[i]);
        
    for(int i = 0; i < n; i++)  //��Ʒ�ı�� 
        for(int j = m; j >= w[i]; j--)     //����ʣ������
        {
            f[j] = max(f[j], f[j-w[i]]+p[i]);
        }
        
    printf("%d",f[m]);
    return 0;
}
