#include <stdio.h>
int main()
{
	int a[110][110],n,k,c = 0;
	scanf("%d",&n);
	k = 2*n - 1;
	int i = 1,j = 1;
	for(int t = 1; t <= k; t++)
	{
		if(t%2)
		{
			while(i >= 1 && j <= n)
			{
				a[i][j] = ++c;
				i--,j++;
			}
			i++,j--;   //重新回到矩阵内
			if(j+1 > n) i++;
			else j++;
		}
		else
		{
			while(i <= n && j >= 1)
			{
				a[i][j] = ++c;
				i++,j--;
			}
			i--,j++;
			if(i+1 > n) j++;
			else i++;
		}
	}
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
			printf("%3d",a[i][j]);
		printf("\n");
	}
	return 0;
		
 } 
