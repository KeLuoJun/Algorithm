/*给定一个包含 n + 1 个整数的数组 nums ，
其数字都在 [1，n] 范围内 (包括 1 和 n)可知至少存在一个重复的整数。
假设 nums只有 一个重复的整数 ，
返回 这个重复的数
你设计的解决方案必须不修改数组 nums 且只用常量级 0(1) 的外空间。
*/

#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[100];
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);    //只能输入1--(n-1) 上的数字
		
	int slow = a[0];
	int fast = a[a[0]];
	while(slow != fast)
	{
		fast = a[a[fast]];
		slow = a[slow];
	} 
	fast = 0;
	while(fast != slow)
	{
		fast = a[fast];
		slow = a[slow];
	}
	printf("%d",slow);
	return 0;
}
