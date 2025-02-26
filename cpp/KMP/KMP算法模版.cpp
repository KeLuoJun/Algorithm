// KMP算法模版（左神 P100） 
// 测试链接 : https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// next数组含义：主要用于记录模式串自身的前缀和后缀的最长公共长度
// 具体来说： 
// 如果next[i] = -1，表示还没有任何有效前缀和后缀可以利用，或者到达了模式串的开始。
// 如果next[i] = k（k >= 0），则表示当模式串的前缀子串s2[0...i-1]与目标串的一个子串失配时，
// 可以从模式串的第k+1个字符开始与目标串的下一个字符重新比较，
// 因为s2[0...k]和s2[i-k...i-1]是相等的，即存在一个长度为k+1的相同前后缀


// 得到next数组
vector<int> getNextArray(string s)
{
	int m = s.size();
	if(m == 1){
		return vector<int>{-1};
	}
	vector<int> next(m);
	next[0] = -1;
	next[1] = 0;
	
	// i表示当前要求next值的位置
	// cn表示当前要和前一个字符比对的下标
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
	// s1中当前比对的位置是x
	// s2中当前比对的位置是y
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
