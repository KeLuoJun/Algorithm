// �ڵ���Ϊn�߶Ȳ�����m�Ķ���������
// ������n���ڵ㣬������ж��ٸ���ͬ�ṹ�Ķ�����
// ����ڵ����Ϊn�����ĸ߶Ȳ�����m�ķ���
// ��Ϊ�𰸺ܴ����Դ���Ҫģ��1000000007�����
// �������� : https://www.nowcoder.com/practice/aaefe5896cce4204b276e213e725f3ea

#include <iostream>
using namespace std;
const int MOD = 1000000007;
const int MAXN = 1000;

int f1(int n, int m, long dp[][MAXN])
{
	if(n == 0) return 1;
	if(m == 0) return 0;
	if(dp[n][m] != -1) return dp[n][m];
	long ans = 0;
	for(int k = 0; k < n; k++)
	{
		ans = (ans + (long)(f1(k, m-1, dp) * f1(n-k-1, m-1, dp) % MOD)) % MOD;
	}
	dp[n][m] = ans;
	return (int)ans;
}
// �������ڵ���Ϊn
// �߶Ȳ��ܳ���m
// �ṹ������
// ���仯����
int compute1(int n, int m)
{
	long (*dp1)[MAXN] = new long[MAXN][MAXN];
	for(int i = 0; i < MAXN; i++)
		for(int j = 0; j < MAXN; j++)
			dp1[i][j] = -1;
	return f1(n, m, dp1);
}



// �ϸ�λ�������Ķ�̬�滮
int compute2(int n, int m)
{
	long (*dp2)[MAXN] = new long[MAXN][MAXN];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			dp2[i][j] = 0;
	for(int j = 0; j < m; j++)
		dp2[0][j] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			dp2[i][j] = 0;
			for(int k = 0; k < i; k++)
			// һ��i���ڵ㣬ͷ�ڵ��Ѿ�ռ����1������
			// �������ռ��k������ô������ռ��i-k-1��
				dp2[i][j] = (dp2[i][j] + dp2[k][j - 1] * dp2[i - k - 1][j - 1] % MOD) % MOD;
				
		}
	}
	return (int)dp2[n][m];
}


int main()
{
	int n,m;
	cin >> n >> m;
	int ans1 = compute1(n,m);
	int ans2 = compute2(n,m);
	
	cout << ans1 << endl;
	cout << ans2 << endl;
	return 0;
} 
