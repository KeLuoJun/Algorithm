
#include <stdio.h>
 
int array[1001][1001] = { 0 };
 
int main()
{
    int n = 0;
    scanf("%d",&n);
    int i = 1, j = 1, k = 0,pos = 1; //pos代表方向移动   1代表右上   -1代表左下
    array[i][j] = 1;
    for (k = 2; k <= n*n; k++)
    {
        if (i == 1 && j <n && pos ==1) //碰到上边界,列增加1,行不变     此后行增,列减
        {
            array[i][++j] = k;
            pos = -1;                 //方向注意
        }
        else if(j==1 && i<n && pos == -1)//碰到左边界,行增加1,列不变     此后行减,列增
        {
            array[++i][j] = k;
            pos = 1;                     //方向注意               
        }
        else if (j == n && pos==1) //碰到左边界,行增加1,列不变     此后行增,列减
        {
            array[++i][j] = k;
            pos = -1;                     //方向注意
        }
        else if (i == n && pos ==-1) //碰到右边界,列增加1,行不变    此后行减,列增
        {
            array[i][++j] = k;
            pos = 1;
        }
        else if (pos == 1)         //除去上面的边界情况,就是中间移动过程
        {
            array[--i][++j] = k;
        }
        else if(pos == -1)
        {
            array[++i][--j] = k;
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d ",array[i][j]);
        printf("\n");
    }
    return 0;
}
 
