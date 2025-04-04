#include <stdio.h>
#define N 100000
int main()
{
    int n,m,x,y,t,i;
    int num[N];
    for(int k = 0; k < N; k++)
        num[k] = k;
        
    scanf("%d %d",&n,&m);
    
    for(int j = 1; j <= m; j++)
    {
        scanf("%d %d",&x,&y);
        t = num[x];
        num[x] = num[y];
        num[y] = t;
        
    }
    for(i = 1; i <= n; i++)
        printf("%d ",num[i]);
    return 0;
}
