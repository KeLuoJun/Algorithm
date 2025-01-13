// 连续数字逆元的线性递推
// 给定n、p，求1～n中所有整数在模p意义下的乘法逆元
// 1 <= n <= 3 * 10^6
// n < p < 20000528
// 输入保证p为质数
// 测试链接 : https://www.luogu.com.cn/problem/P3811

#include <iostream>
using namespace std;
const int N = 3000001;
int inv[N];
int n,p;

void build()
{
	inv[1] = 1;
	for(int i = 2; i <= n; i++){
		// 求连续逆元公式 
		inv[i] = (int)(p - (long) inv[p % i] * (p / i) % p);
	}
}


int main()
{
	cin >> n >> p;
	build();
	for(int i = 1; i <= n; i++){
		cout << inv[i] << endl;
	}
	return 0;
 } 
