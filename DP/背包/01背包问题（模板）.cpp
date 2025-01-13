// 01����(ģ��)
// ����һ������t����ʾ����������
// ��m�����ÿ���������ѡ��һ��
// ÿ���������Լ������costs[i]�ͼ�ֵvalues[i]
// �����ڲ�����������������£���ô��ѡ�����ܴﵽ��ֵ���
// �������ļ�ֵ
// �������� : https://www.luogu.com.cn/problem/P1048

#include <iostream>
using namespace std;
#include <algorithm>
const int MAXN = 1001;
int *value = new int[MAXN];
int *cost = new int[MAXN];

//i������Ʒ��ţ�j����ǰ�ı������� 
int compute1(int t, int m)
{
	int (*dp)[MAXN] = new int[m + 1][MAXN];
	// ����dp��ĳ�ʼ״̬ 
	for(int i = 0; i <= m; i++)
		for(int j = 0; j <= t; j++)
			dp[i][j] = 0;
	for(int i = 1; i <= m; i++)
	{
		for(int j = 0; j <= t; j++)
		{
			// ��Ҫ��ǰ��Ʒ 
			dp[i][j] = dp[i-1][j];
			// Ҫ��ǰ��Ʒ�����ǵñ�֤�ڵ�ǰ��������Ϊj������������ɵ�ǰ��Ʒ 
			if(j - cost[i] >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + value[i]);
		}
	}
	return dp[m][t];
}


// �ռ�ѹ��
int compute2(int t, int m)
{
	int *dp = new int[t+1];
	for(int i = 0; i <= t; i++)
		dp[i] = 0;
	for(int i = 1; i <= m; i++)
	//dp[i][j] = dp[i-1][j];
	//����䵱 j < cost[i] ʱ����Ҫ���� 
	//�൱�ڱ����ڶ�ά���е���һ�е�ֵ 
	//��ʱdp[j]��ֵ��δ���£�ֱ�Ӳ����£��൱�����ɵ���dp[i-1][j]��ֵ 
	//�൱��dp[i][j] = dp[i-1][j]; 
		for(int j = t; j >= cost[i]; j--)
		//�������� 
		//��Ϊ���������ϵĸ��ӣ�����ǰ�����δ���µĸ����൱�����Ͻǵĸ��ӣ����Դ����������
		//j - cost[i] ��ʾ֮ǰ����Ʒ���Ѳ�����װ�µ�ǰ��Ʒ������������ 
		// ��ʱ dp[j - cost[i]] ��ʵ���� dp[i - 1][j - cost[i]] ����ֵ����Ϊ��δ���µ� 
			dp[j] = max(dp[j], dp[j - cost[i]] + value[i]);
	return dp[t];
}

int main()
{
	int t,m; // tΪ����������mΪ��Ʒ���� 
	cin >> t >> m;
	for(int i = 1; i <= m; i++)
		cin >> cost[i] >> value[i];
	cout << compute1(t,m) << endl;
	cout << compute2(t,m) << endl;
	return 0;
}
