# include<stdio.h>
int main()
{
    int a,unit_digit;   //定义变量a，unit_digit
    printf("请输入一个整数：");
    scanf("%d",&a);   //输入变量a的值
    unit_digit = a % 10;    //进行取整数的个位数的计算
    printf("改整数的个位数是：%d\n", unit_digit);  //输出结果
    return 0;
    
}

