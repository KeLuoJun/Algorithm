#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i,j;
	int row = 4,col = 5;
	//申请过程 （方法一）
/* 
	int **ar = (int**)malloc(row * sizeof(int*));  //(int *)  易漏*号
	for(i = 0; i < row; i++)
		ar[i] = (int*)malloc(col * sizeof(int*)); 
*/
	//方法二
	int (*ar)[col] = (int(*)[col])malloc(sizeof(int) * row * col); //(*ar) 括号不能少,[]优先级高，少了就是指针数组了
		
	//打印地址
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			printf("%p ",ar[i][j]);
		 } 
		printf("\n");
	}
	
	//释放内存
	for(i = 0;  i < row; i++)
		free(ar[i]);    //整行同时释放（与一维数组一样）
	free(ar);
	return 0;	 
 } 
 
//方法三（一维数组模拟到二维数组） 
/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j;
    int row = 4,col = 5;
    
    //申请一个 4行 5列的二维数组
    int *ar =(int*)malloc(sizeof(int) * row * col);
    
    for (i = 0;i < row;i++)
    {
        for (j = 0;j < col;j++)
        {
            printf("%p  ",&ar[i * col + j]);   //二维数组线性存储 
        }
        printf("\n");
    }
    free(ar);
    return 0;
}
*/
