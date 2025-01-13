#include <iostream>
using namespace std;
#include <string>
#define MAXN 10000

int cnt;   //ÿ�����Ӧ�ı�� 
int tree[MAXN][26];
int pass[MAXN];   // �洢�������̽ڵ�Ĵ��� 
int End[MAXN];    // �洢�������һ���ڵ�Ĵ��� 

void buildTrie()
{
	cnt = 1;
}

void insert(string word)
{
	int cur = 1; //Ŀǰ������λ�� 
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
	cout << "1--���뵥��" << endl; 
	cout << "2--ɾ������" << endl;
	cout << "3--���ҵ��ʸ���" << endl;
	cout << "4--���ҵ���ǰ׺���ֵĴ���" << endl; 
}

int main()
{
	cout << "��������ʵĴ�����"; 
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
				cout << "����뵥�ʣ�";
				cin >> word;
				insert(word);
				cout << "����ɹ�" << endl;
				break;
			case 2:
				cout << "������Ҫɾ���ĵ��ʣ�";
				cin >> word;
				if(earse(word))
					cout << "ɾ���ɹ�" << endl;
				else
					cout << "�õ��ʲ����ڣ�ɾ��ʧ��" << endl;
				break;
			case 3:
				cout << "������Ҫ���ҵĵ��ʣ�";
				cin >> word;
				ans1 = searchWord(word);
				cout << word << "�ĸ���Ϊ��" << ans1 << endl;
				break;
			case 4:
				cout << "������Ҫ���ҵĵ���ǰ׺��" ;
				cin >> word;
				ans2 = searchPre(word);
				cout << word << "��ǰ׺����Ϊ��" << ans2 << endl;
				break;		
		}
		system("pause");
		system("cls");
	}
	system("pause");
	return 0;
}
