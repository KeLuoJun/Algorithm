// Dijkstra�㷨ģ�棨Leetcode��
// �����ӳ�ʱ��
// �� n ������ڵ㣬���Ϊ 1 �� n
// ����һ���б� times����ʾ�źž��� ���� �ߵĴ���ʱ��
// times[i] = (ui, vi, wi)����ʾ��ui��vi�����źŵ�ʱ����wi
// ���ڣ���ĳ���ڵ� s ����һ���ź�
// ��Ҫ��ò���ʹ���нڵ㶼�յ��ź�
// �������ʹ���нڵ��յ��źţ����� -1
// �������� : https://leetcode.cn/problems/network-delay-time



/*
                    Dijkstra�㷨�������� 
1��distance[i]��ʾ��Դ�㵽i�����̾��룬visited[i]��ʾi�ڵ��Ƿ��С���ѵ�����
2��׼����С���ѣ�С���Ѵ�ż�¼��(x�㣬Դ�㵽x�ľ���)��С���Ѹ��ݾ�����֯
3����distance[Դ��]=0��(Դ�㣬0)����С����
4����С���ѵ���(u�㣬Դ�㵽u�ľ���)
   a. ���visited[u] == true�������κδ����ظ�����4
   b. ���visited[u] == false����visited[u] = true��u���㵯������
      Ȼ�󿼲�u��ÿһ���ߣ�����ĳ��ȥ��v����ȨΪw
      1�����visited[v] == false ���� distance[u] + w < distance[v]
         ��distance[v] = distance[u] + w����(v, distance[u] + w)����С����
      2��������u��ÿһ����֮���ظ�����4
5��С����Ϊ�չ��̽�����distance���¼��Դ�㵽ÿ���ڵ����̾��롣
*/

// ʱ�临�Ӷ� O(m * logm) 
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, k;
int edgeCnt;
vector<vector<int>> times;    // �൱�ڱ� 


struct Compare{
	bool operator()(const vector<int>&a, const vector<int>&b){
		return a[1] > b[1];    // С���ѵıȽ��� 
	}
};

// ��̬��ͼ+��ͨ�ѵ�ʵ��
int networkDelayTime1()
{
	vector<vector<vector<int>>> graph(n + 1);    // �����ڽӱ� 
	for(vector<int> edge : times){
		graph[edge[0]].push_back({edge[1], edge[2]});
	}
	vector<int> distance(n + 1, INT_MAX); // Ŀǰԭ�㵽��i�������̾��� 
	distance[k] = 0;
	vector<bool> visited(n + 1, false);   // �����ʹ��ĵ� 
	// 0 : ��ǰ�ڵ�
	// 1 : Դ�㵽��ǰ�����
	priority_queue<vector<int>, vector<vector<int>>, Compare> heap;
	heap.push({k, 0});    // ��ԭ���ȷ���С������ 
	while(!heap.empty()){
		int u = heap.top()[0];   // ȡ�뵱ǰ�ڵ�����ָ��Ľڵ� 
		heap.pop();
		if(visited[u]){         
			continue;
		}
		visited[u] = true;
		for(const auto& edge : graph[u]){
			int v = edge[0];   // ��ǰ��ָ�����һ���ڵ� 
			int w = edge[1];
			if(!visited[v] && distance[u] + w < distance[v]){
				distance[v] = distance[u] + w;
				heap.push({v, distance[u] + w});
			}
		}
	}
	int ans = INT_MIN;
	for(int i = 1; i <= n; i++){
		// ���distance���δ��� INT_MAX����˵����Щ���޷����� 
		if(distance[i] == INT_MAX){
			return -1;
		}
		ans = max(ans, distance[i]);
	}	
	return ans;
}


int main()
{
	cin >> n >> edgeCnt >> k;
	int u, v, w;
	for(int i = 0; i < edgeCnt; i++){
		vector<int> tmp;
		cin >> u >> v >> w;
		tmp.push_back(u);
		tmp.push_back(v);
		tmp.push_back(w);
		times.push_back(tmp);
	}
	cout << networkDelayTime1() << endl;
	return 0;
}
