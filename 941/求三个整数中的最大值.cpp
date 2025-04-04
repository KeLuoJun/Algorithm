# include <stdio.h>
int main()
{
	int a,b,c;   //定义变量a,b,c 
	scanf("%d,%d,%d",&a,&b,&c);    //输入变量a,b,c
	int d; 
	int max(int a,int b,int c);    //对被调用函数max的声明 
	d = max(a,b,c);    //调用max函数，将得到的结果赋值给d
	printf("max=%d\n",d);   //输出d的值 
	return 0; 
 } 
 
 //求三个整数中的较大者的max函数
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

 


