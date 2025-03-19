#include<stdio.h>
int main()
{
  int n,i,j,k,count=0;
  scanf("%d",&n);
  for(i=n/5;i>=1;i--)
  {
    for(j=n/2;j>=1;j--)
    {
      for(k=n;k>=1;k--)
      {
        if((i*5+j*2+k)==n)
        {
          printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n",i,j,k,i+j+k);
          count++;
        }
      }
    }
  }
  printf("count = %d",count);
}

