# include <stdio.h>
int main()
{
	int a,b,c;   //�������a,b,c 
	scanf("%d,%d,%d",&a,&b,&c);    //�������a,b,c
	int d; 
	int max(int a,int b,int c);    //�Ա����ú���max������ 
	d = max(a,b,c);    //����max���������õ��Ľ����ֵ��d
	printf("max=%d\n",d);   //���d��ֵ 
	return 0; 
 } 
 
 //�����������еĽϴ��ߵ�max����
int max(int a,int b,int c)
{
   int z;
   if(a>b){
   	if(a>c){
   		z = a;
   		return z;
	   }else{
	   	  z = c;
	   	  return z;
	   }
   } else{
   	if(b>c){
   		z = b;
   		return z;
	   }else{
	   	z = c;
	   	return z;
	   }
   }
}

 


