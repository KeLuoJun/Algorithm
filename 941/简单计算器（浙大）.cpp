/*
��������������ȼ���ͬ���������ҵ�˳�����
1+2*10-10/2=10  
*/
#include <stdio.h>
int main()
{
    int a,b,flag = 0;
    char op;
    scanf("%d",&a);
    while((op = getchar()) != '=')
    {
    	if(op == '+')
    	{
    		scanf("%d",&b);
    		a += b;
		}
		else if(op == '-')
		{
			scanf("%d",&b);
			a -= b;
		}
		else if(op == '*')
		{
			scanf("%d",&b);
			a *= b;
		}
		else if(op == '/')
		{
			scanf("%d",&b);
			if(b == 0)
				flag = 1;
			else
				a /= b;
		}
		else
			flag = 1;
	}
	if(flag)
		printf("ERROR\n");
	else
		printf("%d\n",a);
    return 0;
}
