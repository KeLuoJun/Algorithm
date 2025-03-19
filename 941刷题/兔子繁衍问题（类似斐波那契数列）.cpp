#include<stdio.h>

int main()
{
    int n,m=1,t=1,count=2;
    int sum=1;     //sum表示兔子总数
    printf("输入要达到的兔子总对数n(n<=10000)："); //输入提示
    scanf("%d",&n);
    if(n==1){
                printf("1");
            }
    else{
            while(sum<n){
                 count++;
                 t=m;
                 m=sum;    //m存放本次循环中的sum值，用于下一次赋值给t
                 sum=sum+t;
                        }
            printf("需要的月数：%d\n",count);
        }
        return 0;
}

