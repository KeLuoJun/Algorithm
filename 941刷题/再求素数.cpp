#include <stdio.h>
#include <math.h>
int main()
{
    int n,num = 2,count;
    scanf("%d",&n);
    printf("%d\n",num);   //输出素数2
    for(int i = 3; i <= n; i += 2)   //从3到n的奇数判断是否为素数
    {
		
        for(int j = 2; j <= sqrt(i); j ++)   //判断素数时，除数都为奇数 
        {	
			count = 1;       //count=1表示改数为素数 
            if(i % j == 0){
            	count = 0;      //count=0表示改数为非素数 
                break;
				}
            
        }
        if(i == 3)
        	printf("%d\n",i);
        if(count == 1)
            printf("%d\n",i);
    }
    return 0;
}
