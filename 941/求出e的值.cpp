//#include <stdio.h>
//int main()
//{
//    int n,i,j;
//    scanf("%d", &n);
//    
//    double e = 1;
//    for(i = 1; i <= n; i ++){
//    	double count = 1;    //�״�countӦ�ö������������������ѭ���� 
//        for(j = 1; j <= i; j ++){
//            count *= j;
//        }
//        e += 1.0 / count;
//    }
//    printf("%.10lf\n",e);
//    return 0;
//}

//�Ż��� 
#include<stdio.h>
int main()
{
    int i,n;
    double sum =1,t=1;
    printf("����n:\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        t=t*i;
        sum= sum+1.0/t;
    }
    printf("e=%.10lf",sum);
    return 0;
}

