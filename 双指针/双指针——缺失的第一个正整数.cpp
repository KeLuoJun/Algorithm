// 缺失的第一个正数
// 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
// 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
// 测试链接 : https://leetcode.cn/problems/first-missing-positive/

#include <iostream>
#include <algorithm>
using namespace std;
int arr[10000];
int n;

// 时间复杂度O(n)，额外空间复杂度O(1)
void firstMissingPositive()
{
	// l的左边，都是做到i位置上放着i+1的区域
	// 永远盯着l位置的数字看，看能不能扩充(l++)
	int l = 0;
	// [r....]垃圾区
	// 最好的状况下，认为1~r是可以收集全的，每个数字收集1个，不能有垃圾
	// 有垃圾呢？预期就会变差(r--)
	int r = n;
	while(l < r)
	{
		if(arr[l] <= l || arr[l] > r || arr[arr[l] - 1] == arr[l])
			swap(arr[l],arr[--r]);
		else if(arr[l] == l + 1)
			l++;
		else
			swap(arr[l], arr[arr[l] - 1]);
	}
	cout << l + 1 << endl;
}



int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	firstMissingPositive();
	return 0;
} 
