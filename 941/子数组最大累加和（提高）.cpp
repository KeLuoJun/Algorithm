// 如下代码为附加问题的实现
// 子数组中找到拥有最大累加和的子数组
// 并返回如下三个信息:
// 1) 最大累加和子数组的开头left
// 2) 最大累加和子数组的结尾right
// 3) 最大累加和子数组的累加和sum
// 如果不止一个子数组拥有最大累加和，那么找到哪一个都可以
// 测试链接 : https://leetcode.cn/problems/maximum-subarray/

#include <iostream>
using namespace std;
const int MAXN = 1e5+1;
int *nums = new int[MAXN];
int sum = INT_MIN;
int n;


void extra(int &left, int &right)
{
	int l = 0,r = 1;
	for(int i = 1,pre = nums[0]; i < n; i++,r++){
		if(pre > 0){
			pre += nums[i];
		}
		else{
			pre = nums[i];
			l = r;
		}
		if(pre > sum){
			sum = pre;
			left = l;
			right = r;
		}
	}
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> nums[i];
	}
	int left,right;
	extra(left,right);
	cout << left << right << sum << endl;
	return 0;
}

