#include <stdio.h>
#include <stdlib.h>
#define MAX_M 1000
#define MAX_N 100

int n,m;   //分别为物品数量和背包体积
int w[MAX_N],p[MAX_N];   //数组w[]表示物品的重量，p[]表示物品的价值
int f[MAX_M+1];    //备忘录数组（用体积作为备忘录数组的下标）（存储该体积下所装物品的最大价值）

int max(int a,int b)
{
    return a > b ? a : b;
}

int main()
{
    scanf("%d %d",&m,&n);
    for(int i = 0; i < n; i++) 
        scanf("%d %d",&w[i],&p[i]);
        
    for(int i = 0; i < n; i++)  //物品的编号 
        for(int j = m; j >= w[i]; j--)     //背包剩余的体积
        {
            f[j] = max(f[j], f[j-w[i]]+p[i]);
        }
        
    printf("%d",f[m]);
    return 0;
}
