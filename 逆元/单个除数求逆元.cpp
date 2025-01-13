// 单个除数求逆元

#include <iostream>
using namespace std;
typedef long long ll;

// 乘法快速幂
// 计算b的n次方的结果%mod
ll power(ll b, int n, int mod)
{
	ll ans = 1;
	while(n > 0){
		if((n & 1) == 1){
			ans = (ans * b) % mod;
		}
		b = (b * b) % mod;
		n >>= 1;
	}
	return ans;
}

int compute(ll a, ll b, int mod)
{
	// 逆元公式 inv  (a/b)%mod -> (a * 1/b)mod -> (a%mod * (b^mod-2)%mod)%mod 
	// b^mod-2 的计算过程中也可以每一步都mod 
	ll inv = power(b, mod - 2, mod);
	return (int)(((a % mod) * inv) % mod);
}


int main()
{
	int mod = 41;
	ll b = 3671613;
	ll a = 67312 * b;
	cout << compute(a, b, mod);
	return 0;
} 
