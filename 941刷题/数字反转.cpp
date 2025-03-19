#include <stdio.h>  
  
int reverse(int num) {  
    int rev = 0;  
    while(num != 0) {  
        rev = rev*10 + num%10;    //¹Ø¼ü 
        num = num/10;  
    }  
    
    return rev;  
}  
  
int main() {  
    int num;  
    scanf("%d", &num);  
    int rev = reverse(num);  
    printf("%d\n", rev);  
    return 0;  
}
