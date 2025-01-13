// 不停删除之后剩下的字符串
// 给定一个字符串s1，如果其中含有s2字符串，就删除最左出现的那个
// 删除之后s1剩下的字符重新拼接在一起，再删除最左出现的那个
// 如此周而复始，返回最终剩下的字符串
// 测试链接 : https://www.luogu.com.cn/problem/P4824

#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int N = 1e6 + 1;
string s1, s2;
int stack1[N];
int stack2[N];
vector<int> nexts(N);
int size = 0;

void getNextArray(int m)
{
	nexts[0] = -1;
	nexts[1] = 0;
	int i = 2, cn = 0;
	while(i < m){
		if(s2[i - 1] == s2[cn]){
			nexts[i++] = ++cn;
		}else if(cn > 0){
			cn = nexts[cn];
		}else{
			nexts[i++] = 0;
		}
	}
}


void compute()
{
	int n = s1.size();
	int m = s2.size();
	getNextArray(m);
	int x = 0, y = 0;
	while(x < n){
		if(s1[x] == s2[y]){
			stack1[size] = x;
			stack2[size] = y;
			size++;
			x++;
			y++;
		}else if(y == 0){
			stack1[size] = x;
			stack2[size] = -1;
			size++;
			x++;
		}else{
			y = nexts[y];
		}
		if(y == m){
			size -= m;
			y = size > 0 ? (stack2[size - 1] + 1) : 0;
		}
	}
}

int main()
{
	cin >> s1 >> s2;
	compute();
	for(int i = 0; i < size; i++){
		cout << s1[stack1[i]];
	}
	cout << endl;
	return 0;
}


