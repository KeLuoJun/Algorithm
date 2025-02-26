// ����ż��������II
// ����һ���Ǹ��������� nums��nums ��һ������������ ��һ��������ż��
// ��������������Ա㵱 nums[i] Ϊ����ʱ��iҲ������
// �� nums[i] Ϊż��ʱ�� i Ҳ�� ż��
// ����Է��� �κ���������������������Ϊ��
// �������� : https://leetcode.cn/problems/sort-array-by-parity-ii/

#include <iostream>
using namespace std;

void swap(int *arr,int n,int m)
{
	arr[n] = arr[n] ^ arr[m];
	arr[m] = arr[n] ^ arr[m];
	arr[n] = arr[n] ^ arr[m];
}

int main()
{
	int n = 7;
	int arr[n] = {3,2,3,5,2,1,8};
	int odd = 1,even = 0;
	//��n-1������ 
	while(odd < n && even < n)
	{
		if((arr[n-1] & 1) == 1)
		{
			swap(arr,odd,n-1);
			odd += 2;
		}
		else
		{
			swap(arr,even,n-1);
			even += 2;
		}
	}
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
} 
