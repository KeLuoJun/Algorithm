// ��������ģ�棨ţ�ͣ�
// �ڽӱ�ͼ����̬��ʽ��
// �������� : https://www.nowcoder.com/practice/88f7e156ca7d43a1a535f619cd3f495c#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20001;
// ���������õ�����
int Queue[MAXN];
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
bool topoSort(vector<vector<int>> &graph)
{
	int l,r;
	l = r = 0;
	for(int i = 1; i <= n; i++){
		if(indegree[i] == 0){
			Queue[r++] = i;
		}
	}
	int fill = 0;
	while(l < r){
		int cur = Queue[l++];
		ans[fill++] = cur;
		for (int next : graph[cur]) {  
            if (--indegree[next] == 0) {  
                Queue[r++] = next;  
            }  
        } 
	}
	return fill == n;
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
	if(!topoSort(graph)){
		cout << "-1" << endl;
	}else{
		for(int i = 0; i < n; i++){
			cout << ans[i] << " ";
		}
	}
	return 0;
 } 
