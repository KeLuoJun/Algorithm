#include <stdio.h>
/*
思路：现将要插入的数插在原数组的末尾，然后对插入后的数组进行冒泡排序 
*/ 
int main()
{
    int n,x,t;
    scanf("%d",&n);
    int num[10];
    for(int i = 0; i < n; i++)
        scanf("%d",&num[i]);
    scanf("%d",&x);
    num[n] = x;
    n++;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(num[j] > num[j+1])
            {
                t = num[j+1];
                num[j+1] = num[j];
                num[j] = t;
            }
        }
    }
    for(int i = 0; i < n; i++)
        printf("%d ",num[i]);
    return 0;
}
