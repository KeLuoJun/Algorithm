// 环形数组中不能选相邻元素的最大累加和
// 给定一个数组nums，长度为n
// nums是一个环形数组，下标0和下标n-1是连在一起的
// 可以随意选择数字，但是不能选择相邻的数字
// 返回能得到的最大累加和
// 测试链接 : https://leetcode.cn/problems/house-robber-ii/

#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 101;
int *nums = new int[MAXN];
int n;

int best(int l, int r)
{
	if(l > r)
		return 0;
	if(l == r)
		return nums[l];
	if(l == r - 1)
		return max(nums[l], nums[r]);
	int prepre = nums[l];
	int pre = max(nums[l], nums[l + 1]);
	for(int i = l + 2, cur; i <= r; i++){
		cur = max(pre, max(nums[i], prepre + nums[i]));
		prepre = pre;
		pre = cur;
	}
	return pre;	
}



int rob()
{
	if(n == 1)
		return nums[0];
	// best(1, n - 1) 表示不拿nums[0]位置的数，则继续从 1 到 n-1 位置的数中得到最好情况
	// nums[0] + best(2, n - 2) 表示拿nums[0]位置的数，则继续从 2 到 n-2 位置的数中得到最好情况
	return max(best(1, n - 1), nums[0] + best(2, n - 2));
}


int main()
{
	cin >> n; 
	for(int i = 0; i < n; i++){
		cin >> nums[i];
	}
	cout << rob() << endl;
	return 0;
}
