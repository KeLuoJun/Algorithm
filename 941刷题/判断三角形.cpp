#include <stdio.h>  
  
int main() {  
    int a, b, c;  
    scanf("%d %d %d", &a, &b, &c);  
  
    if(a+b>c && a+c>b && b+c>a){
        if(a==b && b==c)
            printf("yes\nyes\nyes");
        else{
            if(a==b || a==c || b==c)
                printf("no\nyes\nyes");
            else
                printf("no\nno\nyes");
        }
    }
    else
        printf("no\nno\nno");
    
  
    return 0;  
}
