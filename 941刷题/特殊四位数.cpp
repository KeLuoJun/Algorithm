#include <stdio.h>  
  
int main() {  
    int k, count = 0;  
    scanf("%d", &k);  
  
    for (int i = 1000; i <= 9999; i++) {  
        int first = i / 100; // ��ȡǰ��λ����  
        int second = i % 100; // ��ȡ����λ����  
  
        // ����Ƿ���������  
        if ((first + second) * (first + second) == i) {  
            count++;  
            if (count == k) {  
                printf("%d\n", i);  
                return 0;  
            }  
        }  
    }  
    return 0;  
}
