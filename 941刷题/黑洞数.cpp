#include <stdio.h>
int main()
{
    int n,t,num[3],count = 0,n_min,n_max;
    scanf("%d",&n);
    while(n != 495)
    {
        count++;
        num[0] = n / 100; //提取百位
        num[1] = (n / 10) % 10;   //提取十位
        num[2] = n % 10;  //提取个位
        //冒泡排序（升序）
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2-i; j++)
            {
                if(num[j] > num[j+1])
                {
                    t = num[j+1];
                    num[j+1] = num[j];
                    num[j] = t;
                }
            }
            
        n_max = num[2]*100 + num[1]*10 + num[0];
        n_min = num[0]*100 + num[1]*10 + num[2];
        n = n_max - n_min;
        printf("%d: %d - %d = %d\n",count,n_max,n_min,n);
        if(num[0] == num[1] && num[1] == num[2])
            break;
        else
            continue;
    }
    return 0;
}
