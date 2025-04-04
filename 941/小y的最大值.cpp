#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int num[n],d[n];
    for(int i = 0; i < n; i ++)
    {
        scanf("%d",&num[i]);
    }
    
    int m;
    for(int i = 0; i < n - 1; i ++)
    {
    	
        for(int j = i + 1; j < n; j ++)
        {
	        d[j] = num[i] - num[j];  }
	    
	    m = d[i + 1];
	    for(int k = i + 1; k < n; k ++)
	    {
	    	if(d[k] > m)
	    		m = d[k];
		}

        printf("%d ",m);
	}
	printf("no");
    return 0;
}
