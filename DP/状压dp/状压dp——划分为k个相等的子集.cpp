// 划分为k个相等的子集
// 给定一个整数数组  nums 和一个正整数 k，
// 找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。
// 测试链接 : https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/

#include <iostream>
using namespace std;
//typedef long long ll;
const int MAXN = 1e8 + 1;
int n,k,sum = 0;
int *nums = new int[MAXN]; 

bool f(int limit, int status, int cur, int rest, int *dp)
{
	if(rest == 0)
		return status == 0;
	if(dp[status] != 0)
		return dp[status] == 1;
	bool ans = false;
	for(int i = 0; i < n; i++){
		if((status & (1 << i)) != 0 && cur + nums[i] <= limit){
			if(cur + nums[i] == limit){
				ans = f(limit, status ^ (1 << i), 0, rest - 1, dp);
			}
			else{
				ans = f(limit, status ^ (1 << i), cur + nums[i], rest, dp);
			}
			if(ans) break;
		}
	}
	dp[status] = ans ? 1 : -1;
	return ans;
	
}

bool solve()
{
	if(sum % k != 0)
		return false;
	int *dp = new int[1 << n];
	return f(sum / k, (1 << n) - 1, 0, k, dp);
}
int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> nums[i];
		sum += nums[i];
	}
	if(solve())
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
}
