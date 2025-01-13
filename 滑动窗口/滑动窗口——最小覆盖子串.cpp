// ��С�����Ӵ�
// ����һ���ַ��� s ��һ���ַ��� t ������ s �к��� t �����ַ�����С�Ӵ�
// ��� s �в����ں��� t �����ַ����Ӵ����򷵻ؿ��ַ��� "" ��
// �������� : https://leetcode.cn/problems/minimum-window-substring/
#include <iostream>
using namespace std;
#include <string>

int main()
{
	string s,tar;
	cin >> s >> tar;
	int cnts[26] = {0};
	//Ƿծ�� 
	for(int i = 0; i < tar.size(); i++)
	{
		cnts[tar[i] - 'a']--;
	}
	// ���ĸ�λ�ÿ�ͷ�����ֵ������С�����Ӵ�
	int start = 0;
	int len = INT_MAX;
	for(int r = 0,l = 0,debt = tar.size(); r < s.size(); r++)
	{
		// cnts[s[r]] : ��ǰ�ַ�Ƿծ�������������Ƿծ���������Ƕ����
		if(cnts[s[r] - 'a']++ < 0) debt--;
		// rλ�ý�β������и����Ӵ���
		// ������������Ӵ��ܲ��ܾ�����
		if(debt == 0)
		{
			while(cnts[s[l] - 'a'] > 0)
			{
				// lλ�õ��ַ����û�
				cnts[s[l++] - 'a']--;
			}
			// ��while���������
			// l....r����rλ�ý�β����С�����Ӵ�
			if(r - l + 1 < len)
			{
				len = r - l + 1;
				start = l;
			}
		}
	}
	string ans;
	for(int i = start,j = 1; j <= len; i++,j++)
		ans += s[i];
	cout << ans << endl;
	return 0;
} 

