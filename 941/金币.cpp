#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    
    int cycle = 1;  //����������
    int day = 0;    //���������µ�����
    int sum = 0;
    while(day < n){
        day += cycle;
        sum += cycle * cycle;
        cycle ++;
    }
    
    if(n - day - cycle + 1 != 0){
        sum = sum + (n - day) * (cycle - 1);
    }
    printf("%d",sum);
    return 0;
}
