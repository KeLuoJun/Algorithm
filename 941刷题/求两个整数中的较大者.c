# include <stdio.h>
int main()   //����ס����
{
	int max(int x,int y);  //�Ա����ú���max������
	int a,b,c;             //�������a,b,c 
	scanf("%d,%d",&a,&b);  //�������a��b��ֵ 
	c = max(a,b);          //����max���������õ���ֵ����c 
	printf("max=%d\n",c);  //���c��ֵ 
	return 0;              //���غ���ֵΪ0
	 
 } 
 
 //�����������еĽϴ��ߵ�max����
 int max(int x,int y)    //����max����������ֵΪ���ͣ���ʽ����x��yΪ���� 
 {
 	int z;               //max�����еĲ����������֣����屾�������õ��ı���zΪ���� 
 	if(x>y)z=x;          //��x>y��������x��ֵ��������z 
 	else z=y;            //���򣬽�y��ֵ��������z
	return(z);           //��z��ֵ��Ϊmax����ֵ�����ص�����max������λ�� 
 	
  }  
