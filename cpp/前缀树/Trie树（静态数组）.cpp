#include <iostream>
using namespace std;
#include <string>
#define MAXN 10000

int cnt;   //每个点对应的编号 
int tree[MAXN][26];
int pass[MAXN];   // 存储经过过程节点的次数 
int End[MAXN];    // 存储进过最后一个节点的次数 

void buildTrie()
{
	cnt = 1;
}

void insert(string word)
{
	int cur = 1; //目前遍历的位置 
	pass[cur]++;
	for(int i = 0,path; i < word.size(); i++)
	{
		path = (int)(word[i] - 'a');
		if(tree[cur][path] == 0)
			tree[cur][path] = ++cnt;
		cur = tree[cur][path];
		pass[cur]++;
	}
	End[cur]++;
}

int searchWord(string word)
{
	int cur = 1;
	for(int i = 0,path; i < word.size(); i++)
	{
		path = (int)(word[i] - 'a');
		if(tree[cur][path] == 0)
			return 0;
		cur = tree[cur][path];	
	}
	return End[cur];
}

int searchPre(string pre)
{
	int cur = 1;
	for(int i = 0, path; i < pre.size(); i++)
	{
		path = (int)(pre[i] - 'a');
		if(tree[cur][path] == 0)
			return 0;
		cur = tree[cur][path];
	}
	return pass[cur];
}

bool earse(string word)
{
	if(searchWord(word) > 0)
	{
		int cur = 1;
		pass[cur]--;
		for(int i = 0, path; i < word.size(); i++)
		{
			path = (int)(word[i] - 'a');
			if(--pass[tree[cur][path]] == 0)
			{
				tree[cur][path] = 0;
				return true;
			}
			cur = tree[cur][path];
		}
		return true;
	} 
	return false;
}

void clear()
{
	for(int i = 0; i <= cnt; i++)
	{
		for(int j = 0; j < 26; j++)
			tree[i][j] = 0;
		pass[i] = 0;
		End[i] = 0;
	}
}

void menu()
{
	cout << "-------------------------" << endl;
	cout << "1--插入单词" << endl; 
	cout << "2--删除单词" << endl;
	cout << "3--查找单词个数" << endl;
	cout << "4--查找单词前缀出现的次数" << endl; 
}

int main()
{
	cout << "请输入访问的次数："; 
	int m;
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		menu();
		int n;
		cin >> n;
		string word;
		int ans1 = 0, ans2 = 0;
		switch(n)
		{
			case 1:
				cout << "请插入单词：";
				cin >> word;
				insert(word);
				cout << "插入成功" << endl;
				break;
			case 2:
				cout << "请输入要删除的单词：";
				cin >> word;
				if(earse(word))
					cout << "删除成功" << endl;
				else
					cout << "该单词不存在，删除失败" << endl;
				break;
			case 3:
				cout << "请输入要查找的单词：";
				cin >> word;
				ans1 = searchWord(word);
				cout << word << "的个数为：" << ans1 << endl;
				break;
			case 4:
				cout << "请输入要查找的单词前缀：" ;
				cin >> word;
				ans2 = searchPre(word);
				cout << word << "的前缀数量为：" << ans2 << endl;
				break;		
		}
		system("pause");
		system("cls");
	}
	system("pause");
	return 0;
}
