/*
有一个机器人的位于一个 m*n个网格左上角。
机器人每一时刻只能向下或者向右移动一步。
机器人试图达到网格的右下角。网格中的障碍和空位置分别用 
1 和 0 来表示。问有多少条不同的路径？ 
*/
#include <stdio.h>
#define N 30
int func(int (*arr)[N],int row,int cow,int m,int n)
{
    if(arr[row][cow] == 1) return 0;
    if(row == m-1 && cow == n-1)
        return 1;
    else
    {
        if(row == m-1)
            return func(arr,row,cow+1,m,n);
        else
        {
            if(cow == n-1)
                return func(arr,row+1,cow,m,n);
            else
                return func(arr,row,cow+1,m,n)+func(arr,row+1,cow,m,n);
        }
    }
}

int main()
{
    int m,n; //行数和列数 
    int arr[N][N];
    scanf("%d%d",&m,&n);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d",&arr[i][j]);
    int ans = func(arr,0,0,m,n);
    printf("%d",ans);
    return 0;
}
