// �ֵ�����С����������
// Ҫ�󷵻�������ȷ������������ �ֵ�����С �Ľ��
// ��ͼ��ʹ����ʽǰ���Ƿ�ʽ����Ϊ����ƽ̨��������ͼ��ʽ�Ῠ�ռ�
// �������� : https://www.luogu.com.cn/problem/U107394

// �ڽӱ� 
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20001;
//С���� 
priority_queue<int, vector<int>, greater<int>>heap;
// ����������ȱ�
int indegree[MAXN];
// �ռ���������Ľ��
int ans[MAXN];
int n,m;

void build(vector<vector<int>> &graph)
{
	memset(indegree, 0, sizeof(indegree));
	graph.resize(n + 1);
}

// ���������򷵻�true
// û���������򷵻�false
void topoSort(vector<vector<int>> &graph)
{
	for(int i = 1; i <= n; i++){
		if(indegree[i] == 0){
			heap.push(i);
		}
	}
	int fill = 0;
	while(!heap.empty()){
		int cur = heap.top();
		heap.pop();
		ans[fill++] = cur;
		for (int next : graph[cur]) {  
            if (--indegree[next] == 0) {  
                heap.push(next);  
            }  
        } 
	}
}

int main()
{
	cin >> n >> m;
	vector<vector<int>> graph;
	build(graph);
	int from,to;
	for(int i = 0; i < m; i++){
		cin >> from >> to;
		graph[from].push_back(to);
		indegree[to]++;
	}
	topoSort(graph);
	for(int i = 0; i < n; i++){
		cout << ans[i] << " ";
	}
	return 0;
 } 
