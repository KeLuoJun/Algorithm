#include<stdio.h>
int main()
{
    int i,n;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
  //����
        scanf("%d",&a[i]);
    int j,num,count,max=-1,maxnum;
    for(i=0;i<n;i++)
  //����
    {
        num=a[i];
        count=0;
        for(j=0;j<n;j++)  //ͳ������
        {
            if(a[j]==num)
            count++;
        }
        if(count>max)    //��¼���ֵ
        {
            max=count;
            maxnum=a[i];
        }
    }
   //���
    printf("%d %d",maxnum,max);
    return 0;
}
