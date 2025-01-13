// ���Ʊ��
// ��һ�������к��ܻ�ӭ�Ĺ��ȣ�����ǰһ��ƻ���һЩ������
// �ڽ�������һ�����Ҫ���е����ӽ���һ����Ϊ days ���������
// ÿһ����һ���� 1 �� 365 ������
// ��Ʊ�� ���ֲ�ͬ�����۷�ʽ
// һ�� Ϊ��1�� ��ͨ��֤�ۼ�Ϊ costs[0] ��Ԫ
// һ�� Ϊ��7�� ��ͨ��֤�ۼ�Ϊ costs[1] ��Ԫ
// һ�� Ϊ��30�� ��ͨ��֤�ۼ�Ϊ costs[2] ��Ԫ
// ͨ��֤�������������Ƶ�����
// ���磬��������ڵ� 2 ����һ�� Ϊ�� 7 �� ��ͨ��֤
// ��ô���ǿ����������� 7 ��(��2~8��)
// ���� ����Ҫ����ڸ������б� days ���г���ÿһ�����������Ҫ���������
// �������� : https://leetcode.cn/problems/minimum-cost-for-tickets/

#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 366;
int *days = new int[MAXN];
int *costs = new int[3];
int durations[3] = {1, 7, 30};

//�����ݹ� 
int mincostTickets1(int *days, int n, int *costs, int i)
{
	if(i == n) return 0;
	
	// i�±� : ��days[i]�죬��һ������
	// i.... ���ٻ����Ƕ��� 
	int ans = INT_MAX;
	// days[i..... ���ٻ����Ƕ��� 
	for(int k = 0, j = i; k < 3; k++)
	{
		while(j < n && days[i] + durations[k] > days[j])
		// ��Ϊ����2������������࣬30��
		// ����whileѭ�����ִ��30��
		// ö����Ϊ������Ϊ��O(1)
			j++;
		ans = min(ans, costs[k] + mincostTickets1(days, n, costs, j));
	}
	return ans;
}

int f2(int *days, int n, int *costs, int i, int *dp)
{
	if(i == n) return 0;
	if(dp[i] != INT_MAX) return dp[i];
	
	int ans = INT_MAX;
	for(int k = 0, j = i; k < 3; k++)
	{
		while(j < n && days[i] + durations[k] > days[j])
			j++;
		ans = min(ans, costs[k] + f2(days, n, costs, j, dp));
	}
	dp[i] = ans;
	return ans;
}
// �������Ըļ��仯����
// �Ӷ����׵Ķ�̬�滮
int mincostTickets2(int *days, int n, int *costs)
{
	int *dp = new int[n];
	for(int i = 0; i < n; i++)
		dp[i] = INT_MAX;
	int ans = f2(days, n, costs, 0, dp);
	delete[] dp;
	return ans;
}

// �ϸ�λ�������Ķ�̬�滮
// �ӵ׵����Ķ�̬�滮
int mincostTickets3(int *days, int n, int *costs)
{
	int *dp = new int[MAXN];
	for(int i = 0; i <= n; i++)
		dp[i] = INT_MAX;
	dp[n] = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		for(int k = 0, j = i; k < 3; k++)
		{
			while(j < n && days[i] + durations[k] > days[j])
				j++;
			dp[i] = min(dp[i], costs[k] + dp[j]);
		}
	}
	return dp[0];
}


int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> days[i];
	for(int i = 0; i < 3; i++)
		cin >> costs[i];
	int ans1 = mincostTickets1(days, n, costs, 0);
	int ans2 = mincostTickets2(days, n, costs);
	int ans3 = mincostTickets3(days, n, costs);
	
	cout << ans1 << endl;
	cout << ans2 << endl;
	cout << ans3 << endl;
	return 0;
}
