#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    
    int sum = 1,a = n;
    //打印上半部分
    for(int i = 1; i <= n; i ++){
        //打印空格
        for(int k = a - 1; k >= 0; k --){
            printf(" ");
        }
        a --;
        
        //打印数字
        for(int j = 1; j <= sum; j++){
            printf("%d",i);
            
        }
		sum += 2;
        printf("\n");
    }
    
    //打印下半部分
    int b = 2;
    for(int i = n - 1; i > 0; i --){
    	
        for(int k = 1; k <= b; k ++){
            printf(" ");
        }
        b ++;
        
        for(int j = sum - 4; j >= 1; j --){
            printf("%d",i);
            
        }
		sum -= 2;
        printf("\n");
    }
    return 0;
}

