#include <stdio.h>
int main()
{
    long long n,m,x;
    scanf("%lld %lld",&n,&m);
    if(n > 114515) //��n=1ʱ���޷�����m���������n>114514+1ʱ
                             //��������������
        printf("NO");
    else
    {
        x = 2 * n - 1;   //������n�����ʱ�������ɵ������������
        if(m <= x)       //���Ҫ��Ĳ�����x����������
            printf("YES");
        else
            printf("NO");
    }
    return 0;
}
