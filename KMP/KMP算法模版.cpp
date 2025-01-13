// KMP�㷨ģ�棨���� P100�� 
// �������� : https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// next���麬�壺��Ҫ���ڼ�¼ģʽ�������ǰ׺�ͺ�׺�����������
// ������˵�� 
// ���next[i] = -1����ʾ��û���κ���Чǰ׺�ͺ�׺�������ã����ߵ�����ģʽ���Ŀ�ʼ��
// ���next[i] = k��k >= 0�������ʾ��ģʽ����ǰ׺�Ӵ�s2[0...i-1]��Ŀ�괮��һ���Ӵ�ʧ��ʱ��
// ���Դ�ģʽ���ĵ�k+1���ַ���ʼ��Ŀ�괮����һ���ַ����±Ƚϣ�
// ��Ϊs2[0...k]��s2[i-k...i-1]����ȵģ�������һ������Ϊk+1����ͬǰ��׺


// �õ�next����
vector<int> getNextArray(string s)
{
	int m = s.size();
	if(m == 1){
		return vector<int>{-1};
	}
	vector<int> next(m);
	next[0] = -1;
	next[1] = 0;
	
	// i��ʾ��ǰҪ��nextֵ��λ��
	// cn��ʾ��ǰҪ��ǰһ���ַ��ȶԵ��±�
	int i = 2, cn = 0;
	while(i < m){
		if(s[i - 1] == s[cn]){
			next[i++] = ++cn;
		}else if(cn > 0){
			cn = next[cn];
		}else{
			next[i++] = 0;
		}
	}
	return next;
}


int kmp(string s1, string s2)
{
	// s1�е�ǰ�ȶԵ�λ����x
	// s2�е�ǰ�ȶԵ�λ����y
	int n = s1.size();
	int m = s2.size();
	int x = 0, y = 0;
	// O(m)
	vector<int> next = getNextArray(s2);
	// O(n)
	while(x < n && y < m){
		if(s1[x] == s2[y]){
			x++;
			y++;
		}else if(y == 0){
			x++;
		}else{
			y = next[y];
		}
	}
	return y == m ? x - y : -1;
} 

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int ans = kmp(s1, s2);
	cout << ans << endl;
	return 0;
} 
