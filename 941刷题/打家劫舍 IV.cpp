// 打家劫舍 IV
// 沿街有一排连续的房屋。每间房屋内都藏有一定的现金
// 现在有一位小偷计划从这些房屋中窃取现金
// 由于相邻的房屋装有相互连通的防盗系统，所以小偷不会窃取相邻的房屋
// 小偷的 窃取能力 定义为他在窃取过程中能从单间房屋中窃取的 最大金额
// 给你一个整数数组 nums 表示每间房屋存放的现金金额
// 第i间房屋中放有nums[i]的钱数
// 另给你一个整数k，表示小偷需要窃取至少 k 间房屋
// 返回小偷需要的最小窃取能力值
// 测试链接 : https://leetcode.cn/problems/house-robber-iv/

#include <iostream>
using namespace std;
const int MAXN = 1e5 + 1;
int *nums = new int[MAXN];
int n,k;

int mostRob1(int ability)
{
	if(n == 1)
		return nums[0] <= ability ? 1 : 0;
	if(n == 2)
		return max(nums[0] <= ability ? 1 : 0, nums[1] <= ability ? 1 : 0);
	// 此时的prepre 和 pre 表示的是在当前位置下所能拿的数字的最大数量，而不是数字的累加值 
	int prepre = nums[0] <= ability ? 1 : 0;
	int pre = nums[1] <= ability ? 1 : 0;
	for(int i = 2,cur; i < n; i++){
		cur = max(pre, (nums[i] <= ability ? 1 : 0) + prepre);
		prepre = pre;
		pre = cur; 
	}
	return pre;
}


// 继续贪心优化
// 因为此题只是要求求出在能力不超过nums[i]的情况下所能拿的最大数量，而不是最大累加和
// 故只要遇到nums[i] < ability的数字，直接拿，这能为后面腾出更大的取值空间
// 更容易获得更多的数量 
int mostRob2(int ability)
{
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(nums[i] <= ability)
			ans++;
			i++;
	}
	return ans;
}


int minCapability()
{
	int l = nums[0], r = nums[0];
	for(int i = 1; i < n; i++){
		l = min(l, nums[i]);
		r = max(r, nums[i]);
	}
	int ans = 0;
	while(l <= r){
		int m = l + ((r - l) >> 1);
		if(mostRob2(m) >= k){
			ans = m;
			r = m - 1;
		}
		else
			l = m + 1;
	}
	return ans;
}

int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> nums[i];
	
	cout << minCapability() << endl;
	return 0;
}
