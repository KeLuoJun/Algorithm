#include<stdio.h>
//�Ƚ������һϵ�������е���Сֵ���һ����������
//Ȼ�����ֵ�����һ���������������������������
int main()
{
    //�����ڵ�һ���и���һ��������N����10����
    //�ڶ��и���N�����������ּ��Կո�ָ���
    int n;
    scanf("%d",&n);
    int a[10],max,min,max_num,min_num;
    int flag = 1;
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        if(flag == 1)
        {
            max = a[i];
            max_num = i;
            min = a[i];
            min_num = i;
            flag = 0;
        }
        else
        {
            if(a[i] > max)
            {
                max = a[i];
                max_num = i;
            }
            if(a[i] < min)
            {
                min = a[i];
                min_num = i;
            }
        }
    }
    a[min_num] = a[0];
    a[0] = min;
    if(max_num == 0) max_num = min_num; 
    a[max_num] = a[n-1];
    a[n-1] = max;
    
    for(int i = 0; i < n; i++)
        printf("%d ",a[i]);
    return 0;
}
