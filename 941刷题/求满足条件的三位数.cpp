#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    
    int count = 1,judge,i;
    int num[1000];
    for(i = 100; i <= 999; i ++)
    {
        judge = 0;
        for(int j = 1; j < i; j++)   //判断是否符合完全平方数 
            if(j*j == i){
                judge = 1;
                break;
            }
            
        if(judge){
            int a,b,c;
            a = i / 100;  //提取百位上的数 
            b = (i / 10) % 10;   //提取十位上的数 
            c = i % 10;    //提取个位数的数 
            if(a == b || b == c || a == c){
                num[count] = i;
                count ++;
            }
        }
    }
    printf("%d",num[n]);
    return 0;
    
}
