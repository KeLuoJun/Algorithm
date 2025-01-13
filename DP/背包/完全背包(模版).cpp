// ��ȫ����(ģ��)
// ����һ������t����ʾ����������
// ��m�ֻ��ÿ�ֻ������ѡ�� �����
// ÿ�ֻ��ﶼ�����costs[i]�ͼ�ֵvalues[i]
// �����ڲ�����������������£���ô��ѡ�����ܴﵽ��ֵ���
// �������ļ�ֵ
// �������� : https://www.luogu.com.cn/problem/P1616


#include <iostream>
using namespace std;
const int MAXN = 10001;
const int MAXT = 1e7 + 1;
int t,m;
int *cost = new int[MAXN];
int *val = new int[MAXN];

// �ϸ�λ�������Ķ�̬�滮
// ��ռ䲻���������޷�ͨ��ȫ����������
int compute1()
{
	int dp[m + 1][t + 1];
	for(int j = 0; j <= t; j++)
		dp[0][j] = 0;
	for(int i = 0; i <= m; i++)
		dp[i][0] = 0;
	
	for(int i = 1; i <= m; i++){
		for(int j = 0; j <= t; j++){
			dp[i][j] = dp[i-1][j];
			if(j - cost[i] >= 0)
			//��01�������������� ����Ҫ��֮ǰi-1����������� 
				dp[i][j] = max(dp[i][j], dp[i][j - cost[i]] + val[i]);
		}
	}
	return dp[m][t];
}

// �ռ�ѹ�� 
int compute2()
{
	int dp[t + 1];
	for(int i = 0; i <= t; i++)
		dp[i] = 0;
	for(int i = 1; i <= m; i++){
		// ע�������൱��
        // for(int j = 0; j <= t; j++)
		//		if(j - cost[i] >= 0) 
		// ��������
		// ��Ϊ����ȫ������ǰi-1����Ʒ����� 
		//ֻҪ��ǰ����������������һֱ�ŵ�ǰ��Ʒ�����ÿ��ǵ�ǰ��Ʒ������ 
		// ��ʱ dp[j - cost[i]] �Ѿ��ǵ�ǰ���Ѿ����¹���ֵ 
		for(int j = cost[i]; j <= t; j++){
			dp[j] = max(dp[j], dp[j - cost[i]] + val[i]);
		}
	}
	return dp[t];
 } 

int main()
{
	cin >> t >> m;
	int a,b;  //�ֱ��ʾ��ժ�� i �ֲ�ҩ��ʱ��͸ò�ҩ�ļ�ֵ
	for(int i = 1; i <= m; i++){
		cin >> a >> b;
		cost[i] = a;
		val[i] = b;
	} 
	
	int ans1 = compute1();
	int ans2 = compute2();
	
	cout << ans1 << endl;
	cout << ans2 << endl;
	return 0;
 } 
