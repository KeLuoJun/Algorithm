/*
���磺-3,2,1,8,5,4,2,3,5,13  ��10���� 
��ȱʧ����С������Ϊ6 ����Ϊ����0��4��λ�����϶��ж�Ӧ���ϵ����֣���a[i] = i+1��
*/
#include <stdio.h>
int main()
{
    int swap(int *a,int *b);
    int n;
    scanf("%d",&n);
    int a[100];
    for(int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    int l = 0,r = n;  //rΪԤ�ڵ����ֵ��r�ұߵ�������������
    //l����ߣ���������iλ���Ϸ���i+1������
    //��Զ����lλ�õ����ֿ������ܲ�������(l++)
    while(l < r)
    {
        if(a[l] == l+1)
            l++;
        //lλ���ϵ���С��l+1 �� ����Ԥ�ڵ�ֵr �� ��lλ���ϵ�����Ӧ�÷��ڵ�λ���ϵ������ظ�
        else if(a[l] <= l || a[l] > r || a[a[l]-1] == a[l])
        {
            swap(&a[l],&a[--r]);
        }
        else
            swap(&a[l],&a[a[l]-1]);
    }
    //l��rײ���� 
    printf("%d",l+1);
    return 0;
    
}
void swap(int *a,int *b)
{
    int t =*b;
    *b = *a;
    *a = t;
}
