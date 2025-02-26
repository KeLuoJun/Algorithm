#include <bits/stdc++.h>
using namespace std;
// ����������
const int MAXN = 11;
// �ߵ��������
// ֻ����ʽǰ���Ƿ�ʽ��ͼ��Ҫ�������
// ע���������ͼ�����������m���ߣ�����Ҫ׼��m*2
// ��Ϊһ�������Ҫ�����������
const int MAXM = 21;

// �ڽӾ���ʽ��ͼ
int graph1[MAXN][MAXM];

// �ڽӱ�ʽ��ͼ
// vector<vector<int>>graph2;
vector<vector<pair<int, int>>>graph2;

// �������Ȩ�أ���ô��Ҫ�������
int weight[MAXM];

void build(int n)
{
	// �ڽӾ������
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			graph1[i][j] = 0;
		}
	}
	// �ڽӱ���պ�׼��
	graph2.resize(n + 1);
}

// ���ַ�ʽ��������ͼ��Ȩͼ
void directGraph(int (*edges)[3], int n)
{
	// �ڽӾ���ͼ
	for(int i = 0; i < n; i++){
		graph1[edges[i][0]][edges[i][1]] = edges[i][2];
	}
	// �ڽӱ�ͼ
	for(int i = 0; i < n; i++){
		graph2[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
	}
	// ��ʽǰ���ǻ�ûѧ 
}

// ���ַ�ʽ��������ͼ��Ȩͼ
void undirectGraph(int (*edges)[3], int n)
{
	// �ڽӾ���ͼ
	for(int i = 0; i < n; i++){
		graph1[edges[i][0]][edges[i][1]] = edges[i][2];
		graph1[edges[i][1]][edges[i][0]] = edges[i][2];
	}
	// �ڽӱ�ͼ
	for(int i = 0; i < n; i++){
		graph2[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
		graph2[edges[i][1]].push_back(make_pair(edges[i][0], edges[i][2]));
	}
	
}

void traversal(int n)
{
	cout << "�ڽӾ���ı�����" << endl;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << graph1[i][j] << " ";
		}
		cout << endl;
	} 
	cout << "�ڽӱ�ı�����" << endl;
	for(int i = 1; i <= n; i++){
		cout << i << "�ھӡ���Ȩ��" ;
		// ע��߽����� 
		for(int j = 0; j < graph2[i].size(); j++){
			cout << "(" << graph2[i][j].first << "," << graph2[i][j].second << ")";
		}
		cout << endl;
	}
}


int main()
{
	// ����˴�Ȩͼ�Ľ������̣�Ҳ������˲���Ȩͼ
	// ��ı��Ϊ1...n
	// ����1�Լ���һ��ͼ�������Ȩͼ��Ȼ���ӡ���
	int n1 = 4;
	int edges1[MAXM][3] = { { 1, 3, 6 }, { 4, 3, 4 }, { 2, 4, 2 }, { 1, 2, 7 }, { 2, 3, 5 }, { 3, 1, 1 } };
	int edgenum1 = 6;
	build(n1);
	directGraph(edges1, edgenum1);
	traversal(n1);
	cout << "===============================" << endl;
	int n2 = 5;
	int edges2[MAXM][3] = { { 3, 5, 4 }, { 4, 1, 1 }, { 3, 4, 2 }, { 5, 2, 4 }, { 2, 3, 7 }, { 1, 5, 5 }, { 4, 2, 6 } };
	int edgenum2 = 7;
	build(n2);
	undirectGraph(edges2, edgenum2);
	traversal(n2);
	return 0;
}

