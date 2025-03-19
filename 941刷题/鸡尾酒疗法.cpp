#include <stdio.h>  
int main()  
{  
    int n, i;  
    float x,y;  
    scanf("%d", &n);  
    int a[n], b[n];  
    for (i = 0; i < n; i++) {  
        scanf("%d %d", &a[i], &b[i]);  
    }  
    x = (float)b[0] / a[0];   
    for (i = 1; i < n; i++) {  
        y = (float)b[i] / a[i];  
        if (y - x > 0.05) {     //±È½ÏÊä³öbetter 
            printf("better\n");  
        } else {  
            if (x - y > 0.05) {  
                printf("worse\n");  
            } else {  
                printf("same\n");  
            }  
        }  
    }  
    return 0;  
}
