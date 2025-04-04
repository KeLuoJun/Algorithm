#include <stdio.h>
int main()
{
    int a,b,j,k;
    scanf("%d %d",&a,&b);
    
    //求最小公倍数
    for(j=1; j<=b; j++)
    {
        k = a * j;
        if(k % b == 0)
            break;
        else
            continue;
    }
    
	//求最大公约数
	int temp;  
    while (b != 0) {  
        temp = a % b;  
        a = b;  
        b = temp;  
    }  

    
    printf("%d %d",a,k);
    return 0;
}
