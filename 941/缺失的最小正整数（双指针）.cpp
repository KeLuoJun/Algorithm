/*
例如：-3,2,1,8,5,4,2,3,5,13  这10个数 
则缺失的最小正整数为6 （因为数组0到4的位置上上都有对应符合的数字）（a[i] = i+1）
*/
#include <stdio.h>
int main()
{
    int swap(int *a,int *b);
    int n;
    scanf("%d",&n);
    int a[100];
    for(int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    int l = 0,r = n;  //r为预期的最大值，r右边的区域都是垃圾区
    //l的左边，都是做到i位置上放着i+1的区域
    //永远盯着l位置的数字看，看能不能扩充(l++)
    while(l < r)
    {
        if(a[l] == l+1)
            l++;
        //l位置上的数小于l+1 或 大于预期的值r 或 与l位置上的数字应该放在的位置上的数字重复
        else if(a[l] <= l || a[l] > r || a[a[l]-1] == a[l])
        {
            swap(&a[l],&a[--r]);
        }
        else
            swap(&a[l],&a[a[l]-1]);
    }
    //l和r撞上了 
    printf("%d",l+1);
    return 0;
    
}
void swap(int *a,int *b)
{
    int t =*b;
    *b = *a;
    *a = t;
}
