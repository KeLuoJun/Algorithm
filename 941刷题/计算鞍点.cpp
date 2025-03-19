#include <stdio.h>
int main()
{
    int a[5][5];
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            scanf("%d",&a[i][j]);

    int max[5][5] = {0},min[5][5] = {0};
    int sign1,sign2;   //用于暂时存储最大最小值所在位置
    for(int i = 0; i < 5; i++) //求每行的最大值
    {
        sign1 = i;
        sign2 = 0;
        for(int j = 1; j < 5; j++)  //对每行逐个判断
        {
            if(a[i][j] > a[sign1][sign2]) 
            {
                sign1 = i;
                sign2 = j;
            }
                
        }
        max[sign1][sign2] = 1;  //将最大值所在位置对应到max数组并将其的值变为1
    }

    for(int j = 0; j < 5; j++)  //求每列的最小值
    {
        sign1 = 0;
        sign2 = j;
        for(int i = 1; i < 5; i++)   //对每一列逐个比较
        {
            if(a[i][j] < a[sign1][sign2])
            {
                sign1 = i;
                sign2 = j;
            }
                
        }
        min[sign1][sign2] = 1;   //将最小值所在位置对应到min数组并将其的值变为1
    }
    int flag = 0;  //是否存在的标志，0为不存在，1为存在
    for(int i = 0; i < 5; i++)  //遍历两个数组
        for(int j = 0; j < 5; j++)
        {
            if(max[i][j] * min[i][j] != 0)
            {
                printf("%d %d %d",i+1,j+1,a[i][j]); 
                flag = 1;
            }
                
        }
    if(flag == 0)  //不存在鞍点
        printf("not found");
    return 0;
}
