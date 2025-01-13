// 可以翻转1次的情况下子数组最大累加和
// 给定一个数组nums，
// 现在允许你随意选择数组连续一段进行翻转，也就是子数组逆序的调整
// 比如翻转[1,2,3,4,5,6]的[2~4]范围，得到的是[1,2,5,4,3,6]
// 返回必须随意翻转1次之后，子数组的最大累加和
// 对数器验证

#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
const int N = 1e5;
int n;
int arr[N];

// nums[l...r]范围上的数字进行逆序调整
void reverse(int l, int r)
{
	while(l < r){
		int tmp = arr[l];
		arr[l++] = arr[r];
		arr[r--] = tmp;
	}
}
// 返回子数组最大累加和
int maxSum()
{
	int ans = arr[0];
	for(int i = 1, pre = arr[0]; i < n; i++){
		pre = max(arr[i], pre + arr[i]);
		ans = max(ans, pre);
	}
	return ans;
}

// 暴力方法
// 为了验证
int maxSumReverse1()
{
	int ans = INT_MIN;
	for(int l = 0; l < n; l++){
		for(int r = l; r < n; r++){
			reverse(l, r);
			ans = max(ans, maxSum());
			reverse(l, r);
		} 
	}
	return ans;
}


// 正式方法
// 时间复杂度O(n)
int maxSumReverse2()
{
	// start[i] : 所有必须以i开头的子数组中，最大累加和是多少
	int *start = new int[n];
	start[n - 1] = arr[n - 1];
	for(int i = n - 2; i >= 0; i--){
		// nums[i]
		// nums[i] + start[i+1]
		start[i] = max(arr[i], arr[i] + start[i + 1]);
	}
	
	int ans = start[0];
	// end : 子数组必须以i-1结尾，其中的最大累加和
	int end = arr[0]; // 与 start 性质相反 
	// maxEnd :
	// 0~i-1范围上，
	// 子数组必须以0结尾，其中的最大累加和
	// 子数组必须以1结尾，其中的最大累加和
	// ...
	// 子数组必须以i-1结尾，其中的最大累加和
	// 所有情况中，最大的那个累加和就是maxEnd
	int maxEnd = arr[0];
	for(int i = 1; i < n; i++){
		// maxend   i....
		// 枚举划分点 i...
		ans = max(ans, maxEnd + start[i]);
		// 子数组必须以i结尾，其中的最大累加和
		end = max(arr[i], end + arr[i]);
		maxEnd = max(maxEnd, end);
	}
	// 有可能不用反转（即单独一个数自己反转） 
	ans = max(ans, maxEnd);
	return ans;
}

int main()
{
	srand((unsigned)time(NULL));
	int testTime = 200;
	cout << "测试开始" << endl;
	while(testTime--){
		n = rand() % 20;
		for(int i = 0; i < n; i++){
			arr[i] = rand() % 200 - 50;
		}
		int ans1 = maxSumReverse1(); // 有点小问题 
		int ans2 = maxSumReverse2();
		cout << ans1 << " " << ans2 << endl;
		if(ans1 != ans2){
			cout << "出错了" << endl;
		}
	}
	cout << "测试结束" << endl;
	return 0;
}
