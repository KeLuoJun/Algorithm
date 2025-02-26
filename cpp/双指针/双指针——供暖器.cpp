// ��ů��
// �����Ѿ����١� ������������һ���й̶����Ȱ뾶�Ĺ�ů�������з��ݹ�ů��
// �ڼ������ļ��Ȱ뾶��Χ�ڵ�ÿ�����ݶ����Ի�ù�ů��
// ���ڣ�����λ��һ��ˮƽ���ϵķ��� houses �͹�ů�� heaters ��λ��
// �����ҳ������ؿ��Ը������з��ݵ���С���Ȱ뾶��
// ˵�������й�ů������ѭ��İ뾶��׼�����ȵİ뾶Ҳһ����
// �������� : https://leetcode.cn/problems/heaters/

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int n,m;
int houses[10000];
int heaters[10000];

// ����������壺
// ��ǰ�ĵص�houses[i]��heaters[j]����ů�����ŵ���
// ��ǰ�ĵص�houses[i]��heaters[j]����ů�������İ뾶��a
// ��ǰ�ĵص�houses[i]��heaters[j + 1]����ů�������İ뾶��b
// ���a < b, ˵�������ţ���ů��Ӧ������һ��λ��
// ���a >= b, ˵���������ţ�Ӧ������һ��λ��
bool best(int i,int j)
{
	if(j == m-1)
		return true;
	else
	{
		if(abs(houses[i] - heaters[j]) <= abs(houses[i] - heaters[j+1]))
			return true;
		else
			return false;
	}
}


// ʱ�临�Ӷ�O(n * logn)����Ϊ�����򣬶���ռ临�Ӷ�O(1)
void findRadius()
{
	int ans = 0;
	sort(houses, houses + n);
	sort(heaters, heaters + m);
	int i = 0,j = 0;  //i������  j����ů�� 
	for( ; i < n; i++)
	{
		while(!best(i,j))
			j++;
		ans = max(ans, abs(houses[i] - heaters[j]));
	}
	cout << ans << endl; 
}

int main()
{
	cin >> n >> m;
	for(int i = 0 ; i < n; i++)
		cin >> houses[i];
	for(int i = 0 ; i < m; i++)
		cin >> heaters[i];
	findRadius();
	return 0;
 } 
