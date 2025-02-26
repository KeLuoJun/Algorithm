// �ظ������ַ���ƥ��
// ���������ַ���a��b��Ѱ���ظ������ַ���a����С������ʹ���ַ���b��Ϊ���Ӻ���ַ���a���Ӵ�
// ����������򷵻�-1
// �ַ���"abc"�ظ�����0����""
// �ظ�����1����"abc"
// �ظ�����2����"abcabc"
// �������� : https://leetcode.cn/problems/repeated-string-match/


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
	// m/n ����ȡ�� 
	int k = (m + n - 1) / n;
	// s1�ĳ����Ϊ�ﵽs2�ĳ��Ⱥ��ټ�һ������ĳ���
	// ����ⶼ�������㣬���ٵ���s1Ҳ���������� 
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
			// �����е㲻����� 
			ans = r < k * n ? k : (k + 1);
		}
	}
	cout << ans << endl;
	return 0;
}

