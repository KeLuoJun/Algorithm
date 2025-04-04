#include <stdio.h>
int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	
	int num[n]; 
	for(i=1; i<=n; i++)
		scanf("%d",&num[i]);
		
	//开始比较
	for(i=1; i<=n-1; i++)   //定义比较多少组 
	{
		for(j=i+1; j<=n; j++){    //与后面的数依次比较 
			if(num[i]>num[j]){
				k=num[i]; num[i]=num[j]; num[j]=k;
			}
		}
	} 
	for(i=1; i<=n; i++)
	{
		printf("%d ",num[i]); 
	}
	return 0;
}
