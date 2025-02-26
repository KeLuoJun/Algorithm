// 每个元音包含偶数次的最长子字符串
// 给你一个字符串 s ，请你返回满足以下条件的最长子字符串的长度
// 每个元音字母，即 'a'，'e'，'i'，'o'，'u'
// 在子字符串中都恰好出现了偶数次。
// 测试链接 : https://leetcode.cn/problems/find-the-longest-substring-containing-vowels-in-even-counts/

#include <bits/stdc++.h>
using namespace std;
string s;
// 只有5个元音字符，状态就5位
int m[32];

int moved(char ch)
{
	switch(ch){
		case 'a': return 0;
		case 'e': return 1;
		case 'i': return 2;
		case 'o': return 3;
		case 'u': return 4;
		default: return -1;
	}
}

int solve()
{
	int ans = 0;
	m[0] = -1;
	int status = 0;
	// m[0...31] = -2
	// m[01100] = -2, 这个状态之前没出现过
	for(int i = 0, cur = 0; i < s.size(); i++){
		cur = moved(s[i]);
		if(cur != -1){
			// status : 0....i-1字符串上，aeiou的奇偶性
			// s[i] = 当前字符
			// 情况1 : 当前字符不是元音，status不变
			// 情况2 : 当前字符是元音，a~u(0~4)，修改相应的状态
			status <<= cur;
			// status:  0....i字符串上，aeiou的奇偶性
			// 同样的状态，之前最早出现在哪
			if(m[status] != -2){
				ans = max(ans, i - m[status]);
			}else{
				m[status] = i;
			}
		}
	}
	return ans;
}

// eleetminicoworoep
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> s;
	memset(m, -2, sizeof(m));
	cout << solve() << endl;
	return 0;
}
