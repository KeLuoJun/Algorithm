// 重复叠加字符串匹配
// 给定两个字符串a和b，寻找重复叠加字符串a的最小次数，使得字符串b成为叠加后的字符串a的子串
// 如果不存在则返回-1
// 字符串"abc"重复叠加0次是""
// 重复叠加1次是"abc"
// 重复叠加2次是"abcabc"
// 测试链接 : https://leetcode.cn/problems/repeated-string-match/


#include <iostream>
#include <string>
using namespace std;
const int base = 499;
const int N = 30001;
long pow[N];
long hashs[N];

void build(string s, int n)
{
	pow[0] = 1;
	for(int i = 1; i < n; i++){
		pow[i] = pow[i - 1] * base;
	}
	hashs[0] = s[0] - 'a' + 1;
	for(int i = 1; i < n; i++){
		hashs[i] = hashs[i - 1] * base + s[i] - 'a' + 1;
	}
}

long getHash(int l, int r)
{
	long ans = hashs[r];
	if(l > 0){
		ans -= hashs[l - 1] * pow[r - l + 1];
	}
	return ans;
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.size();
	int m = s2.size();
	string tmp = s1;
	// m/n 向上取整 
	int k = (m + n - 1) / n;
	// s1的长度最长为达到s2的长度后再加一个自身的长度
	// 如果这都不能满足，则再叠加s1也不可能满足 
	for(int cnt = 1; cnt <= k; cnt++){
		s1 += tmp;
	} 
	int len = s1.size();
	build(s1, len);
	long h2 = s2[0] = -'a' + 1;
	for(int i = 1; i < m; i++){
		h2 = h2 * base + s2[i] - 'a' + 1;
	}
	int ans = -1;
	for(int l = 0, r = m - 1; r < len; l++, r++){
		if(getHash(l, r) == h2){
			// 这里有点不能理解 
			ans = r < k * n ? k : (k + 1);
		}
	}
	cout << ans << endl;
	return 0;
}

