// ���������������һ�����
// ���������ַ���str1��str2
// ��������ַ����������������
// ��������������Ϊ�գ������-1
// �������� : https://www.nowcoder.com/practice/4727c06b9ee9446cab2e859b4bb86bb8


#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5001;
int n, m, k;
string s1,s2;
int dp[MAXN][MAXN] = {0};
char ans[MAXN];

//i�����ַ���s1����str1���ĵ�ǰ���ǵ��Ӵ����ȣ�
//��Χ�Ǵ�1��s1�ĳ���n��ע�⣬�����Ǵ�1��ʼ��������Ϊ�����մ���Ϊ��㣩

//j�����ַ���s2����str2���ĵ�ǰ���ǵ��Ӵ����ȣ�
//��ΧҲ�Ǵ�1��s2�ĳ���m��ͬ����1��ʼ�� 

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

// ���˵ó����巽�� 
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
