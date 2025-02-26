// ȥ���ظ���ĸ��֤ʣ���ַ������ֵ�����С
// ����һ���ַ��� s ������ȥ���ַ������ظ�����ĸ��ʹ��ÿ����ĸֻ����һ��
// �豣֤ ���ؽ�����ֵ�����С
// Ҫ���ܴ��������ַ������λ��
// �������� : https://leetcode.cn/problems/remove-duplicate-letters/

#include <iostream>
#include <vector>
using namespace std;

string removeDuplicateLetters(string s) 
{
    const int N = 26;
    int n = s.size();
    vector<int> cnts(N, 0);  // ��Ƶ�� 
    vector<bool> enters(N, false);   // ջ�г��ֵĴ�
	// false ��ʾ�ô�û�г�����ջ�� 
    for(int i = 0; i < n; i++){
        cnts[s[i] - 'a']++;
    }
    vector<char> stack(n);   // ջ�б��ִ�ѹС��ȷ��ջ�е��ֵ�����С�� 
    int r = 0;
    for(int i = 0; i < n; i++){
        if(!enters[s[i] - 'a']){
            while(r > 0 && stack[r - 1] > s[i] && cnts[stack[r - 1] - 'a'] > 0){
                enters[stack[r - 1] - 'a'] = false;
                r--;
            }
            stack[r++] = s[i];
            enters[s[i] - 'a'] = true;
        }
        cnts[s[i] - 'a']--;
    }
    string ans = "";
    for(int i = 0; i < r; i++){
        ans += stack[i];
    }
    return ans;
}

int main()
{
	string s;
	cin >> s;
	string ans = removeDuplicateLetters(s);
	cout << ans << endl;
	return 0;
}

