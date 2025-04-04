#include <stdio.h>  
#include <stdlib.h>  
  
// 比较函数，用于 qsort  
int compare(const void *a, const void *b) {  
    int int_a = *((int*) a);  
    int int_b = *((int*) b);  
  
    if (int_a == int_b) return 0;  
    else if (int_a < int_b) return -1;  
    else return 1;  
}  
  
int main() {  
    int i;  
    int numbers[] = {7, 3, 4, 1, -1, 23, 12, 43, -8, 5};  
    int size = sizeof(numbers) / sizeof(int);  
  
    // 对数组进行排序  
    qsort(numbers, size, sizeof(int), compare);  
  
    // 输出排序后的数组  
    for (i = 0; i < size; i++) {  
        printf("%d ", numbers[i]);  
    }  
    printf("\n");  
  
    return 0;  
}
