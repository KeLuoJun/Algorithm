//��ϰ7-4 �ҳ������������鹲�е�Ԫ�� (20 ��)
//���������������飬����Ҫ���ҳ��������߹��е�Ԫ�ء�
//��������:
//10 3 -5 2 8 0 3 5 -15 9 100
//11 6 4 8 2 6 -5 9 0 100 8 1
//��β�޿���
//�������:
//3 5 -15 6 4 1
//��β�޿���
#include <stdio.h>
#define max 25
int main()
{
	int m,n;int a[max],b[max];
	scanf("%d",&m);
	for (int i=0;i<m;i++) {
		scanf("%d",&a[i]);
	}
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d",&b[i]);
	}
	
	//ȥ�������й��еľ��ǲ����еģ���c[k]
	int c[40],k=0;int bs[25]={0};
	for (int i=0;i<m;i++) {
		int flag=0;
		for (int j=0;j<n;j++) {
			if (a[i]==b[j]) {
				bs[j]=1;
				flag=1;
			} 
		}
		if (flag==0) c[k++]=a[i];
	} 
	for (int j=0;j<n;j++) {
		if (bs[j]==0) c[k++]=b[j];
	}
	//��ʱ���Ϊ3 3 5 -15 6 4 6 1 ��������������a,b�Լ��ڲ��ظ�Ԫ����ɵģ� 
	int cs[40]={0};	
	for (int i=0;i<k;i++) {
		for (int j=i+1;j<k;j++) {
			if (c[i]==c[j]) cs[j]=1;
		} 
	}
	int end;//��ĩβ��λ�ã�������ո� �� 
	for (int i=k-1;i>=0;i--) {
		if (cs[i]==0) end=i;
	}
	
	for (int i=0;i<k;i++) {
		if (cs[i]==0) printf("%d",c[i]);
		if (i!=end) printf(" "); 
	}
}
