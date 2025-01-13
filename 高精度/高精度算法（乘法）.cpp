#include <stdio.h>
#include <string.h> 
#define N 10000000
int t;
char s1[N],s2[N];
int a[N] = {0},b[N] = {0},c[N] = {0};


void save_int(char s[],int arr[])
{
	int len = strlen(s);
	for(int i = 0; i < len; i++)
		arr[i] = s[len-i-1] - '0';
}


int multiply()
{
	memset(c, 0, N);
	save_int(s1,a);
	save_int(s2,b);
	int lena = strlen(s1);
	int lenb = strlen(s2);
	for(int i = 0; i < lena; i++)
	{
		for(int j = 0; j < lenb; j++)
		{
			c[i+j] += a[i] * b[j];
			if(c[i+j] > 9)
			{
				c[i+j+1] += c[i+j] / 10;
				c[i+j] %= 10;
			}
		}
	}
	int lenc = lena + lenb;
	if(c[lenc]) lenc++;  //最后进位
	while(c[lenc-1] == 0 && lenc > 1) lenc--;  //去除当乘除为0时得到结果中多余的0
	return lenc; 
}
int main()
{
	scanf("%d", &t);
	while(t--){
		scanf("%s",s1);
		scanf("%s",s2);
		int len = multiply();
		for(int i = 0; i < len; i++)
			printf("%d",c[len-i-1]);
		printf("\n");
	}
	return 0;
 } 
 

