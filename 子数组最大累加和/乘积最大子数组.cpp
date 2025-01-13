// 乘积最大子数组
// 给你一个整数数组 nums
// 请你找出数组中乘积最大的非空连续子数组
// 并返回该子数组所对应的乘积
// 测试链接 : https://leetcode.cn/problems/maximum-product-subarray/

#include <iostream>
using namespace std;
const int N = 1e5;
int n;
int arr[N];

int maxProduct()
{
	int ans = arr[0];
	int maxnum = arr[0];
	int minnum = arr[0];
	int curmax, curmin;
	for(int i = 1; i < n; i++){
		curmin = min(arr[i], min(minnum * arr[i], maxnum * arr[i]));
		curmax = max(arr[i], max(minnum * arr[i], maxnum * arr[i]));
		minnum = curmin;
		maxnum = curmax;
		ans = max(ans, maxnum);
	}
	return ans;
}



int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int ans = maxProduct();
	cout << ans << endl;
	return 0;
	
 } 
