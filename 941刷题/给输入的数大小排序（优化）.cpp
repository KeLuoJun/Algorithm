#include <stdio.h>
int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	
	int num[n]; 
	for(i=1; i<=n; i++)
		scanf("%d",&num[i]);
		
	//��ʼ�Ƚ�
	for(i=1; i<=n-1; i++)   //����Ƚ϶����� 
	{
		for(j=i+1; j<=n; j++){    //�����������αȽ� 
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
