#include <stdio.h>
int main()
{
	int max(int a,int b);
	int n = 6;
	int a[n];
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	int lmax = a[0],rmax = a[n-1];
	int i = 1,j = n-2;   //����ָ�� 
	int sum = 0;
	while(i <= j)
	{
		if(lmax <= rmax)   //������ߵ�������ߵ����ֵ��ȷ���� 
		{                  //������ȷ�������ֵ���ұ߲�ȷ�������ֵ��С��
		                   //���ұ�ָ����ָ��λ���Ϸ�����ˮ�ǿ���ȷ����
			sum += max(0,lmax-a[i]);
			lmax = max(lmax,a[i++]);
		}
		else    //�����ұߵ��룬�ұߵ����ֵ��ȷ���� 
		{
			sum += max(0,rmax-a[j]);
			rmax = max(rmax,a[j--]);
		}
	}
	printf("%d",sum);
	return 0;
} 
int max(int a,int b)
{
	return a > b ? a : b;
}
