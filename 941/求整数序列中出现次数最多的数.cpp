#include<stdio.h>
int main()
{
    int i,n;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
  //读入
        scanf("%d",&a[i]);
    int j,num,count,max=-1,maxnum;
    for(i=0;i<n;i++)
  //处理
    {
        num=a[i];
        count=0;
        for(j=0;j<n;j++)  //统计数量
        {
            if(a[j]==num)
            count++;
        }
        if(count>max)    //记录最大值
        {
            max=count;
            maxnum=a[i];
        }
    }
   //输出
    printf("%d %d",maxnum,max);
    return 0;
}
