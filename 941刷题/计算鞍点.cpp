#include <stdio.h>
int main()
{
    int a[5][5];
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            scanf("%d",&a[i][j]);

    int max[5][5] = {0},min[5][5] = {0};
    int sign1,sign2;   //������ʱ�洢�����Сֵ����λ��
    for(int i = 0; i < 5; i++) //��ÿ�е����ֵ
    {
        sign1 = i;
        sign2 = 0;
        for(int j = 1; j < 5; j++)  //��ÿ������ж�
        {
            if(a[i][j] > a[sign1][sign2]) 
            {
                sign1 = i;
                sign2 = j;
            }
                
        }
        max[sign1][sign2] = 1;  //�����ֵ����λ�ö�Ӧ��max���鲢�����ֵ��Ϊ1
    }

    for(int j = 0; j < 5; j++)  //��ÿ�е���Сֵ
    {
        sign1 = 0;
        sign2 = j;
        for(int i = 1; i < 5; i++)   //��ÿһ������Ƚ�
        {
            if(a[i][j] < a[sign1][sign2])
            {
                sign1 = i;
                sign2 = j;
            }
                
        }
        min[sign1][sign2] = 1;   //����Сֵ����λ�ö�Ӧ��min���鲢�����ֵ��Ϊ1
    }
    int flag = 0;  //�Ƿ���ڵı�־��0Ϊ�����ڣ�1Ϊ����
    for(int i = 0; i < 5; i++)  //������������
        for(int j = 0; j < 5; j++)
        {
            if(max[i][j] * min[i][j] != 0)
            {
                printf("%d %d %d",i+1,j+1,a[i][j]); 
                flag = 1;
            }
                
        }
    if(flag == 0)  //�����ڰ���
        printf("not found");
    return 0;
}
