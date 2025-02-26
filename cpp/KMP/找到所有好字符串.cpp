// 找到所有好字符串
// 给你两个长度为n的字符串s1和s2，以及一个字符串evil
// 好字符串的定义为 : 长度为n，字典序大于等于s1，字典序小于等于s2，且不包含evil字符串
// 返回好字符串的数量
// 由于答案很大返回对1000000007取余的结果
// 测试链接 : https://leetcode.cn/problems/find-all-good-strings/

#include <iostream>
#include <string>
using namespace std;
const int N = 501;
const int mod = 1000000007;

int dp[N][N][N];
int nexts[N];

void clear(int n, int m)
{
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			dp[i][j][0] = -1;
			dp[i][j][1] = -1;
		}
	}
}


void getNextArray(string evil, int m)
{
	nexts[0] = -1;
	nexts[1] = 0;
	int i = 2, cn = 0;
	while(i < m){
		if(evil[i - 1] == evil[cn]){
			nexts[i++] = ++cn;
		}else if(cn > 0){
			cn = nexts[cn];
		}else{
			nexts[i++] = 0;
		}
	}
}


// 字符串 和 字符串的匹配 
int kmp(string s, string e, int n, int m)
{
	int x = 0, y = 0;
	while(x < n && y < m){
		if(s[x] == e[y]){
			x++;
			y++;
		}else if(y == 0){
			x++;
		}else{
			y = nexts[y];
		}
	}
	return y == m ? x - y : -1;
}

// 字符串 和 字符 的匹配 
// 当前字符是pick，一开始匹配e[j]
// 根据next数组加速匹配，返回匹配出来的位置
// 如果匹配不出来返回-1
// 单次调用的时间复杂度O(1)
int jump(string e, char pick, int j)
{
	while(j >= 0 && pick != e[j]){
		j = nexts[j];
	}
	return j;
}

// 时间复杂度O(n * m * 2 * 26)
// s、e、n、m都是固定参数
// 0...i-1已经做了决策，已经匹配了e[0...j-1]这个部分
// 当前来到s[i]时，最先该考察的匹配位置是e[j]
// 之前的决策如果已经比s小了，free == 1
// 之前的决策如果和s[0..i-1]一样，free == 0
// 返回后续的所有决策中，不含有e字符串且<=s的决策有多少个，同时长度需要为n
// 核心 : 利用e字符串的next数组加速匹配
// 方法：数位dp + 不出现evil字符串 
int f(string s, string e, int n, int m, int i, int j, int Free)
{
	if(j == m){
		return 0;
	}
	if(i == n){
		return 1;
	}
	if(dp[i][j][Free] != -1){
		return dp[i][j][Free];
	}
	char cur = s[i];
	int ans = 0;
	if(Free == 0){
		// 之前的决策和s的状况一样
		// 当前尝试比cur小的字符
		for(char pick = 'a'; pick < cur; pick++){
			ans = (ans + f(s, e, n, m, i + 1, jump(e, pick, j) + 1, 1)) % mod;
		}
		// 当前尝试等于cur的字符
		ans = (ans + f(s, e, n, m, i + 1, jump(e, cur, j) + 1, 0)) % mod;
	}else{
		// 之前的决策已经确定小于s了
		// 当前a~z随便尝试
		for(char pick = 'a'; pick <= 'z'; pick++){
			ans = (ans + f(s, e, n, m, i + 1, jump(e, pick, j) + 1, 1)) % mod;
		}
	}
	dp[i][j][Free] = ans;
	return ans;
}



int main()
{
	int n;
	string s1, s2, evil;
	cin >> n;
	cin >> s1 >> s2 >> evil;
	int m = evil.size();
	getNextArray(evil, m);
	clear(n, m);
	// <=s2的好字符串数量
	int ans = f(s2, evil, n, m, 0, 0, 0);
	clear(n, m);
	// 减去<=s1的好字符串数量
	ans = (ans - f(s1, evil, n, m, 0, 0, 0) + mod) % mod;
	if(kmp(s1, evil, n, m) == -1){
		// 如果s1不含有evil，则s1也算好字符串 
		ans = (ans + 1) % mod;
	}
	cout << ans << endl;
	return 0;
}


