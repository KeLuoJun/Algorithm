#include <stdio.h>
int main()

{
	char str1[50],str2[50];
//	scanf("%s%s",str1,str2);     //×Ö·û´®²»º¬¿Õ¸ñ 
	gets(str1);
	gets(str2);
	printf("str1 = %s\n",str1);
	printf("str2 = %s\n",str2);
	return 0;

}
