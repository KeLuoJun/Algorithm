#include <stdio.h>
int main()
{
    int n,m,d = 0;
    scanf("%d %d",&n,&m);
    int num[n + 1] = {0};
    for(int i = 2; i <= n; i ++){
	    for(int j = i; j <= m; j = j + i)  //每个人关灯的过程
	    {
	        if(num[j] == 1)
	        	num[j] = 0;
	        else
	        	num[j] = 1;
	    }
	}
    
    for(int i = 1; i <= n; i++)   //遍历查找关灯的是几号灯 
    {
        if(num[i] == 0)
        {
        	if(d == 0){
        		printf("%d",i);
        		d = 1;
			}
			else
			{
				printf(",%d",i); 
			}
		}
    } 
    return 0;
}
