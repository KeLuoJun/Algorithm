// 独特子串的数量
// 给你一个由数字组成的字符串s
// 返回s中独特子字符串数量（独特子串不能重复） 
// 其中的每一个数字出现的频率都相同
// 测试链接 : https://leetcode.cn/problems/unique-substrings-with-equal-digit-frequency/

#include <iostream>
#include <string>
#include <string.h>
#include <set>
using namespace std;
const int base = 499;

int equalDigitFrequency(string s)
{
	int n = s.size();
	int cnt[10];   // 词频表 
	set<long> hs;
	for(int i = 0; i < n; i++){
		memset(cnt, 0, sizeof(cnt));  // 每次cnt都要清零 
		long hashCode = 0;  // 当前字符串的哈希值
		// curVal 当前数字字符转换为数字后的值
		// maxCnt 当前出现最大词频的数字的词频值
		// maxCurKinds 拥有与当前最大词频相同的字符种类
		// allKinds 当前字符串中字符的种类 
		int curVal = 0, maxCnt = 0, maxCntKinds = 0, allKinds = 0;
		for(int j = i; j < n; j++){
			curVal = s[i] - '0';
			hashCode = hashCode * base + curVal + 1;
			cnt[curVal]++;
			if(cnt[curVal] == 1){   
				// 表示当前字符在当前字符串中只出现一次
				// 把该字符加在字符的种类中 
				allKinds++;
			}
			if(cnt[curVal] > maxCnt){
				// 当前字符的词频大于目前字符串中的最大词频
				maxCnt = cnt[curVal]; // 更新字符串的最大词频 
				maxCntKinds = 1;      // 把拥有与当前最大词频相同的字符种类更新位1 
			}else if(cnt[curVal] == maxCnt){
				maxCntKinds++;
			}
			if(maxCntKinds == allKinds){
				// 说明当前字符串中的每种字符出现的次数相同
				//  是独特子串 
				hs.insert(hashCode);
			}
		}
	}
	return hs.size();
}


int main()
{
	string s;
	cin >> s;
	int ans = equalDigitFrequency(s);
	cout << ans << endl;
	return 0;
}
