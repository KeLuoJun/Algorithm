#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    
    int sum = 1,a = n;
    //��ӡ�ϰ벿��
    for(int i = 1; i <= n; i ++){
        //��ӡ�ո�
        for(int k = a - 1; k >= 0; k --){
            printf(" ");
        }
        a --;
        
        //��ӡ����
        for(int j = 1; j <= sum; j++){
            printf("%d",i);
            
        }
		sum += 2;
        printf("\n");
    }
    
    //��ӡ�°벿��
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

