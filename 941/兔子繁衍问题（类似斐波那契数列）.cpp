#include<stdio.h>

int main()
{
    int n,m=1,t=1,count=2;
    int sum=1;     //sum��ʾ��������
    printf("����Ҫ�ﵽ�������ܶ���n(n<=10000)��"); //������ʾ
    scanf("%d",&n);
    if(n==1){
                printf("1");
            }
    else{
            while(sum<n){
                 count++;
                 t=m;
                 m=sum;    //m��ű���ѭ���е�sumֵ��������һ�θ�ֵ��t
                 sum=sum+t;
                        }
            printf("��Ҫ��������%d\n",count);
        }
        return 0;
}

