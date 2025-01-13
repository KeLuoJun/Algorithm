// 牛牛和他的朋友们约定了一套接头密匙系统，用于确认彼此身份
// 密匙由一组数字序列表示，两个密匙被认为是一致的，如果满足以下条件：
// 密匙 b 的长度不超过密匙 a 的长度。
// 对于任意 0 <= i < length(b)，有b[i+1] - b[i] == a[i+1] - a[i]
// 现在给定了m个密匙 b 的数组，以及n个密匙 a 的数组
// 请你返回一个长度为 m 的结果数组 ans，表示每个密匙b都有多少一致的密匙
// 数组 a 和数组 b 中的元素个数均不超过 10^5
// 1 <= m, n <= 1000

#include <bits/stdc++.h>   
#include <string>  
#include <vector>
using namespace std;
#define MAXN 10000

int cnt;
int tree[MAXN][12];
int *pass = new int[MAXN];


void build()
{
	cnt = 1;
}

int pathNum(char ch)
{
	if(ch == '#')
		return 10;
	else if(ch == '-')
		return 11;
	else
		return ch - '0';
}

void insert(string word)
{
	int cur = 1;
	pass[cur]++;
	for(int i = 0,path; i < word.size(); i++)
	{
		path = pathNum(word[i]);
		if(tree[cur][path] == 0)
			tree[cur][path] = ++cnt;
		cur = tree[cur][path];
		pass[cur]++;
	}
}


int count(string pre)
{
	int cur = 1;
	for(int i = 0,path; i < pre.size(); i++)
	{
		path = pathNum(pre[i]);
		if(tree[cur][path] == 0)
			return 0;
		cur = tree[cur][path];
	}
	return pass[cur];
}

void clear()
{
	for(int i = 0; i <= cnt; i++)
	{
		for(int j = 0; j < 12; j++)
			tree[i][j] = 0;
	}
}

vector<int> solve()
{
	cout << "请输入密钥a的数量：" ;
	int n;
	cin >> n;
	vector<int>v;
	string *a = new string[n];
	for(int i = 0; i < n; i++)
	{
		cout << "请输入第" << i+1 << "个密钥a：";
		cin >> a[i];
		string word;
		for(int j = 0; j < a[i].size(); j++)
		{
			word += to_string(a[i][j] - 'a') + '#';
		}
		insert(word);
	}
	cout << endl;
	cout << "请输入密钥b的数量：" ;
	int m;
	cin >> m;
	string *b = new string[m];
	for(int i = 0; i < m; i++)
	{
		cout << "请输入第" << i+1 << "个密钥b：";
		cin >> b[i];
		string pre;
		for(int j = 0; j < b[i].size(); j++)
		{
			pre += to_string(b[i][j] - 'a') + '#';
		}
		v.push_back(count(pre));
	}
	return v;
} 



int main()
{
	vector<int>v;
	v = solve();
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
		cout << *it << " ";
	cout << endl;
	clear(); 
	system("pause");
	return 0;
}
