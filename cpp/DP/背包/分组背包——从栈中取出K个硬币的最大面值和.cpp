// ��ջ��ȡ��K��Ӳ�ҵ������ֵ��
// һ���������ܹ��� n ��Ӳ�� ջ ��ÿ��ջ�� ������ ������ֵ��Ӳ��
// ÿһ�β����У�����Դ�����һ��ջ�� ���� ȡ�� 1 ��Ӳ�ң���ջ���Ƴ��������������Ǯ����
// ����һ���б� piles ������ piles[i] ��һ����������
// �ֱ��ʾ�� i ��ջ�� �Ӷ����� ��Ӳ����ֵ��ͬʱ����һ�������� k
// ���㷵���� ǡ�� ���� k �β�����ǰ���£���Ǯ����Ӳ����ֵ֮�� ���Ϊ����
// �������� : https://leetcode.cn/problems/maximum-value-of-k-coins-from-piles/

//�Ƿ��鱳������ת��Ϊ���鱳������ 
#include <iostream>
using namespace std;
const int MAXN = 1001;
int n,k;  //kΪ����������Ҳ��Ϊ���������� 
int m[MAXN];
int piles[MAXN][MAXN];

// piles��һ��һ���Ӳ��
// m����������ʾһ��Ҫ����m�β���
// dp[i][j] : 1~i���ϣ�һ������j��Ӳ�ҵ�����£���õ�����ֵ
// 1) ��Ҫi���Ӳ�� : dp[i-1][j]
// 2) i���ﳢ��ÿһ�ַ���
// ���磬i��������ǰk��Ӳ�ҵķ��� : dp[i-1][j-k] + �Ӷ�����ʼǰk��Ӳ�ҵļ�ֵ��
// ö��ÿһ��k��ѡ�����ֵ
int compute1()
{
	int dp[n + 1][k + 1];
	for(int j = 0; j <= k; j++)
		dp[0][j] = 0;
	for(int i = 0; i <= n; i++)
		dp[i][0] = 0;
		
	for(int i = 1; i <= n; i++)
	{
		int t = min(k, m[i]);  //������һ���в����������� 
		// ÿһ���ǰ׺�ͼ�Ϊ�������һ�������������մ��� 
		// Ԥ����ǰ׺�ͣ�Ϊ�˼��ټ���
		int *preSum = new int[t + 1];
		for(int j = 1, sum = 0; j <= t; j++){
			sum += piles[i][j];
			preSum[j] = sum;
		}
		
		// ���¶�̬�滮��
		for(int j = 0; j <= k; j++){
			dp[i][j] = dp[i - 1][j];   //iΪǰi�飬jΪ��ǰ����
			// ö���ڵ�ǰ���У�����С�ڵ�ǰ���������Ĳ���������� 
			for(int kk = 1; kk <= min(j, t); kk++){
				dp[i][j] = max(dp[i][j], dp[i - 1][j - kk] + preSum[kk]);
			}
		}
	}
	return dp[n][k];
}


int compute2()
{
	int dp[k + 1];
	for(int i = 0; i <= k; i++)
		dp[i] = 0;
		
	for(int i = 1; i <= n; i++)
	{
		int t = min(m[i], k);
		int *preSum = new int[t + 1];
		for(int j = 1, sum = 0; j <= t; j++){
			sum += piles[i][j];
			preSum[j] = sum;
		}
		
		for(int j = k; j >= 0; j--){
			for(int kk = 1; kk <= min(j,t); kk++)
				dp[j] = max(dp[j], dp[j - kk] + preSum[kk]); 
		}
	}
	return dp[k];
} 


int main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++)	
		cin >> m[i];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m[i]; j++)
			cin >> piles[i][j];
	
	int ans1 = compute1();
	int ans2 = compute2();
	
	cout << ans1 << endl;
	cout << ans2 << endl;
	return 0;
}
