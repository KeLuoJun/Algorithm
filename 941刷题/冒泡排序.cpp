#include <stdio.h>
int main()
{
	int n = 5,t;
	int num[5] = {5,3,4,1,2};
	for(int i = 0; i < n - 1; i++)    //控制比较的轮次 
		for(int j = 0; j < n - i - 1; j++)    //控制每次比较的次数 （哪些数进行比较） 
		{
			int flag = 1; 
			if(num[j] > num[j + 1])      //交换两个数 
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
