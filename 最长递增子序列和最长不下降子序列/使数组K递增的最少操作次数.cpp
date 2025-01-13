// 使数组K递增的最少操作次数
// 给你一个下标从0开始包含n个正整数的数组arr，和一个正整数k
// 如果对于每个满足 k <= i <= n-1 的下标 i
// 都有 arr[i-k] <= arr[i] ，那么称 arr 是K递增的
// 每一次操作中，你可以选择一个下标i并将arr[i]改成任意正整数
// 请你返回对于给定的 k ，使数组变成K递增的最少操作次数
// 测试链接 : https://leetcode.cn/problems/minimum-operations-to-make-the-array-k-increasing/

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1;
int arr[MAXN];
int nums[MAXN];
int n,k;

int bs(int *ends, int len, int num)
{
	int l = 0, r  = len - 1, ans = -1;
	while(l <= r){
		int m = l + ((r - l) >> 1);
		if(ends[m] > num){
			ans = m;
			r = m - 1;
		}else{
			l = m + 1;
		}
	}
	return ans;
}

// nums[0...size-1]中的最长不下降子序列长度
int lengthOfNoDecreasing(int size)
{
	int *ends = new int[size];
	int len = 0;
	for(int i = 0; i < size; i++){
		int find = bs(ends, len, nums[i]);
		if(find == -1){
			ends[len++] = nums[i];
		}else{
			ends[find] = nums[i];
		}
	}
	return len;
}

int kIncreasing()
{
	int ans = 0;
	for(int i = 0; i < k; i++){
		int size = 0;
		// 把每一组的数字放入容器
		for(int j = i; j < n; j += k){
			nums[size++] = arr[j];
		}
		// 当前组长度 - 当前组最长不下降子序列长度 = 当前组至少需要修改的数字个数
		ans += size - lengthOfNoDecreasing(size);
	}
	return ans;
}


int main()
{
	srand((unsigned)time(NULL));
	n = rand() % (MAXN + 1);
	k = rand() % n;
	cout << n << " " << k << endl;
	for(int i = 0; i < n; i++){
		arr[i] = rand() % (MAXN + 1);
		cout << arr[i] << " ";
		if(i % 9 == 0)
			cout << endl;
	}
	cout << endl;
	cout << kIncreasing() << endl;
	return 0;
}
