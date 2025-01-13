#include <bits/stdc++.h>
using namespace std;
// 点的最大数量
const int MAXN = 11;
// 边的最大数量
// 只有链式前向星方式建图需要这个数量
// 注意如果无向图的最大数量是m条边，数量要准备m*2
// 因为一条无向边要加两条有向边
const int MAXM = 21;

// 邻接矩阵方式建图
int graph1[MAXN][MAXM];

// 邻接表方式建图
// vector<vector<int>>graph2;
vector<vector<pair<int, int>>>graph2;

// 如果边有权重，那么需要这个数组
int weight[MAXM];

void build(int n)
{
	// 邻接矩阵清空
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			graph1[i][j] = 0;
		}
	}
	// 邻接表清空和准备
	graph2.resize(n + 1);
}

// 三种方式建立有向图带权图
void directGraph(int (*edges)[3], int n)
{
	// 邻接矩阵建图
	for(int i = 0; i < n; i++){
		graph1[edges[i][0]][edges[i][1]] = edges[i][2];
	}
	// 邻接表建图
	for(int i = 0; i < n; i++){
		graph2[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
	}
	// 链式前向星还没学 
}

// 三种方式建立无向图带权图
void undirectGraph(int (*edges)[3], int n)
{
	// 邻接矩阵建图
	for(int i = 0; i < n; i++){
		graph1[edges[i][0]][edges[i][1]] = edges[i][2];
		graph1[edges[i][1]][edges[i][0]] = edges[i][2];
	}
	// 邻接表建图
	for(int i = 0; i < n; i++){
		graph2[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
		graph2[edges[i][1]].push_back(make_pair(edges[i][0], edges[i][2]));
	}
	
}

void traversal(int n)
{
	cout << "邻接矩阵的遍历：" << endl;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << graph1[i][j] << " ";
		}
		cout << endl;
	} 
	cout << "邻接表的遍历：" << endl;
	for(int i = 1; i <= n; i++){
		cout << i << "邻居、边权：" ;
		// 注意边界问题 
		for(int j = 0; j < graph2[i].size(); j++){
			cout << "(" << graph2[i][j].first << "," << graph2[i][j].second << ")";
		}
		cout << endl;
	}
}


int main()
{
	// 理解了带权图的建立过程，也就理解了不带权图
	// 点的编号为1...n
	// 例子1自己画一下图，有向带权图，然后打印结果
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

