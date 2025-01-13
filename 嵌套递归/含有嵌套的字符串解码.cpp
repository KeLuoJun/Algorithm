// 输出类似 uu3[rr2[ff]]hh 的展开结果
// 测试链接 : https://leetcode.cn/problems/decode-string/ 

#include <iostream>
using namespace std;
#include <string>
#include <vector>

int where = 0;

string get(int cnt, string s)
{
	string str;
	for(int i = 0; i < cnt; i++)
		str += s;
	return str;
}


string f(string s,int i)
{
	vector<char> path;
	int cnt = 0;
	while(i < s.size() && s[i] != ']'){
		if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z'){
			path.push_back(s[i++]);
		} else if(s[i] >= '0' && s[i] <= '9'){
			cnt = (int)(s[i++] - '0');
		} else{  // 命中了 '[' 
			string str = get(cnt,f(s,i+1));
			for(int j = 0; j < str.size(); j++)
				path.push_back(str[j]);
			i = where + 1;
			cnt = 0;
		}
	}
	where = i;
	string str;
	for(vector<char>::iterator it = path.begin(); it != path.end(); it++)
		str += *it;
	return str;
}


int main()
{
	string s;
	cin >> s;
	string ans = f(s,0);
	cout << ans << endl;
	return 0;
 } 
