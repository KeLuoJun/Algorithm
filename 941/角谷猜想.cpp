#include <stdio.h>
int main()
{
    int i,j,k;
    scanf("%d",&i);
    
    if(i!=1){
        while(i!=1){
            if(i%2==0){
                i=i/2;
                j=i*2;
                printf("%d/2=%d\n",j,i);
            }
            else{
                i=i*3+1;
                k=(i-1)/3;
                printf("%d*3+1=%d\n",k,i);
                continue;
            }
        }
    }
    printf("End");
    return 0;
}
