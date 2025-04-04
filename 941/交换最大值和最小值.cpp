#include<stdio.h>
//先将输入的一系列整数中的最小值与第一个数交换，
//然后将最大值与最后一个数交换，最后输出交换后的序列
int main()
{
    //输入在第一行中给出一个正整数N（≤10），
    //第二行给出N个整数，数字间以空格分隔。
    int n;
    scanf("%d",&n);
    int a[10],max,min,max_num,min_num;
    int flag = 1;
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        if(flag == 1)
        {
            max = a[i];
            max_num = i;
            min = a[i];
            min_num = i;
            flag = 0;
        }
        else
        {
            if(a[i] > max)
            {
                max = a[i];
                max_num = i;
            }
            if(a[i] < min)
            {
                min = a[i];
                min_num = i;
            }
        }
    }
    a[min_num] = a[0];
    a[0] = min;
    if(max_num == 0) max_num = min_num; 
    a[max_num] = a[n-1];
    a[n-1] = max;
    
    for(int i = 0; i < n; i++)
        printf("%d ",a[i]);
    return 0;
}
