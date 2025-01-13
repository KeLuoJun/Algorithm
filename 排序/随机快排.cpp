//随机快速排序
//时间复杂度 O(N*logN) 

//优化版（荷兰国旗问题）
//已知arr[l....r]范围上一定有x这个值
//划分数组  <x放左边  ==x放中间  >x放右边
//把全局变量first, last 更新成==x区域的左右边界

#include <iostream>
#include <time.h>
#include<stdlib.h>
using namespace std;
#define MAXSIZE 1000

int arr[MAXSIZE];
int first;  //小于x的越界左边界 
int last;   //大于x的越界右边界 

void swap(int l,int r)
{
	int temp = arr[l];
	arr[l] = arr[r];
	arr[r] = temp;
}

void partition(int l,int r,int x)
{
	first = l;
	last = r;
	int i = l;  //扫描改段数组
	while(i <= last)
	{
		if(arr[i] == x)
			i++;
		else if(arr[i] < x)
			//交换之后由于i上的数是从数组的左边换来的
			//而数组i的左边是已经扫描过的
			//因此不用再对交换之后i上的数进行扫描，直接扫描下一位 
			swap(first++,i++);
		else if(arr[i] > x)
			//交换之后i上的数是从数组的右边换来的
			//而数组i的右边还未扫描过 
			//因此需要再对交换之后i上的数进行扫描
			swap(i,last--);
	} 
} 

void quickSort(int l,int r)
{
	srand((unsigned)time(0));
	if(l >= r)
		return;
	int x = arr[l + (int)rand()%(r-l+1)];
	partition(l,r,x);
	//为了防止底层的递归过程覆盖全局变量
	//这里用临时变量记录first、last 
	int left = first;
	int right = last;
	quickSort(l,left-1);
	quickSort(right+1,r);
}


int main()
{
	int n;
	cout << "请输入数组的长度：" << endl;
	cin >> n;
	cout << "请输入数据的数据：" << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	quickSort(0,n-1);
	cout << "排序后的数组为：" << endl;
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	system("pause");
	return 0;
} 
