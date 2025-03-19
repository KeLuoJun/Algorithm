#include <stdio.h>
int main()
{
    int i,j,k;
    scanf("%d",&k);
    int a,b,c,count=0;
    
    for(i=100; i<=999; i++){
        for(j=1; j<=i; j++)
            if(i==j*j){
                count++;
                a=i/100;
                b=(i/10)%10;
                c=i%10;
                if(count==k){
                    if(a==b || a==c || b==c){
                        printf("%d",i);
                        break;
                        
                    }
            }
    }
    }
    return 0;
    
}
