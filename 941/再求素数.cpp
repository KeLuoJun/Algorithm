#include <stdio.h>
#include <math.h>
int main()
{
    int n,num = 2,count;
    scanf("%d",&n);
    printf("%d\n",num);   //�������2
    for(int i = 3; i <= n; i += 2)   //��3��n�������ж��Ƿ�Ϊ����
    {
		
        for(int j = 2; j <= sqrt(i); j ++)   //�ж�����ʱ��������Ϊ���� 
        {	
			count = 1;       //count=1��ʾ����Ϊ���� 
            if(i % j == 0){
            	count = 0;      //count=0��ʾ����Ϊ������ 
                break;
				}
            
        }
        if(i == 3)
        	printf("%d\n",i);
        if(count == 1)
            printf("%d\n",i);
    }
    return 0;
}
