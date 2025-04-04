#include <stdio.h>
int main()
{
	int num[10],i,j;
	for(i=0; i<=9; i++)
		num[i] = 0;  //初始化每个小房间为0 
		
	for(i=1; i<=5; i++)
	{
		scanf("%d",&j);   //依次输入5个数 
		num[i] = 1;       //把对应的小房间改为1 
	 }
	
	for(i=0; i<=9; i++)
		if(num[i] == 0)    //输出没有出现过的数 
			printf("%d ",i);
	
	return 0; 
}

