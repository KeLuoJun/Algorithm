//选择排序
//时间复杂度 O(N^2)

#include <iostream>
using namespace std;

void swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
 } 
 
void SelectSort(int *arr,int n)
{
	for(int i = 0; i < n-1; i++)
	{
		int min = i;
		for(int j = i+1; j < n; j++)
		{
			if(arr[j] < arr[min])
				min = j;
		}
		swap(arr[i],arr[min]);
	}
} 

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for(int i = 0; i < n; i++)	
		cin >> arr[i];
	SelectSort(arr,n);
	for(int i = 0; i < n; i++)	
		cout << arr[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}
