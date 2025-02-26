// �������
// ���������ַ��� s1��s2��s3
// ���æ��֤s3�Ƿ���s1��s2�������
// �������� : https://leetcode.cn/problems/interleaving-string/

#include <iostream>
using namespace std;
#include <string>
const int MAXN = 10000;

bool isInterleave1(string s1, string s2, string s3)
{
	int n = s1.size();
	int m = s2.size();
	bool (*dp)[MAXN] = new bool[MAXN][MAXN];
	//��ʼ��dp���ֵ 
	for(int i = 0; i <= n; i++)
		dp[i][0] = false;
	for(int j = 0; j <= m; j++)
		dp[0][j] = false;
	
	dp[0][0] = true;
	
	// s1[ǰ׺����Ϊi]��s2[ǰ׺����Ϊj]���ܷ񽻴���ɳ�s3[ǰ׺����Ϊi+j]
	//�� dp[i][j] ��Ӧ s1[i-1]��s2[j-1] 
	//�����ٽ��������ж� 
	
	//ֻ��s1��ʱ���ܷ�õ�s3 
	for(int i = 1; i <= n; i++)
	{
		if(s1[i - 1] != s3[i - 1])
			break;
		dp[i][0] = true; 
	}
	//ֻ��s2��ʱ���ܷ�õ�s3 
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
			//��ǰλ�õ��ַ���s3��ͬ����Ҫ������ַ���֮ǰ���ַ��Ƿ������s3���ַ� 
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
