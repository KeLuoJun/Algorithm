/*
��һ�������˵�λ��һ�� m*n���������Ͻǡ�
������ÿһʱ��ֻ�����»��������ƶ�һ����
��������ͼ�ﵽ��������½ǡ������е��ϰ��Ϳ�λ�÷ֱ��� 
1 �� 0 ����ʾ�����ж�������ͬ��·���� 
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
    int m,n; //���������� 
    int arr[N][N];
    scanf("%d%d",&m,&n);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d",&arr[i][j]);
    int ans = func(arr,0,0,m,n);
    printf("%d",ans);
    return 0;
}
