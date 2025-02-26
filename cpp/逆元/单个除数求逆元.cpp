// ������������Ԫ

#include <iostream>
using namespace std;
typedef long long ll;

// �˷�������
// ����b��n�η��Ľ��%mod
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
	// ��Ԫ��ʽ inv  (a/b)%mod -> (a * 1/b)mod -> (a%mod * (b^mod-2)%mod)%mod 
	// b^mod-2 �ļ��������Ҳ����ÿһ����mod 
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
