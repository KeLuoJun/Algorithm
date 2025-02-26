// 分成k份的最大乘积
// 一个数字n一定要分成k份，得到的乘积尽量大是多少
// 数字n和k，可能非常大，到达10^12规模
// 结果可能更大，所以返回结果对1000000007取模
// 来自真实大厂笔试，没有在线测试，对数器验证

#include <iostream>
using namespace std;
typedef long long ll;

// 剩余的数字rest拆成k份
// 返回最大乘积
// 暴力尝试一定能得到最优解
int f1(int rest, int k)
{
	if(k == 1) return rest;
	int ans = INT_MIN;
	for(int cur = 1; cur <= rest && (rest - cur) >= (k - 1); cur++){
		int curAns = cur * f1(rest - cur, k - 1);
		ans = max(ans, curAns);
	}
	return ans;
}
// 暴力递归
// 为了验证
// 此题提交暴力接通过不了
// 因为数据非常大，动态规划的过程中如果取模
// 则失去了动态规划比较大小的性质 
int maxValue1(int n, int k)
{
	return f1(n, k);
}


ll power(int x, int n, int mod)
{
	ll ans = 1;
	while(n > 0){
		if((n & 1) == 1){
			ans = (ans * x) % mod;
		}
		x = (x * x) % mod;
		n >>= 1;
	}
	return ans;
}
// 贪心的解
// 这是最优解
// 如果结果很大，那么求余数
int maxValue2(int n, int k)
{
	int mod = 1e9 + 7;
	int a = n / k;
	int b = n % k;
	int part1 = power(a + 1, b, mod);
	int part2 = power(a, k - b, mod);
	return (part1 * part2) % mod;
}


int main()
{
	int num, k;
	cin >> num >> k;
	
	cout << maxValue1(num, k) << endl;
	cout << maxValue2(num, k) << endl;
	return 0;
	
}

