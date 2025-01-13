// �ҵ����к��ַ���
// ������������Ϊn���ַ���s1��s2���Լ�һ���ַ���evil
// ���ַ����Ķ���Ϊ : ����Ϊn���ֵ�����ڵ���s1���ֵ���С�ڵ���s2���Ҳ�����evil�ַ���
// ���غ��ַ���������
// ���ڴ𰸺ܴ󷵻ض�1000000007ȡ��Ľ��
// �������� : https://leetcode.cn/problems/find-all-good-strings/

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


// �ַ��� �� �ַ�����ƥ�� 
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

// �ַ��� �� �ַ� ��ƥ�� 
// ��ǰ�ַ���pick��һ��ʼƥ��e[j]
// ����next�������ƥ�䣬����ƥ�������λ��
// ���ƥ�䲻��������-1
// ���ε��õ�ʱ�临�Ӷ�O(1)
int jump(string e, char pick, int j)
{
	while(j >= 0 && pick != e[j]){
		j = nexts[j];
	}
	return j;
}

// ʱ�临�Ӷ�O(n * m * 2 * 26)
// s��e��n��m���ǹ̶�����
// 0...i-1�Ѿ����˾��ߣ��Ѿ�ƥ����e[0...j-1]�������
// ��ǰ����s[i]ʱ�����ȸÿ����ƥ��λ����e[j]
// ֮ǰ�ľ�������Ѿ���sС�ˣ�free == 1
// ֮ǰ�ľ��������s[0..i-1]һ����free == 0
// ���غ��������о����У�������e�ַ�����<=s�ľ����ж��ٸ���ͬʱ������ҪΪn
// ���� : ����e�ַ�����next�������ƥ��
// ��������λdp + ������evil�ַ��� 
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
		// ֮ǰ�ľ��ߺ�s��״��һ��
		// ��ǰ���Ա�curС���ַ�
		for(char pick = 'a'; pick < cur; pick++){
			ans = (ans + f(s, e, n, m, i + 1, jump(e, pick, j) + 1, 1)) % mod;
		}
		// ��ǰ���Ե���cur���ַ�
		ans = (ans + f(s, e, n, m, i + 1, jump(e, cur, j) + 1, 0)) % mod;
	}else{
		// ֮ǰ�ľ����Ѿ�ȷ��С��s��
		// ��ǰa~z��㳢��
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
	// <=s2�ĺ��ַ�������
	int ans = f(s2, evil, n, m, 0, 0, 0);
	clear(n, m);
	// ��ȥ<=s1�ĺ��ַ�������
	ans = (ans - f(s1, evil, n, m, 0, 0, 0) + mod) % mod;
	if(kmp(s1, evil, n, m) == -1){
		// ���s1������evil����s1Ҳ����ַ��� 
		ans = (ans + 1) % mod;
	}
	cout << ans << endl;
	return 0;
}


