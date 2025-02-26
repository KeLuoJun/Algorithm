#include <stdio.h>
#include <string.h>
int main()
{
	char s1[260], s2[260];
	int a[260] = {0}, b[260] = {0}, c[260] = {0};
	gets(s1);
	gets(s2);
	//对齐个位（反转）
	int lena = strlen(s1);
	int lenb = strlen(s2);
	for(int i = 0; i < lena; i++)
		a[i] = s1[lena-i-1] - '0';
	for(int i = 0; i < lenb; i++)
		b[i] = s2[lenb-i-1] - '0';
	int lenc = lena;
	if(lenb > lenc) lenc = lenb;   //取两者中最长的 
	for(int i = 0; i < lenc; i++)
	{
		// 3.从个位往高位依次相加 
		c[i] += a[i] + b[i];   //注意原来c[i]中可能有原来寄过来的1 
		if(c[i] > 9)   //需要进位 
		{
			c[i+1] = 1;  //进1 
			c[i] = c[i] % 10;  //保留个位 
		}
	}
	if(c[lenc] != 0) lenc++;
	for(int i = 0; i < lenc; i++)
		printf("%d",c[lenc-i-1]);
	return 0; 
	
 } 
