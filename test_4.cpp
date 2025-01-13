#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
const int MAXN = 100006;
const int MAXM = 500006;
int n, k;
int edgeCnt;
vector<vector<int>> times; 


struct Compare{
	bool operator()(const vector<int>&a, const vector<int>&b){
		return a[1] < b[1];
	}
};



int networkDelayTime1(vector<vector<int>>& times, int n, int s) {
    vector<vector<pair<int, int>>> graph(n + 1);
    for (const auto& edge : times) {
        graph[edge[0]].emplace_back(edge[1], edge[2]);
    }

    vector<int> distance(n + 1, INT_MAX);
    distance[s] = 0;
	vector<bool> visited(n + 1, false);
    priority_queue<vector<int>, vector<vector<int>>, Compare> heap;
    heap.emplace(s, 0);

    while (!heap.empty()) {
        int u = heap.top()[0];
        heap.pop();
        
        if(visited[u]){         
			continue;
		}
		visited[u] = true;

        for(const auto& edge : graph[u]){
			int v = edge[0];   // 当前点指向的下一个节点 
			int w = edge[1];
			if(!visited[v] && distance[u] + w < distance[v]){
				distance[v] = distance[u] + w;
				heap.push({v, distance[v]});
			}
		}
    }

    int ans = INT_MIN;
    for (int i = 1; i <= n; i++) {
        if (distance[i] == INT_MAX) {
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
	cout << networkDelayTime1(times, n, k) << endl;
	return 0;
}
