#include <stdio.h>
int main()
{
	int num, sum = 0;
	scanf("%d",&num);
	
	while(num > 0){   //实现各个位数上的数字的提取
	//因为num是整数，所以最终会就变为零 
		sum += num % 10;   //%10实现对该数字个位数上数字的提取 
		num /= 10;         // /10实现对该数字个位数的去除 
	}
	printf("%d",sum);
	return 0;
}
