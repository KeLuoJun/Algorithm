// ���ر���ͨ�������Ʒ���ת����01����(ģ��)
// ����ɸѡ
// һ����n�ֻ���, ��������Ϊt
// ÿ�ֻ���ļ�ֵ(v[i])������(w[i])������(c[i])������
// �뷵��ѡ����ﲻ������������������£��ܵõ������ļ�ֵ
// �������� : https://www.luogu.com.cn/problem/P1776


#include <iostream>
using namespace std;
const int MAXN = 101;
const int MAXM = 1001;
int *v = new int[MAXN];
int *w = new int[MAXN];
int n,t;
int m = 0;   // ��Ϊ������ת������µ����� 

// ʱ�临�Ӷ�O(t * (log(��1����Ʒ�ĸ���) + log(��2����Ʒ�ĸ���) + ... + log(��n����Ʒ�ĸ���)))
// ��ÿһ����Ʒ�ĸ���ȡlog������ʱ�临�Ӷ���Ȼ����O(n * t)����Ҳ��������
// ���ر�����õķ�ʽ

// 01�����Ŀռ�ѹ������(ģ��)
int compute()
{
	int *dp = new int[MAXM];
	for(int i = 0; i <= t; i++) dp[i] = 0;
	// ת����һ����Ϊm������Ǹ�����n�� 
	for(int i = 1; i <= m; i++){
		for(int j = t; j >= w[i]; j--){
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	return dp[t];
}


int main()
{
	cin >> n >> t;
	int vv,ww,cnt;
	for(int i = 1; i <= n; i++){
		cin >> vv >> ww >> cnt;
		// ������ת�� 
		for(int k = 1; k <= cnt; k << 1){
			v[++m] = k * vv;
			w[m] = k * ww;
			cnt -= k;
		}
		// ������ת���󲻹�������λ������ 
		if(cnt > 0){
			v[++m] = cnt * vv;
			w[m] = cnt * ww;
		}
	}
	cout << compute() << endl;
	return 0;
}
