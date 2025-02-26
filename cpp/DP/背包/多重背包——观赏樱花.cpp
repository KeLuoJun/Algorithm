// ����ӣ�� 
// ����һ������������t��һ����n�ֻ�����Ҹ���ÿ�ֻ������Ϣ
// ����(cost)����ֵ(val)������(cnt)
// ���cnt == 0���������ֻ����������ѡ��
// ���cnt > 0����ôcnt�������ֻ��������
// ��ѡ������������ڲ�����t������£������ܵõ�������ֵ
// ��������������1000��ÿһ�ֻ���Ļ��Ѷ�>0
// �������� : https://www.luogu.com.cn/problem/P1833

#include <iostream>
using namespace std;
const int MAXN = 100001;
const int MAXW = 1001;
int *v = new int[MAXN];
int *w = new int[MAXN];
int *dp = new int[MAXW];
int n,t,m = 0;

int compute()
{
	for(int i = 0; i <= t; i++) dp[i] = 0;
	for(int i = 1; i <= m; i++){
		for(int j = t; j >= w[i]; j--){
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	return dp[t];
}

int main()
{
	int h1,m1,h2,m2;
	scanf("%d:%d %d:%d %d",&h1,&m1,&h2,&m2,&n);
	t = h2 * 60 + m2 - (h1 * 60 + m1);
	//cin >> n >> t;
	int vv,ww,cnt;
	for(int i = 1; i <= n; i++){
		cin >> ww >> vv >> cnt;
		if(cnt == 0) cnt = 1000;
		for(int k = 1; k <= cnt; k << 1){
			v[++m] = k * vv;
			w[m] = k * ww;
			cnt -= k;
		}
		if(cnt > 0){
			v[++m] = cnt * vv;
			w[m] = cnt * ww;
		}
	}
	cout << compute() << endl;
	return 0;
}
