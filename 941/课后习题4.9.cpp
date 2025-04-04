#include <stdio.h>
#include <math.h>
int main()
{
    int n,a,b,c,d=0;
    int count = 0;
    scanf("%d",&n);
    
    a = n;
    b = n;
    while(n)
    {
        n = n / 10;
        count ++;
    }
    printf("%d\n",count);
    
    for(int j = count; j >= 1; j --)
    {
    	int ten = pow(10,(j-1));
        d = (b / ten) % 10; 
        printf("%d ",d);
        
    }
    printf("\n");
    
    for(int i = 1; i <= count; i++)
    {
        c = a % 10;
        printf("%d",c);
        a /= 10;
    }
    return 0;
}
