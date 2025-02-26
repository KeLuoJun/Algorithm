// 去除重复字母保证剩余字符串的字典序最小
// 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次
// 需保证 返回结果的字典序最小
// 要求不能打乱其他字符的相对位置
// 测试链接 : https://leetcode.cn/problems/remove-duplicate-letters/

#include <iostream>
#include <vector>
using namespace std;

string removeDuplicateLetters(string s) 
{
    const int N = 26;
    int n = s.size();
    vector<int> cnts(N, 0);  // 词频表 
    vector<bool> enters(N, false);   // 栈中出现的词
	// false 表示该词没有出现在栈中 
    for(int i = 0; i < n; i++){
        cnts[s[i] - 'a']++;
    }
    vector<char> stack(n);   // 栈中保持大压小（确保栈中的字典序最小） 
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

