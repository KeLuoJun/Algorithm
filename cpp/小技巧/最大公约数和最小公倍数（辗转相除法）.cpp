#include <iostream>
using namespace std;
typedef long long ll;


// ֤��շת���������֤�����¹�ϵ��
// gcd(a, b) = gcd(b, a % b)
// ����a % b = r������Ҫ֤���Ĺ�ϵΪ��gcd(a, b) = gcd(b, r)
// ֤�����̣�
// ��Ϊa % b = r����������������ʽ��Ȼ����
// 1) a = b * q + r��qΪ0��1��2��3....�е�һ������
// 2) r = a ? b * q��qΪ0��1��2��3....�е�һ������
// ����u��a��b�Ĺ����ӣ�����: a = s * u, b = t * u
// ��a��b����2)�õ���r = s * u - t * u * q = (s - t * q) * u
// ��˵�� : u�����a��b�Ĺ����ӣ���ôuҲ��r������
// ����v��b��r�Ĺ����ӣ�����: b = x * v, r = y * v
// ��b��r����1)�õ���a = x * v * q + y * v = (x * q + y) * v
// ��˵�� : v�����b��r�Ĺ����ӣ���ôvҲ��a�Ĺ�����
// ���ϣ�a��b��ÿһ�������� Ҳ�� b��r��һ�������ӣ���֮��Ȼ
// ���ԣ�a��b��ȫ�幫���Ӽ��� = b��r��ȫ�幫���Ӽ���
// ��gcd(a, b) = gcd(b, r)
// ֤������

//���Լ�� 
ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}
 
//��С������ 
ll lcm(ll a, ll b)
{
	return a / gcd(a, b) * b;
}


int main()
{
	int a = 22,b = 10;
	int num1 = gcd(a,b); 
	int num = lcm(a,b);
	cout << num << endl;
	cout << num1 << endl;
	return 0;
}
