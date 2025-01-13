// 最长公共子序列其中一个结果
// 给定两个字符串str1和str2
// 输出两个字符串的最长公共子序列
// 如果最长公共子序列为空，则输出-1
// 测试链接 : https://www.nowcoder.com/practice/4727c06b9ee9446cab2e859b4bb86bb8


#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5001;
int n, m, k;
string s1,s2;
int dp[MAXN][MAXN] = {0};
char ans[MAXN];

//i代表字符串s1（即str1）的当前考虑的子串长度，
//范围是从1到s1的长度n（注意，这里是从1开始计数，因为包括空串作为起点）

//j代表字符串s2（即str2）的当前考虑的子串长度，
//范围也是从1到s2的长度m（同样从1开始） 

void f()
{
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(s1[i - 1] == s2[j - 1]){
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}else{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
}

// 倒退得出具体方案 
void lcs()
{
	f();
	k = dp[n][m];
	if(k > 0){
		for(int len = k, i = n, j = m; len > 0;){
			if(s1[i - 1] == s2[j - 1]){
				ans[--len] = s1[i - 1];
				i--;
				j--;
			}else{
				if(dp[i - 1][j] >= dp[i][j - 1]){
					i--;
				}else{
					j--;
				}
			}
		}
	}
}


int main()
{
	cin >> s1 >> s2;
	n = s1.size();
	m = s2.size();
	lcs();
	if(k == 0){
		cout << "-1" << endl;
	}else{
		for(int i = 0; i < k; i++){
			cout << ans[i];
		}
	}
	return 0;
}
