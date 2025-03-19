#include <stdio.h>
int main()
{
    int n,k,sum;
    scanf("%d %d",&n,&k);
    int num[n],a[k],b[k];
    for(int i = 0; i < n; i ++)
    {
        scanf("%d",&num[i]);
    }
    for(int j = 1; j <= k; j++)
    {
        scanf("%d %d",&a[j],&b[j]);
    }
    for(int j = 1; j <= k; j++){
    	sum = 0;
	    for(int p = a[j] - 1; p <= b[j] - 1; p ++)
	        {
	            sum += num[p];
	        }
	        printf("%d\n",sum);
	        
	}
    return 0;
}
