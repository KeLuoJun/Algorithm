#include <stdio.h>
int main()
{
    int m,k,i,j;
    scanf("%d %d",&m,&k);
    j = m;
    //判断m有多少个3
    int count = 0;
    while(m != 0){
        i = m % 10;
        m /= 10;
        if(i == 3)
            count++;
    }
    if(count == k){
        if(j % 19 == 0)
            printf("YES");
        else
            printf("NO");
    }
    else
    	printf("NO");
    return 0;
}
