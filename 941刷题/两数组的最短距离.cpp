#include<stdio.h>
#include<math.h>
 
int main()
{
	int f[100];
	int g[100];
    int m,n,i,j;
	int min;
 
	
 
	scanf("%d%d",&m,&n);
 
	for(i=0;i<m;i++)
	{
		scanf("%d",&f[i]);
	}
 
	for(j=0;j<n;j++)
	{
		scanf("%d",&g[j]);
	}
 
	min = fabs(f[0]-g[0]);
 
	for(i=0;i<m;)
	{
		for(j=0;i<n;)
		{
			if( fabs(f[i]-g[j+1])<min && j+1<m )
			{
				min = fabs(f[i] - g[j+1]);
				j++;
			}
			  else if(fabs(f[i+1]-g[j])<min&&i+1<n)//比其大的情况
            {
                min = fabs(f[i+1]-g[j]);
                i++;
            }
            else
            {
                i++;
                j++;
                if(fabs(f[i]-g[j])<min)
                    min=fabs(f[i]-g[j]);
            }
			if(i==m-1||j==n-1)
                break;
		}
	}
	 printf("%d",min);
	
 
	return 0;
}
