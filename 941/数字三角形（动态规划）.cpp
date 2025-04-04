#include <stdio.h>
#define N 1001
int map[N][N];
void DP(int (*arr)[N],int n)
{
    int max(int a,int b);
    for(int i = 2; i <= n; i++)
        for(int j = 1; j <= i; j++)
        {
            arr[i][j] = max(arr[i-1][j-1],arr[i-1][j]) + arr[i][j];
            
        }
}
int maxValue(int (*arr)[N],int n)
{
    int max = arr[n][1];
    for(int i = 2; i <= n; i++)
        if(arr[n][i] > max) max = arr[n][i];
    return max;
}

int max(int a,int b)
{
    return a > b ? a : b;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            scanf("%d",&map[i][j]);
    DP(map,n);
    int result = maxValue(map,n);
    printf("%d\n",result);
    return 0;
}
