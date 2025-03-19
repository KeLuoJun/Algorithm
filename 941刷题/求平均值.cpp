#include <stdio.h>
int main()
{
    int num,sum=0,count=0;
    double avg;
    
    do{
        scanf("%d",&num);
        if(num != 0){
            sum += num;
            count++;
        }
    }while(num != 0);
    
    if(count>0){
        avg = (double)sum / count;
        printf("%.1f",avg);
    }
    return 0;
}
