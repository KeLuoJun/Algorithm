// ���ر���������ö���Ż�
// ����ɸѡ
// һ����n�ֻ���, ��������Ϊt
// ÿ�ֻ���ļ�ֵ(v[i])������(w[i])������(c[i])������
// �뷵��ѡ����ﲻ������������������£��ܵõ������ļ�ֵ
// �������� : https://www.luogu.com.cn/problem/P1776


#include <iostream>
using namespace std;
const int MAXN = 101;
const int MAXM = 1001;
int v[MAXN];
int w[MAXN];
int m[MAXN];
int n,t;


// �ϸ�λ�������Ķ�̬�滮
// ʱ�临�Ӷ�O(n * t * ÿ����Ʒ��ƽ������)
int compute1()
{
	// dp[0][....] = 0����ʾû�л��������£��������������Ƕ��٣�����ֵ����0
	int (*dp)[MAXM] = new int[MAXN][MAXM];
	for(int j = 0; j <= t; j++)
		dp[0][j] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= t; j++){
			dp[i][j] = dp[i - 1][j];
			// ö�ٵ�ǰ��Ʒ�������������õ���Ʒ�����������ܳ�����ǰ��������j 
			for(int k = 1; k <= m[i] && k * w[i] <= j; k++)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + k * v[i]);
		}
	}
	return dp[n][t];
}

// �ռ�ѹ��
// ���ֲ���������ʱ
// ��Ϊû���Ż�ö��
// ʱ�临�Ӷ�O(n * t * ÿ����Ʒ��ƽ������)
int compute2()
{
	int *dp = new int[t + 1];
	for(int i = 0; i <= t; i++)
		dp[i] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = t; j >= 0; j--){
			for(int k = 1; k <= m[i] && k * w[i] <= j; k++)
				dp[j] = max(dp[j], dp[j - k * w[i]] + k * v[i]);
		}
	}
	return dp[t];
}

int main()
{
	cin >> n >> t;
	int vv,ww,mm;
	for(int i = 1; i <= n; i++)
	{
		cin >> vv >> ww >> mm;
		v[i] = vv;
		w[i] = ww;
		m[i] = mm;
	}
	
	int ans1 = compute1();
	int ans2 = compute2();
	
	cout << ans1 << endl;
	cout << ans2 << endl;
	return 0;
}
