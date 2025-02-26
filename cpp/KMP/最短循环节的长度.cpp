// 最短循环节的长度
// 给你一个字符串s，它一定是由某个循环节不断自我连接形成的
// 题目保证至少重复2次，但是最后一个循环节不一定完整
// 现在想知道s的最短循环节是多长
// 测试链接 : https://www.luogu.com.cn/problem/P4391

#include <iostream>
using namespace std;
const int N = 1e6 + 1;
int n;
int nexts[N];
string s;

void getNextArray()
{
	nexts[0] = -1;
	nexts[1] = 0;
	int i = 2, cn = 0;
	while(i <= n){
		if(s[i - 1] == s[cn]){
			nexts[i++] = ++cn;
		}else if(cn > 0){
			cn = nexts[cn];
		}else{
			nexts[i++] = 0;
		}
	}
}

int compute()
{
	getNextArray();
	return n - nexts[n];
}

int main()
{
	cin >> n;
	cin >> s;
	cout << compute() << endl;
	return 0;
} 
