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
        for(int j = 1; j < i; j++)   //�ж��Ƿ������ȫƽ���� 
            if(j*j == i){
                judge = 1;
                break;
            }
            
        if(judge){
            int a,b,c;
            a = i / 100;  //��ȡ��λ�ϵ��� 
            b = (i / 10) % 10;   //��ȡʮλ�ϵ��� 
            c = i % 10;    //��ȡ��λ������ 
            if(a == b || b == c || a == c){
                num[count] = i;
                count ++;
            }
        }
    }
    printf("%d",num[n]);
    return 0;
    
}
