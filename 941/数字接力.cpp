//A同学在玩一个数字游戏，它们从一个整数开始，比如：6593。将这个整数中的各位数字全部取出，
//将它们相乘，得到一个新的整数，上面的例子就是 6×5×9×3=810，
//然后继续做下去，8×1×0=0 得到了一个个位数 0。
//帮助A同学完成这个游戏，读入一个数并计算出由游戏得到一个个位数的过程。


#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d ",n);
	int x,y,num = n;
 	while(1)
 	{
 		n = num;
 		num = 1;
 		while(n)
 		{
 			x = n % 10;
 			n /= 10;
 			num *= x;			
		}
		printf("%d ",num);
		if(num <= 9)
		 		break;
			else
			 	continue;
		
		 
	 }
	 return 0;
}
