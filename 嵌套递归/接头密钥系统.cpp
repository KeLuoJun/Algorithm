// ţţ������������Լ����һ�׽�ͷ�ܳ�ϵͳ������ȷ�ϱ˴����
// �ܳ���һ���������б�ʾ�������ܳױ���Ϊ��һ�µģ������������������
// �ܳ� b �ĳ��Ȳ������ܳ� a �ĳ��ȡ�
// �������� 0 <= i < length(b)����b[i+1] - b[i] == a[i+1] - a[i]
// ���ڸ�����m���ܳ� b �����飬�Լ�n���ܳ� a ������
// ���㷵��һ������Ϊ m �Ľ������ ans����ʾÿ���ܳ�b���ж���һ�µ��ܳ�
// ���� a ������ b �е�Ԫ�ظ����������� 10^5
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
	cout << "��������Կa��������" ;
	int n;
	cin >> n;
	vector<int>v;
	string *a = new string[n];
	for(int i = 0; i < n; i++)
	{
		cout << "�������" << i+1 << "����Կa��";
		cin >> a[i];
		string word;
		for(int j = 0; j < a[i].size(); j++)
		{
			word += to_string(a[i][j] - 'a') + '#';
		}
		insert(word);
	}
	cout << endl;
	cout << "��������Կb��������" ;
	int m;
	cin >> m;
	string *b = new string[m];
	for(int i = 0; i < m; i++)
	{
		cout << "�������" << i+1 << "����Կb��";
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
