#include <stdio.h>
int main()
{
	int num, sum = 0;
	scanf("%d",&num);
	
	while(num > 0){   //ʵ�ָ���λ���ϵ����ֵ���ȡ
	//��Ϊnum���������������ջ�ͱ�Ϊ�� 
		sum += num % 10;   //%10ʵ�ֶԸ����ָ�λ�������ֵ���ȡ 
		num /= 10;         // /10ʵ�ֶԸ����ָ�λ����ȥ�� 
	}
	printf("%d",sum);
	return 0;
}
