#include <stdio.h>
int main()
{
    int m,n,i;
    scanf("%d",&m);   //输入总药量
    scanf("%d",&n);	   //输入取药人数
    
    int num[n];    
    for(i=1;i<=n;i++){
        scanf("%d",&num[i]);   //每个病人希望取走的药品数
    }
    
    int count=0;
    for(i=1;i<=n;i++){
        if(num[i]<=m)
            m=m-num[i];
        else
            count++;
    }
    
    printf("%d\n",count);
    return 0;
}
