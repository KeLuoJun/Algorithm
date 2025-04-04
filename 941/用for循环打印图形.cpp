#include <stdio.h>  
  
int main() {  
    int i, j, k;  
    int n = 9; // 图形的大小，可以根据需要进行调整  
  
    // 打印上半部分  
    for (i = 1; i <= n; i++) {  
        // 打印空格  
        for (j = 1; j <= n - i; j++) {  
            printf(" ");  
        }  
        // 打印星号  
        for (k = 1; k <= 2 * i - 1; k++) {  
            printf("*");  
        }  
        printf("\n");  
    }  
  
    // 打印下半部分  
    for (i = n - 1; i >= 1; i--) {  
        // 打印空格  
        for (j = 1; j <= n - i; j++) {  
            printf(" ");  
        }  
        // 打印星号  
        for (k = 1; k <= 2 * i - 1; k++) {  
            printf("*");  
        }  
        printf("\n");  
    }  
  
    return 0;  
}
