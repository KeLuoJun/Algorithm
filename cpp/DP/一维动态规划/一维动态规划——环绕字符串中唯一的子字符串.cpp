// �����ַ�����Ψһ�����ַ���
// �����ַ��� base Ϊһ�� "abcdefghijklmnopqrstuvwxyz" ���޻��Ƶ��ַ���
// ���� base �������������ģ�
// "..zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd.."
// ����һ���ַ��� s ������ͳ�Ʋ����� s ���ж��� ��ͬ�ǿ��Ӵ� Ҳ�� base �г���
// �������� : https://leetcode.cn/problems/unique-substrings-in-wraparound-string/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// ʱ�临�Ӷ�O(n)��n���ַ���s�ĳ��ȣ��ַ���base����Ϊ������
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
		// (ǰһ���ַ���'z' && ��ǰ�ַ���'a') || ǰһ���ַ��ȵ�ǰ�ַ���ascii����1
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
