// ���Ч����
// ����һ��ֻ���� '(' �� ')' ���ַ���
// �ҳ����Ч����ʽ��ȷ�������������Ӵ��ĳ��ȡ�
// �������� : https://leetcode.cn/problems/longest-valid-parentheses/


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// ʱ�临�Ӷ�O(n)��n��str�ַ����ĳ���
int main()
{
	string s;
	cin >> s;
	int n = s.size();
	int *dp = new int[n];
	for(int i = 0; i < n; i++)
		dp[i] = 0;
	int ans = 0;
	for(int i = 1, p; i < n; i++)
	{
		if(s[i] == ')')
		{
			p = i - dp[i - 1] - 1;
			//  ?         )
			//  p         i
			if(p >= 0 && s[p] == '(')
			{
				dp[i] = dp[i - 1] + 2 + (p - 1 >= 0 ? dp[p - 1] : 0);
			}
		}
		ans = max(ans, dp[i]);	
	}
	cout << ans << endl;
	return 0;
 } 
