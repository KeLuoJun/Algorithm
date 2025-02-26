// ���뷽��
// һ��������ĸ A-Z ����Ϣͨ������ӳ������� ���� ��
// 'A' -> "1"
// 'B' -> "2"
// ...
// 'Z' -> "26"
// Ҫ ���� �ѱ������Ϣ���������ֱ����������ӳ��ķ���������ӳ�����ĸ�������ж��ַ�����
// ���磬"11106" ����ӳ��Ϊ��"AAJF"��"KJF"
// ע�⣬��Ϣ���ܷ���Ϊ(1 11 06)����Ϊ "06" ����ӳ��Ϊ "F"
// �������� "6" �� "06" ��ӳ���в����ȼ�
// ����һ��ֻ�����ֵ� �ǿ� �ַ��� s ������㲢���� ���� ������ ����
// ��Ŀ���ݱ�֤�𰸿϶���һ�� 32λ ������
// �������� : https://leetcode.cn/problems/decode-ways/

#include <iostream>
#include <string>
using namespace std;

//�����ݹ�
// s : �����ַ��� 
// s[i....]�ж�������Ч��ת������ 
int numDecodings1(string s, int i)
{
	int n = s.size();
	if(i == n) return 1;
	int ans;
	if(s[i] == '0')
		return 0;
	else
	{
		ans = numDecodings1(s, i + 1);
		if(i + 1 < n && ((s[i] - '0') * 10 + (s[i + 1] - '0')) <= 26)
			ans += numDecodings1(s, i + 2);
	}
	return ans;
}


int f2(string s, int i, int *dp)
{
	int n = s.size();
	if(i == n) return 1;
	if(dp[i] != 0) return dp[i];
	int ans;
	if(s[i] == '0')
		return 0;
	else
	{
		ans = f2(s, i + 1, dp);
		if(i + 1 < n && ((s[i] - '0') * 10 + (s[i + 1] - '0')) <= 26)
			ans += f2(s, i + 2, dp);
	}
	dp[i] = ans;
	return ans;
}
// �����ݹ�ļ��仯����
int numDecodings2(string s)
{
	int *dp = new int[s.size() + 1];
	for(int i = 0; i <= s.size(); i++)
		dp[i] = 0;
	return f2(s, 0, dp);
}

// �ϸ�λ�������Ķ�̬�滮
int numDecodings3(string s)
{
	int n = s.size();
	int *dp = new int[n+1];
	dp[n] = 1;
	//�ӵ׵��� 
	for(int i = n-1; i >= 0; i--)
	{
		if(s[i] == '0')
			dp[i] = 0;
		else
		{
			dp[i] = dp[i + 1];
			if(i + 1 < n && ((s[i] - '0') * 10 + (s[i + 1] - '0')) <= 26)
				dp[i] += dp[i + 2];
		}
	}
	return dp[0];
}

// �ϸ�λ�������Ķ�̬�滮 + �ռ�ѹ��
int numDecodings4(string s)
{
	int n = s.size();
	// dp[i+1]
	int next = 1;
	// dp[i+2]
	int nextNext = 0;
	for(int i = n-1, cur; i >= 0; i--)
	{
		if(s[i] == '0')
			cur = 0;
		else
		{
			cur = next;
			if(i + 1 < n && ((s[i] - '0') * 10 + (s[i + 1] - '0')) <= 26)
				cur += nextNext;
		}
		nextNext = next;
		next = cur;
	}
	return next;
}


int main()
{
	string s;
	cin >> s;
	int ans1 = numDecodings1(s, 0);
	int ans2 = numDecodings2(s);
	int ans3 = numDecodings3(s);
	int ans4 = numDecodings4(s);
	
	cout << ans1 << endl;
	cout << ans2 << endl;
	cout << ans3 << endl;
	cout << ans4 << endl;
	return 0;
}
