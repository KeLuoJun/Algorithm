# include<stdio.h>
int main()
{
    int a,unit_digit;   //�������a��unit_digit
    printf("������һ��������");
    scanf("%d",&a);   //�������a��ֵ
    unit_digit = a % 10;    //����ȡ�����ĸ�λ���ļ���
    printf("�������ĸ�λ���ǣ�%d\n", unit_digit);  //������
    return 0;
    
}

