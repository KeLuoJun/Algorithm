// 交错符串
// 给定三个字符串 s1、s2、s3
// 请帮忙验证s3是否由s1和s2交错组成
// 测试链接 : https://leetcode.cn/problems/interleaving-string/

#include <iostream>
using namespace std;
#include <string>
const int MAXN = 10000;

bool isInterleave1(string s1, string s2, string s3)
{
	int n = s1.size();
	int m = s2.size();
	bool (*dp)[MAXN] = new bool[MAXN][MAXN];
	//初始化dp表的值 
	for(int i = 0; i <= n; i++)
		dp[i][0] = false;
	for(int j = 0; j <= m; j++)
		dp[0][j] = false;
	
	dp[0][0] = true;
	
	// s1[前缀长度为i]和s2[前缀长度为j]，能否交错组成出s3[前缀长度为i+j]
	//即 dp[i][j] 对应 s1[i-1]和s2[j-1] 
	//减少临界条件的判断 
	
	//只有s1串时，能否得到s3 
	for(int i = 1; i <= n; i++)
	{
		if(s1[i - 1] != s3[i - 1])
			break;
		dp[i][0] = true; 
	}
	//只有s2串时，能否得到s3 
	for(int j = 1; j <= m; j++)
	{
		if(s2[j - 1] != s3[j - 1])
			break;
		dp[0][j] = true;
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			//当前位置的字符与s3相同，还要看这个字符串之前的字符是否有组成s3的字符 
			dp[i][j] = (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j])
						|| (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]);
		}
	}
	return dp[n][m]; 
}


int main()
{
	string s1,s2,s3;
	cin >> s1 >> s2 >> s3;
	
	bool ans1 = isInterleave1(s1, s2, s3);
	
	cout << ans1 << endl;
	return 0;
}
