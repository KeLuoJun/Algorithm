#include <stdio.h>
#include <math.h>
int main()
{
	int a[80] = {0};
	char ch;
	int n = 1,s = 0;
	while(scanf("%c",&ch), ch != '#')
	{
		if(ch >= '0' && ch <= '9')
		{
			a[n] = (int)ch - '0';
			n++;
		}
		else if(ch >= 'A' && ch <= 'F')  //细节，是A到F 
		{
			a[n] = (int)ch - 55;  //细节，不是ch-'A',因为16进制的A的值为10 
			n++;
		}
		else if(ch >= 'a' && ch <= 'f')
		{
			a[n] = (int)ch - 87;
			n++;
		}
		else if(ch == '-' && n == 1){ 
			a[0] = -1;
			}
		else continue; 
	}
	n--;
	for(int i = 0; n > 0; --n,++i)
		s += a[n] * pow(16,i);
		
	if(a[0] == -1)
		s *= -1;
	printf("%d\n",s);
	return 0;
}
