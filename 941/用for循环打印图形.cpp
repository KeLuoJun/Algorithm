#include <stdio.h>  
  
int main() {  
    int i, j, k;  
    int n = 9; // ͼ�εĴ�С�����Ը�����Ҫ���е���  
  
    // ��ӡ�ϰ벿��  
    for (i = 1; i <= n; i++) {  
        // ��ӡ�ո�  
        for (j = 1; j <= n - i; j++) {  
            printf(" ");  
        }  
        // ��ӡ�Ǻ�  
        for (k = 1; k <= 2 * i - 1; k++) {  
            printf("*");  
        }  
        printf("\n");  
    }  
  
    // ��ӡ�°벿��  
    for (i = n - 1; i >= 1; i--) {  
        // ��ӡ�ո�  
        for (j = 1; j <= n - i; j++) {  
            printf(" ");  
        }  
        // ��ӡ�Ǻ�  
        for (k = 1; k <= 2 * i - 1; k++) {  
            printf("*");  
        }  
        printf("\n");  
    }  
  
    return 0;  
}
