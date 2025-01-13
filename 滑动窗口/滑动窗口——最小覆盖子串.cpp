// 最小覆盖子串
// 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串
// 如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
// 测试链接 : https://leetcode.cn/problems/minimum-window-substring/
#include <iostream>
using namespace std;
#include <string>

int main()
{
	string s,tar;
	cin >> s >> tar;
	int cnts[26] = {0};
	//欠债表 
	for(int i = 0; i < tar.size(); i++)
	{
		cnts[tar[i] - 'a']--;
	}
	// 从哪个位置开头，发现的这个最小覆盖子串
	int start = 0;
	int len = INT_MAX;
	for(int r = 0,l = 0,debt = tar.size(); r < s.size(); r++)
	{
		// cnts[s[r]] : 当前字符欠债情况，负数就是欠债，正数就是多给的
		if(cnts[s[r] - 'a']++ < 0) debt--;
		// r位置结尾，真的有覆盖子串！
		// 看看这个覆盖子串能不能尽量短
		if(debt == 0)
		{
			while(cnts[s[l] - 'a'] > 0)
			{
				// l位置的字符能拿回
				cnts[s[l++] - 'a']--;
			}
			// 从while里面出来，
			// l....r就是r位置结尾的最小覆盖子串
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

