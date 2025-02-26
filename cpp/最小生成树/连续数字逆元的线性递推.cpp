// ����������Ԫ�����Ե���
// ����n��p����1��n������������ģp�����µĳ˷���Ԫ
// 1 <= n <= 3 * 10^6
// n < p < 20000528
// ���뱣֤pΪ����
// �������� : https://www.luogu.com.cn/problem/P3811

#include <iostream>
using namespace std;
const int N = 3000001;
int inv[N];
int n,p;

void build()
{
	inv[1] = 1;
	for(int i = 2; i <= n; i++){
		// ��������Ԫ��ʽ 
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
