#include <stdio.h>
int main()
{
	int n = 5,t;
	int num[5] = {5,3,4,1,2};
	for(int i = 0; i < n - 1; i++)    //���ƱȽϵ��ִ� 
		for(int j = 0; j < n - i - 1; j++)    //����ÿ�αȽϵĴ��� ����Щ�����бȽϣ� 
		{
			int flag = 1; 
			if(num[j] > num[j + 1])      //���������� 
			{
				t = num[j + 1];
				num[j + 1] = num[j];
				num[j] = t;
				flag = 0;
			}
			if(flag) break;
		}
		
	for(int i = 0; i < n; i ++)
		printf("%d ",num[i]);
	return 0;
 } 
