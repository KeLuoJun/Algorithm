//插入排序
//时间复杂度 O(N*2)

#include <iostream>
using namespace std;

void swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void InsertSort(int *arr,int n)
{
	//i 为有序数组的边界 
	for(int i = 1; i < n; i++)
	{
		for(int j = i-1; j >= 0; i--)
		{
			if(arr[j] > arr[j+1])
				swap(arr[j],arr[j+1]);
			else
				break;
		}
	}
} 

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for(int i = 0; i < n; i++)	
		cin >> arr[i];
	InsertSort(arr,n);
	for(int i = 0; i < n; i++)	
		cout << arr[i] << " " ;
	cout << endl;
	system("pause");
	return 0;
}
