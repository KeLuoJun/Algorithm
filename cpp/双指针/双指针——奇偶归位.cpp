// 按奇偶排序数组II
// 给定一个非负整数数组 nums。nums 中一半整数是奇数 ，一半整数是偶数
// 对数组进行排序，以便当 nums[i] 为奇数时，i也是奇数
// 当 nums[i] 为偶数时， i 也是 偶数
// 你可以返回 任何满足上述条件的数组作为答案
// 测试链接 : https://leetcode.cn/problems/sort-array-by-parity-ii/

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
	//从n-1处发货 
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
