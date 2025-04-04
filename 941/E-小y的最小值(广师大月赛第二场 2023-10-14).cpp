#include <stdio.h>  
#include <stdlib.h>  
int main()
{
    int n,i,j;
    int a[n],b[n];
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(j = 0; j < n; j++){
        scanf("%d", &b[j]);
    }
    
    int M = 0,min = abs(a[0] - b[0]);
    for(i = 0; i < n; i ++){
        for(j = 0; j < n; j ++){
            M = abs(a[i] - b[j]);
            if(M < min)
                min = M;
        }
    }
    printf("%d",min);
    return 0;
}
