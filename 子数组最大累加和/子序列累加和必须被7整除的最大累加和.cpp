// 子序列累加和必须被7整除的最大累加和
// 给定一个非负数组nums，
// 可以任意选择数字组成子序列，但是子序列的累加和必须被7整除
// 返回最大累加和
// 对数器验证

#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
using namespace std;
const int N = 1e5;
int n;
int arr[N];

// 暴力方法
// 为了验证
int f(int i, int s)
{
	if(i == n){
		return s % 7 == 0 ? s : 0;
	}
	return max(f(i + 1, s + arr[i]), f(i + 1, s));
}
int maxSum1()
{
	// nums形成的所有子序列的累加和都求出来
	// 其中%7==0的那些累加和中，返回最大的
	// 就是如下f函数的功能
	return f(0, 0);
}

// 正式方法
// 时间复杂度O(n)
int maxSum2()
{
	int (*dp)[7] = new int[n + 1][7];
	memset(dp, 0, sizeof dp);  // 初始化dp表 
	// dp[i][j] : nums[0...i-1]
	// nums前i个数形成的子序列一定要做到，子序列累加和%7 == j
	// 这样的子序列最大累加和是多少
	// 注意 : dp[i][j] == -1代表不存在这样的子序列
	dp[0][0] = 0;
	for(int j = 1; j < 7; j++){
		dp[0][j] = -1;
	}
	
	for(int i = 1, x, cur, need; i <= n; i++){
		x = arr[i - 1];
		cur = arr[i - 1] % 7;
		for(int j = 0; j < 7; j++){
			dp[i][j] = dp[i - 1][j];
			// 这里求need是核心
			need = cur <= j ? (j - cur) : (j + 7 - cur);
			// 或者如下这种写法也对
			// need = (7 + j - cur) % 7;
			if(dp[i - 1][need] != -1){
				dp[i][j] = max(dp[i][j], dp[i - 1][need] + x);
			}
		}
	}
	return dp[n][0];
}

// 为了测试
// 生成随机数组
int randomArray(int v)
{
	for(int i = 0; i < n; i++){
		arr[i] = rand() % (v + 1);
	}
}


// 为了测试
// 对数器
int main()
{
	srand((unsigned)time(NULL));
	int v = 10000;
	int testTime = 2000;
	cout << "测试开始" << endl;
	for(int i = 0; i < testTime; i++){
		n = rand() % 15;  // 由于 maxSum1 方法采用递归，因此数组不能开太大 
		randomArray(v);
		int ans1 = maxSum1();
		int ans2 = maxSum2();
		if(ans1 != ans2){
			cout << "第" << i << "组出错了" << endl;
		}else{
			cout << "第" << i << "组测试成功" << endl; 
		}
	}
	cout << "测试结束" << endl;
	return 0;
}


