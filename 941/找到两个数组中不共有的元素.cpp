//练习7-4 找出不是两个数组共有的元素 (20 分)
//给定两个整型数组，本题要求找出不是两者共有的元素。
//输入样例:
//10 3 -5 2 8 0 3 5 -15 9 100
//11 6 4 8 2 6 -5 9 0 100 8 1
//结尾无空行
//输出样例:
//3 5 -15 6 4 1
//结尾无空行
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
	
	//去掉两组中共有的就是不共有的，记c[k]
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
	//此时输出为3 3 5 -15 6 4 6 1 （这是由于数组a,b自己内部重复元素造成的； 
	int cs[40]={0};	
	for (int i=0;i<k;i++) {
		for (int j=i+1;j<k;j++) {
			if (c[i]==c[j]) cs[j]=1;
		} 
	}
	int end;//找末尾的位置（不输出空格 ； 
	for (int i=k-1;i>=0;i--) {
		if (cs[i]==0) end=i;
	}
	
	for (int i=0;i<k;i++) {
		if (cs[i]==0) printf("%d",c[i]);
		if (i!=end) printf(" "); 
	}
}
