#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i,j;
	int row = 4,col = 5;
	//������� ������һ��
/* 
	int **ar = (int**)malloc(row * sizeof(int*));  //(int *)  ��©*��
	for(i = 0; i < row; i++)
		ar[i] = (int*)malloc(col * sizeof(int*)); 
*/
	//������
	int (*ar)[col] = (int(*)[col])malloc(sizeof(int) * row * col); //(*ar) ���Ų�����,[]���ȼ��ߣ����˾���ָ��������
		
	//��ӡ��ַ
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			printf("%p ",ar[i][j]);
		 } 
		printf("\n");
	}
	
	//�ͷ��ڴ�
	for(i = 0;  i < row; i++)
		free(ar[i]);    //����ͬʱ�ͷţ���һά����һ����
	free(ar);
	return 0;	 
 } 
 
//��������һά����ģ�⵽��ά���飩 
/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j;
    int row = 4,col = 5;
    
    //����һ�� 4�� 5�еĶ�ά����
    int *ar =(int*)malloc(sizeof(int) * row * col);
    
    for (i = 0;i < row;i++)
    {
        for (j = 0;j < col;j++)
        {
            printf("%p  ",&ar[i * col + j]);   //��ά�������Դ洢 
        }
        printf("\n");
    }
    free(ar);
    return 0;
}
*/
