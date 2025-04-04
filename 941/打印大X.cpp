#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char* argv[])
{
    int i = 0, j = 0;
    int n = 0, m = 0;
    scanf("%d%d", &m, &n);
    int k = n - m -1;//中间空格(句点)最大值
    int t = m + n - 1;//列数
    //上半部分
    for (i = 0; i < n / 2 + 1; i++)
    {
        for (j = 0; j < i; j++)//左边空格(句点)
        {
            printf(".");
        }
        //除去每行两边的空格(句点)，判断中间剩余位置数量是否大于2*m，若大于2*m则中间还有空间打印空格(句点)
        if (t - i * 2 > 2 * m)//中间还能打印空格(句点)
        {
            for (j = 0; j < m; j++)
            {
                printf("*");
            }
            for (j = k - i * 2; j > 0; j--)
            {
                printf(".");
            }
            for (j = 0; j < m; j++)
            {
                printf("*");
            }
        }
        else//中间不能打印空格(句点)
        {
            for (j = 0; j <t - i * 2; j++)
            {
                printf("*");
            }
        }
 
        for (j = 0; j < i; j++)//右边空格(句点)
        {
            printf(".");
        }
        printf("\n");
    }
    //下半部分
    for (i = 0; i < n / 2; i++)
    {
        for (j = 0; j < n / 2 - 1 - i; j++)//左边空格(句点)
        {
            printf(".");
        }
 
        if (t - (n / 2 - 1 - i) * 2 > 2 * m)//中间还能打印空格(句点)
        {
            for (j = 0; j < m; j++)
            {
                printf("*");
            }
            for (j = 0; j < t - 2 * m - (n / 2 - 1 - i) * 2; j++)
            {
                printf(".");
            }
            for (j = 0; j < m; j++)
            {
                printf("*");
            }
        }
        else//中间不能打印空格(句点)
        {
            for (j = 0; j < t - (n / 2 - 1 - i) * 2; j++)
            {
                printf("*");
            }
        }
 
        for (j = 0; j < n / 2 - 1 - i; j++)
        {
            printf(".");
        }
        printf("\n");
    }
    // 请在此输入您的代码
    return 0;
}
