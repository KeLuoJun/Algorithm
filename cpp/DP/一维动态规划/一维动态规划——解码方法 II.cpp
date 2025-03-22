	// ���뷽�� II
	// һ��������ĸ A-Z ����Ϣͨ�����µķ�ʽ������ ���� ��
	// 'A' -> "1"
	// 'B' -> "2"
	// ...
	// 'Z' -> "26"
	// Ҫ ���� һ���ѱ������Ϣ�����е����ֶ��������
	// Ȼ��ԭ���ı��뷽������ӳ�����ĸ�����ܴ��ڶ��ַ�ʽ��
	// ���磬"11106" ����ӳ��Ϊ��"AAJF"��"KJF"
	// ע�⣬�� (1 11 06) �����ķ�������Ч�ģ�"06"������ӳ��Ϊ'F'
	// ��������������������ĸӳ�䷽����������Ϣ�п��ܰ��� '*' �ַ�
	// ���Ա�ʾ�� '1' �� '9' ����һ���֣������� '0'��
	// ���磬"1*" ���Ա�ʾ "11"��"12"��"13"��"14"��"15"��"16"��"17"��"18" �� "19"
	// �� "1*" ���н��룬�൱�ڽ�����ַ������Ա�ʾ���κα�����Ϣ
	// ����һ���ַ��� s �������ֺ� '*' �ַ���ɣ����� ���� ���ַ����ķ��� ��Ŀ
	// ���ڴ���Ŀ���ܷǳ��󣬷���10^9 + 7��ģ
	// �������� : https://leetcode.cn/problems/decode-ways-ii/

#include <iostream>
#include <string>
using namespace std;

int numDecodings1(string s, int i)
{
	int n = s.size();
	if(i == n)
		return 1;
	if(s[i] == '0')
		return 0;
	int ans;
	ans = numDecodings1(s, i + 1) * (s[i] == '*' ? 9 : 1);
	if(i + 1 < n)
	{
		if(s[i] != '*')
		{
			if(s[i + 1] != '*')
			{
				if((s[i] - '0') * 10 + (s[i + 1] - '0') <= 26)
					ans += numDecodings1(s, i + 2);
			}
			else
			{
				if(s[i] == '1')
					ans += numDecodings1(s, i + 2) * 9;
				else if(s[i] == '2')
					ans += numDecodings1(s, i + 2) * 6;
			}
		}
		else
		{
			if(s[i + 1] != '*')
			{
				if(s[i + 1] <= '6')
					ans += numDecodings1(s, i + 2) * 6;
				else
					ans += numDecodings1(s, i + 2);
			}
			else
			{
				ans += numDecodings1(s, i + 2) * 15;
			}
		}
	}
	return ans;
}


int f2(string s, int i, int *dp)
{
	int n = s.size();
	if(i == n) return 1;
	if(s[i] == '0') return 0;
	if(dp[i] != -1) return dp[i];
	int ans;
	ans = f2(s, i + 1, dp) * (s[i] == '*' ? 9 : 1);
	if(i + 1 < n)
	{
		if(s[i] != '*')
		{
			if(s[i + 1] != '*')
			{
				if((s[i] - '0') * 10 + (s[i + 1] - '0') <= 26)
					ans += f2(s, i + 2, dp);
			}
			else
			{
				if(s[i] == '1')
					ans += f2(s, i + 2, dp) * 9;
				else if(s[i] == '2')
					ans += f2(s, i + 2, dp) * 6;
			}
		}
		else
		{
			if(s[i + 1] != '*')
			{
				if(s[i + 1] <= '6')
					ans += f2(s, i + 2, dp) * 2;
				else
					ans += f2(s, i + 2, dp);
			}
			else
			{
				ans += f2(s, i + 2, dp) * 15;
			}
		}
	}
	dp[i] = ans;
	return ans;
}
int numDecodings2(string s)
{
	int n = s.size();
	int *dp = new int[n];
	for(int i = 0; i <= n; i++)
		dp[i] = -1;
	return f2(s, 0, dp);
}


int numDecodings3(string s)
{
	int n = s.size();
	int *dp = new int[n + 1];
	dp[n] = 1;
	for(int i = n - 1; i >= 0; i--)
	{
		if(s[i] == '0')
			dp[i] = 0;
		else
		{
			if(s[i] == '*')
				dp[i] = dp[i + 1] * 9;
			else
				dp[i] = dp[i + 1];
			
			if(i + 1 < n)
			{
				if(s[i] != '*')
				{
					if(s[i + 1] != '*')
					{
						if((s[i] - '0') * 10 + (s[i + 1] - '0') <= 26)
							dp[i] += dp[i + 2];
					}
					else
					{
						if(s[i] == '1')
							dp[i] += dp[i + 2] * 9;
						else if(s[i] = '2')
							dp[i] += dp[i + 2] * 6; 
					}
				}
				else
				{
					if(s[i + 1] != '*')
					{
						if(s[i + 1] <= '6')
							dp[i] += dp[i + 2] * 2;
						else
							dp[i] += dp[i + 2];
					}
					else
					{
						dp[i] += dp[i + 2] * 15;
					}
				}
			}
		}
	}
	return dp[0];
}


int numDecodings4(string s)
{
	int n = s.size();
	int next = 1;
	int nextNext = 0;
	int cur = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		if(s[i] != '0')
		{
			cur = next * (s[i] == '*' ? 9 : 1);
			if(i + 1 < n)
			{
				if(s[i] != '*')
				{
					if(s[i + 1] != '*')
					{
						if((s[i] - '0') * 10 + (s[i + 1] - '0') <= 26)
							cur += nextNext;
					}
					else
					{
						if(s[i] == '1')
							cur += nextNext * 9;
						else if(s[i] == '2')
							cur += nextNext * 6;
					}
				}
				else
				{
					if(s[i + 1] != '*')
					{
						if(s[i] <= '6')
							cur += nextNext * 2;
						else
							cur += nextNext;
					}
					else
					{
						cur += nextNext * 15;
					}
				}
			}
		}
		nextNext = next;
		next = cur;
		cur = 0;  //ע������Ҫ����  
		//��Ϊ�˴����� s[i] == 0 ����������ۣ��Ƚ��ر� 
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
