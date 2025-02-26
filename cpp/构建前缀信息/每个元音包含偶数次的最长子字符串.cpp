// ÿ��Ԫ������ż���ε�����ַ���
// ����һ���ַ��� s �����㷵��������������������ַ����ĳ���
// ÿ��Ԫ����ĸ���� 'a'��'e'��'i'��'o'��'u'
// �����ַ����ж�ǡ�ó�����ż���Ρ�
// �������� : https://leetcode.cn/problems/find-the-longest-substring-containing-vowels-in-even-counts/

#include <bits/stdc++.h>
using namespace std;
string s;
// ֻ��5��Ԫ���ַ���״̬��5λ
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
	// m[01100] = -2, ���״̬֮ǰû���ֹ�
	for(int i = 0, cur = 0; i < s.size(); i++){
		cur = moved(s[i]);
		if(cur != -1){
			// status : 0....i-1�ַ����ϣ�aeiou����ż��
			// s[i] = ��ǰ�ַ�
			// ���1 : ��ǰ�ַ�����Ԫ����status����
			// ���2 : ��ǰ�ַ���Ԫ����a~u(0~4)���޸���Ӧ��״̬
			status <<= cur;
			// status:  0....i�ַ����ϣ�aeiou����ż��
			// ͬ����״̬��֮ǰ�����������
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
