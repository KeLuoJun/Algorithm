// �ֳ�k�ݵ����˻�
// һ������nһ��Ҫ�ֳ�k�ݣ��õ��ĳ˻��������Ƕ���
// ����n��k�����ܷǳ��󣬵���10^12��ģ
// ������ܸ������Է��ؽ����1000000007ȡģ
// ������ʵ�󳧱��ԣ�û�����߲��ԣ���������֤

#include <iostream>
using namespace std;
typedef long long ll;

// ʣ�������rest���k��
// �������˻�
// ��������һ���ܵõ����Ž�
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
// �����ݹ�
// Ϊ����֤
// �����ύ������ͨ������
// ��Ϊ���ݷǳ��󣬶�̬�滮�Ĺ��������ȡģ
// ��ʧȥ�˶�̬�滮�Ƚϴ�С������ 
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
// ̰�ĵĽ�
// �������Ž�
// �������ܴ���ô������
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

