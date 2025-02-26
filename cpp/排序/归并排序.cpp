//归并排序
//时间复杂度 O(N*logN) 

#include <iostream>
using namespace std;
#define MAX 501

int arr[MAX];
int help[MAX];

void merge(int l, int m, int r)
{
	int i = l;
	int a = l;
	int b = m + 1;
	while(a <= m && b <= r)
	{
		help[i++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
	}
	while(a <= m)
		help[i++] = arr[a++];
	while(b <= r)
		help[i++] = arr[b++];
	//复原 
	for(i = l; i <= r; i++)
		arr[i] = help[i];
}

//递归版 
void mergeSort1(int l, int r)
{
	if(l == r)
		return;
	int m = (l + r) / 2;
	mergeSort1(l,m);
	mergeSort1(m+1,r);
	merge(l,m,r);
}

int min(int a, int b)
{  
	return a > b ? b : a;
}

//非递归版 
void mergeSort2(int n)
{
	int l,m,r;
	//step 为每次划分的步长
	//l...m  m+1...r 
	for(int step = 1; step < n; step <<= 1)
	{
		l = 0;
		while(l < n)
		{
			m = l + step - 1;
			if(m+1 >= n)	
				//已经没有右侧了 
				break;
			//有右侧，求右侧的有右边界（可能右侧不足step个）
			r = min(m+step,n-1);
			merge(l,m,r);
			l = r + 1;
		}
	}
} 

void test()
{
	int num;
	cout << "请输入要排序数字的个数：";
	cin >> num;
	cout << "请输入要排序的数字：" ;
	for(int i = 0; i < num; i++)
		cin >> arr[i];
	//mergeSort1(0,num-1);
	mergeSort2(num);
	cout << "排序后的结果：" << endl;
	for(int i = 0; i < num; i++)
		cout << arr[i] << " ";
	cout << endl;
} 

int main()
{
	test();
	system("pause");
	return 0;
}

