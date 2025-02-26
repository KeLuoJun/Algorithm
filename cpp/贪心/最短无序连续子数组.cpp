// 最短无序连续子数组
// 给你一个整数数组nums，你需要找出一个 连续子数组
// 如果对这个子数组进行升序排序，那么整个数组都会变为升序排序
// 请你找出符合题意的最短子数组，并输出它的长度
// 测试链接 : https://leetcode.cn/problems/shortest-unsorted-continuous-subarray/

#include <iostream>
using namespace std;
const int MAXN = 1e6;
int n;
int arr[MAXN];

int findUnsortedSubarray()
{
	// max > 当前数，认为不达标
	// 从左往右遍历，记录最右不达标的位置
	int right = -1;
	int maxx = INT_MIN;
	for(int i = 0; i < n; i++){
		if(maxx > arr[i]){
			right = i;
		}
		maxx = max(maxx, arr[i]);
	}
	// min < 当前数，认为不达标
	// 从右往左遍历，记录最左不达标的位置
	int minn = INT_MAX;
	int left = n;
	for(int i = n - 1; i >= 0; i--){
		if(minn < arr[i]){
			left = i;
		}
		minn = min(minn, arr[i]);
	}
	return max(0, right - left + 1);
}


int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cout << findUnsortedSubarray() << endl;
	return 0;
 } 
