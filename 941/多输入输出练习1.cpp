#include <stdio.h>
int main()
{
	int num;
	int max;
	
end:
    int flag = 1;
	while(scanf("%d",&num))
	{
	    if(flag)
	    {
	        max = num;
	        flag = 0;
	    }
	        
	    if(num > max) max = num;
		if(num == 0)
		{
		    printf("%d\n",max);
		    goto end;
		}
			
	}
	return 0;
} 
