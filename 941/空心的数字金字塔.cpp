#include <stdio.h> 
int main()
{
	int n;
	scanf("%d",&n);
	int i, row=1; //row��¼����
	for( ; row<=n; row++ ){
		for( i=1; i<=n-row; i++ ){
			printf(" ");
		} //�������ǰ�ո񣬹�n-row��
		if(row==1)
			printf("1"); //��һ��ֻ��1�����֣��������
		else if(row>1&&row<n){
			printf("%d", row); //����м�ĳ�е�һ������
			for(i=1; i<=2*row-3; i++){
				printf(" ");
			} //���������֮��ո񣬹�2row-3��
			printf("%d", row); //����м�ĳ�еڶ�������
		}else if(row==n){
			for(i=1; i<=2*row-1; i++){
				printf("%d", row);
			} //�����n������
		}
		printf("\n");
	}
}
