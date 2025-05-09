// 环绕字符串中唯一的子字符串
// 定义字符串 base 为一个 "abcdefghijklmnopqrstuvwxyz" 无限环绕的字符串
// 所以 base 看起来是这样的：
// "..zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd.."
// 给你一个字符串 s ，请你统计并返回 s 中有多少 不同非空子串 也在 base 中出现
// 测试链接 : https://leetcode.cn/problems/unique-substrings-in-wraparound-string/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 时间复杂度O(n)，n是字符串s的长度，字符串base长度为正无穷
int findSubstringInWraproundString(string str)
{
	int n = str.size();
	int *s = new int[n];
	for(int i = 0; i < n; i++)
		s[i] = (int)(str[i] - 'a');
	int *dp = new int[26];
	for(int i = 0; i < 26; i++)
		dp[i] = 0;
	// s : c d e....
	//     2 3 4
	dp[s[0]] = 1;
	for(int i = 1, cur, pre, len = 1; i < n; i++)
	{
		cur = s[i];
		pre = s[i - 1];
		if((pre == 25 && cur == 0) || pre + 1 == cur)
		// (前一个字符是'z' && 当前字符是'a') || 前一个字符比当前字符的ascii码少1
			len++;
		else
			len = 1;
		dp[cur] = max(dp[cur], len);
	}
	int ans = 0;
	for(int i = 0; i < 26; i++)
		ans += dp[i];
	return ans;
}



int main()
{
	string s;
	cin >> s;
	cout << findSubstringInWraproundString(s) << endl;
	return 0;
 } 
