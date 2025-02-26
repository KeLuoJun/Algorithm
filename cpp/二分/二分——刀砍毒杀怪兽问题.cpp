// ������ɱ��������
// ���޵ĳ�ʼѪ����һ������hp������ÿһ�غϵ����Ͷ�ɱ����ֵcuts��poisons
// ��i�غ�����õ�������������غϻ�ֱ����ʧcuts[i]��Ѫ�������к���Ч��
// ��i�غ�����ö�ɱ����������غϲ�����ʧѪ��������֮��ÿ�غ϶���ʧpoisons[i]��Ѫ��
// ������ѡ������ж�ɱЧ������֮��Ļغ϶������
// ��������cuts��poisons�����ȶ���n��������һ�����Խ���n�غ�
// ÿһ�غ���ֻ��ѡ�񵶿����߶�ɱ�е�һ������
// �������n���غ���û��ֱ��ɱ�����ޣ���ζ�����Ѿ��޷����µ��ж���
// ���ǹ���������ж�Ч���Ļ�����ô������Ȼ����Ѫ���ľ����ǻغ�����
// �������ٶ��ٻغϣ����޻�����
// ���ݷ�Χ : 
// 1 <= n <= 10^5
// 1 <= hp <= 10^9
// 1 <= cuts[i]��poisons[i] <= 10^9

#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100000;
int cuts[MAXN];
int poisons[MAXN];
int hp,n,m;

bool f(int limit, int &hp1)
{
	int k = min(n,limit);
	for(int i = 0,j = 1; i < k; i++,j++)
	{
		hp1 -= max(cuts[i],(limit - j) * poisons[i]);
		if(hp1 <= 0)
			return true;
	}
	return false;
}


int fast()
{
	int l = 0;
	int r = hp + 1;
	int ans = 0;
	while(l <= r)
	{
		int m = l + ((r - l ) >> 1);
		if(f(m,hp))
		{
			ans = m;
			r = m - 1;
		}
		else
			l = m + 1;
	}
	return ans;
}

int main()
{
	cin >> hp >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> cuts[i];
	for(int i = 0; i < m; i++)
		cin >> poisons[i]; 
	int ans = fast();
	cout << ans << endl;
	return 0;
}

