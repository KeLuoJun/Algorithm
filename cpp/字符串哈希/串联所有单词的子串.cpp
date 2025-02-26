// 串联所有单词的子串（未解决） 
// 给定一个字符串s和一个字符串数组words
// words中所有字符串长度相同
// s中的串联子串是指一个包含 words中所有字符串以任意顺序排列连接起来的子串
// 例如words = { "ab","cd","ef" }
// 那么"abcdef"、"abefcd"、"cdabef"、"cdefab"、"efabcd"、"efcdab"都是串联子串。 
// "acdbef"不是串联子串，因为他不是任何words排列的连接
// 返回所有串联子串在s中的开始索引
// 你可以以任意顺序返回答案
// 测试链接 : https://leetcode.cn/problems/substring-with-concatenation-of-all-words/

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int base = 499;
const int N = 1000;
int pow[N];
int hashs[N];
int wordNum;
vector<string> words;

long getHash(string str)
{
	int n = str.size();
	long ans = str[0] - 'a' + 1;
	for(int j = 1; j < n; j++){
		ans = ans * base + str[j] - 'a' + 1;
	}
	return ans;
}

long getHash(int l, int r)
{
	long ans = hashs[r];
	if(l > 0){
		ans -= hashs[l - 1] * pow[r - l + 1];
	}
	return ans;
}

void build(string s)
{
	pow[0] = 1;
	for(int j = 1; j < N; j++){
		pow[j] = pow[j - 1] * base;
	}
	hashs[0] = s[0] - 'a' + 1;
	for(int j = 1; j < s.size(); j++){
		hashs[j] = hashs[j - 1] * base + s[j] - 'a' + 1;
	}
}

vector<int> findSubstring(string s)
{
	vector<int> ans;
	if(s == "" || s.size() == 0 || words.size() == 0){
		return ans;
	}
	map<long, int> m;    // words的词频表 
	for(string key : words){
		long v = getHash(key);
		if(m.find(v) == m.end()){
			m.insert(make_pair(v, 1));
		}else{
			m[v] += 1;
		}
	}
	build(s);
	int n = s.size();
	int wordLen = words[0].size();
	int allLen = wordNum * wordLen;
	// 窗口的词频表
	map<long, int> window;
	// 初步建立第一个窗口 
	for(int init = 0; init < wordLen && init + allLen <= n; init++){
		// init是当前组的首个开头
		int debt = wordNum;  // 欠债的单词个数 
		for(int l = init, r = init + wordLen, part = 0; part < wordNum; l += wordLen, r += wordLen, part++){
			long cur = getHash(l, r);
			auto it = window.find(cur);
			if(it != window.end()){
				window[cur] += 1;
			}else{
				window[cur] = 1;
			}
			if(window[cur] <= (m.count(cur) ? m[cur] : 0)){
				debt--;
			}
		}
		if(debt == 0){
			ans.push_back(init);
		}
		
	// 滑动窗口 
	// 接下来窗口进一个、出一个
	// s  k  d  f  v  b  s  k  j  v  b  s  d  v  c  s  v
	// l1    r1                            l2      r2
	// ................................... ->已构建的初步窗口 
	for(int l1 = init, r1 = init + wordLen, l2 = init + allLen,
		r2 = init + allLen + wordLen; r2 <= n; l1 += wordLen, r1 += wordLen, l2 += wordLen, r2 += wordLen){
			long out = getHash(l1, r1);
			long in = getHash(l2, r2);
			window[out]--;
			if(window[out] < (m.count(out) ? m[out] : 0)){
				debt++;
			}
			auto it = window.find(in);
			if(it != window.end()){
				window[in]++;
			}else{
				window[in] = 1;
			}
			if(window[in] <= (m.count(in) ? m[in] : 0)){
				debt--;
			}
			if(debt == 0){
				ans.push_back(r1);
			}
		}		
	window.clear();	
	}
	return ans;
}

int main()
{
	string s = "";
	cin >> s;
	cin >> wordNum;
	for(int i = 0; i < wordNum; i++){
		cin >> words[i];
	}
	vector<int> ans = findSubstring(s);
	for(vector<int>::iterator it = ans.begin(); it < ans.end(); it++){
		cout << *it << " ";
	}
	return 0;
}

