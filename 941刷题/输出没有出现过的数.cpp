#include <stdio.h>
int main()
{
	int num[10],i,j;
	for(i=0; i<=9; i++)
		num[i] = 0;  //��ʼ��ÿ��С����Ϊ0 
		
	for(i=1; i<=5; i++)
	{
		scanf("%d",&j);   //��������5���� 
		num[i] = 1;       //�Ѷ�Ӧ��С�����Ϊ1 
	 }
	
	for(i=0; i<=9; i++)
		if(num[i] == 0)    //���û�г��ֹ����� 
			printf("%d ",i);
	
	return 0; 
}

