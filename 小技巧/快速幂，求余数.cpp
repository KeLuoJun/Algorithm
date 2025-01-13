#include <iostream>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

// 快速幂，求余数
// 求x的n次方，最终得到的结果 % mod
int power(ll x, int n)
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


int main()
{
	ll x;
	int n;
	cin >> x >> n;
	cout << power(x, n) << endl;
	return 0;
 } 
