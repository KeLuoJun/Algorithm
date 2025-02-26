// 寻找重复数
// 给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n）
// 可知至少存在一个重复的整数。
// 假设 nums 只有 一个重复的整数 ，返回 这个重复的数 。
// 你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间。
// 测试链接 : https://leetcode.cn/problems/find-the-duplicate-number/

#include <iostream>
using namespace std;

int main()
{
	int n = 8;
	int arr[n] = {2,5,7,4,9,5,3,1};
	//快慢指针找到入环点即为重复的元素 
	int fast = arr[arr[0]];
	int slow = arr[0];
	//fast一次走两步，slow一次走一步 
	while(fast != slow)
	{
		fast = arr[arr[fast]];
		slow = arr[slow];
	}
	//第一次相遇之后，fast回到起始位置，之后fast一次走一步 
	fast = arr[0];
	//快慢指针再次相遇
	while(fast != slow)
	{
		fast = arr[fast];
		slow = arr[slow];
	}
	cout << fast << endl;
	return 0; 
} 
