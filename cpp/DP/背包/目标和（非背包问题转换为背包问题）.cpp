// Ŀ���
// ����һ���Ǹ��������� nums ��һ������ target ��
// �������е�ÿ������ǰ��� '+' �� '-' ��Ȼ��������������
// ���Թ���һ�����ʽ
// ����nums=[2, 1]��������2֮ǰ���'+' ����1֮ǰ���'-'
// Ȼ���������õ����ʽ "+2-1" ��
// ���ؿ���ͨ��������������ģ����������� target �Ĳ�ͬ���ʽ����Ŀ
// �������� : https://leetcode.cn/problems/target-sum/


#include <iostream>
using namespace std;
const int MAXN = 21;
int n,target;
int *num = new int[MAXN];


// ��ͨ���ԣ������ݹ��
// nums[0...i-1]��Χ�ϣ��Ѿ��γɵ��ۼӺ���sum
// nums[i...]��Χ�ϣ�ÿ�����ֿ��Ա��+����-
// �����γ��ۼӺ�Ϊtarget�Ĳ�ͬ���ʽ��Ŀ
int f1(int i, int sum)
{
	if(i == n)
		return sum == target ? 1 : 0;
	return f1(i + 1, sum + num[i]) + f1(i + 1, sum - num[i]);
}
int findTargetSumWays1()
{
	return f1(0, 0);
}


// ��ͨ����
// �ϸ�λ�������Ķ�̬�滮
// ƽ�Ƽ���

int findTargetSumWays2()
{
	int s = 0;
	for(int i = 0; i < n; i++)
		s += num[i];
	if(target < -s || target > s)
		return 0;
	// -s ~ +s -> 2 * s + 1
	int m = 2 * s + 1;
	// ԭ����dp[i][j]����:
	// nums[0...i-1]��Χ�ϣ��Ѿ��γɵ��ۼӺ���sum
	// nums[i...]��Χ�ϣ�ÿ�����ֿ��Ա��+����-
	// �����γ��ۼӺ�Ϊtarget�Ĳ�ͬ���ʽ��Ŀ
	// ��Ϊsum����Ϊ������Ϊ���±겻���ָ�����
	// "ԭ����dp[i][j]"��dp���е�dp[i][j + s]����ʾ
	// Ҳ����ƽ�Ʋ�����
	// һ��"ԭ����dp[i][j]"һ��ƽ�Ƶ�dp���е�dp[i][j + s]
	int (*dp)[MAXN] = new int[n + 1][MAXN];
	// ԭ����dp[n][target] = 1��ƽ�ƣ�
	dp[n][target + s] = 1;
	//�� n-1 ����ʡȥ���� i Խ������� 
	for(int i = n - 1; i >= 0; i--)
	{
		for(int j = -s; j <= s; j++)
		{
			if(j + num[i] + s < m)
			// ԭ���� : dp[i][j] = dp[i + 1][j + nums[i]]
			// ƽ��
				dp[i][j + s] = dp[i+1][j + num[i] + s];
			if(j - num[i] + s >= 0)
			// ԭ���� : dp[i][j] += dp[i + 1][j - nums[i]]
			// ƽ�ƣ�
				dp[i][j + s] += dp[i+1][j - num[i] + s];
		}
	}
	// ԭ��Ӧ�÷���dp[0][0]
	// ƽ�ƣ�
	// ����dp[0][0 + s]
	return dp[0][s];
}


// ��˼·��ת��Ϊ01��������
// ˼��1:
// ��Ȼ��Ŀ˵nums�ǷǸ����飬����ʹnums���и�������[3,-4,2]
// ��Ϊ����ÿ����ǰ����+����-��
// ����[3,-4,2]��ʵ��[3,4,2]����һ���Ľ��
// ���Լ�ʹnums���и�����Ҳ���԰Ѹ���ֱ�ӱ��������Ҳ����Ӱ����
// ˼��2:
// ���nums���ǷǸ������������������ۼӺ���sum
// ��ô���target>sum��������û���κη������Դﵽtarget������ֱ�ӷ���0
// ˼��3:
// nums�ڲ������飬������ô+��-�����յĽ����һ������ı���ż��
// ���ԣ�������������ۼӺ���sum��������target����ż�Բ�һ��
// ��ôû���κη������Դﵽtarget������ֱ�ӷ���0
// ˼��4(����Ҫ):
// ����˵����һ������, nums = [1, 2, 3, 4, 5] ���� target = 3
// ����һ�������� : +1 -2 +3 -4 +5 = 3
// �÷�����ȡ�����ļ���ΪA = {1��3��5}
// �÷�����ȡ�˸��ļ���ΪB = {2��4}
// �����κ�һ�ַ�������һ���� sum(A) - sum(B) = target
// ��������������һ�������ʽ�����������߶�����sum(A) + sum(B)����ô�ͻ������£�
// sum(A) - sum(B) + sum(A) + sum(B) = target + sum(A) + sum(B)
// 2 * sum(A) = target + �������������ۼӺ�
// sum(A) = (target + �������������ۼӺ�) / 2
// Ҳ����˵���κ�һ�����ϣ�ֻҪ�ۼӺ���(target + �������������ۼӺ�) / 2
// ��ô��һ����Ӧһ��target�ķ�ʽ
// ����Ǹ�����nums��target = 1, nums�������ۼӺ���11
// ���ж��ٷ������1����ʵ�������ж������Ӽ��ۼӺʹﵽ6�ķ�����(1+11)/2=6
// ��Ϊ���Ӽ��ۼӺ�6 - ��һ����Ӽ��ۼӺ�5 = 1��target)
// �����ж��ٸ��ۼӺ�Ϊ6�Ĳ�ͬ���ϣ��ʹ����ж��ٸ�target==1�ı��ʽ����
// �����Ѿ�ת��Ϊ01����������

// ��Ǹ�����nums�ж��ٸ��������ۼӺ���t
// 01��������(�Ӽ��ۼӺ��ϸ���t) + �ռ�ѹ��
// dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]]
int subsets(int t)
{
	if(t < 0) return 0;
	int *dp = new int[t + 1];
	dp[0] = 1;
	for(int j = 1; j <= t; j++) dp[j] = 0;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = t; j >= num[i]; j--)
			dp[j] += dp[j - num[i]];
	}
	return dp[t];
}
int findTargetSumWays3()
{
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += num[i];
	if(sum < target || (target & 1) ^ (sum & 1) == 1)
		return 0;
	return subsets((target + sum) >> 1);
}

int main()
{
	cin >> n >> target;
	for(int i = 0; i < n; i++)
		cin >> num[i];
	
	int ans1 = findTargetSumWays1();
	int ans2 = findTargetSumWays2();
	int ans3 = findTargetSumWays3();
	
	cout << ans1 << endl;
	cout << ans2 << endl;
	cout << ans3 << endl;
	return 0;	
}
