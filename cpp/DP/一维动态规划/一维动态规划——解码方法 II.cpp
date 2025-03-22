	// 解码方法 II
	// 一条包含字母 A-Z 的消息通过以下的方式进行了 编码 ：
	// 'A' -> "1"
	// 'B' -> "2"
	// ...
	// 'Z' -> "26"
	// 要 解码 一条已编码的消息，所有的数字都必须分组
	// 然后按原来的编码方案反向映射回字母（可能存在多种方式）
	// 例如，"11106" 可以映射为："AAJF"、"KJF"
	// 注意，像 (1 11 06) 这样的分组是无效的，"06"不可以映射为'F'
	// 除了上面描述的数字字母映射方案，编码消息中可能包含 '*' 字符
	// 可以表示从 '1' 到 '9' 的任一数字（不包括 '0'）
	// 例如，"1*" 可以表示 "11"、"12"、"13"、"14"、"15"、"16"、"17"、"18" 或 "19"
	// 对 "1*" 进行解码，相当于解码该字符串可以表示的任何编码消息
	// 给你一个字符串 s ，由数字和 '*' 字符组成，返回 解码 该字符串的方法 数目
	// 由于答案数目可能非常大，返回10^9 + 7的模
	// 测试链接 : https://leetcode.cn/problems/decode-ways-ii/

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
		cur = 0;  //注意这里要归零  
		//因为此处包含 s[i] == 0 的情况的讨论，比较特别 
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
