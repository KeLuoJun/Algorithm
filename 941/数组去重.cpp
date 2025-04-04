#include <stdio.h>
#define N 10000
int main()
{
	int n =  10;
	int num[n] = {10,20,30,40,30,20,50,60,70,60};
	for(int i = 0; i < n - 1; i ++)
		for(int j = i + 1; j < n; j ++)
		{
			if(num[i] == num[j])
			{
				for(int k = j; k < n; k ++)
				{
					num[k] = num[k + 1];
				}
				n --;
				j --;
			}
		}
		
	for(int i = 0; i < n; i ++)
		printf("%d ",num[i]); 
	return 0;
 } 
