#include <stdio.h>
#include <string.h>
int main()
{
	char s1[260], s2[260];
	int a[260] = {0}, b[260] = {0}, c[260] = {0};
	gets(s1);
	gets(s2);
	//�����λ����ת��
	int lena = strlen(s1);
	int lenb = strlen(s2);
	for(int i = 0; i < lena; i++)
		a[i] = s1[lena-i-1] - '0';
	for(int i = 0; i < lenb; i++)
		b[i] = s2[lenb-i-1] - '0';
	int lenc = lena;
	if(lenb > lenc) lenc = lenb;   //ȡ��������� 
	for(int i = 0; i < lenc; i++)
	{
		// 3.�Ӹ�λ����λ������� 
		c[i] += a[i] + b[i];   //ע��ԭ��c[i]�п�����ԭ���Ĺ�����1 
		if(c[i] > 9)   //��Ҫ��λ 
		{
			c[i+1] = 1;  //��1 
			c[i] = c[i] % 10;  //������λ 
		}
	}
	if(c[lenc] != 0) lenc++;
	for(int i = 0; i < lenc; i++)
		printf("%d",c[lenc-i-1]);
	return 0; 
	
 } 
