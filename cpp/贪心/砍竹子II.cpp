// 砍竹子II
// 现需要将一根长为正整数bamboo_len的竹子砍为若干段
// 每段长度均为正整数
// 请返回每段竹子长度的最大乘积是多少
// 答案需要对1000000007取模
// 测试链接 : https://leetcode.cn/problems/jian-sheng-zi-ii-lcof/

#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;
typedef long long ll;

ll power(int x, int n)
{
	ll ans = 1;
	while(n > 0){
		if((n & 1) == 1){
			ans = (ans * x) % MOD;
		}
		x = (x * x) % MOD;
		n >>= 1;
	}
	return ans;
}

ll cuttingBamboo(int num)
{
	if(num == 2) return 1;
	if(num == 3) return 2;
	// n = 4  -> 2 * 2
	// n = 5  -> 3 * 2
	// n = 6  -> 3 * 3
	// n = 7  -> 3 * 2 * 2
	// n = 8  -> 3 * 3 * 2
	// n = 9  -> 3 * 3 * 3
	// n = 10 -> 3 * 3 * 2 * 2
	// n = 11 -> 3 * 3 * 3 * 2
	// n = 12 -> 3 * 3 * 3 * 3
	int tail = num % 3 == 0 ? 1 : (num % 3 == 1 ? 4 : 2);
	int n = (tail == 1 ? num : (num - tail)) / 3;
	return (power(3, n) * tail % MOD);
}

int main()
{
	int num;
	cin >> num;
	cout << cuttingBamboo(num) << endl;
	return 0;
}
