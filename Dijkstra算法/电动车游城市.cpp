// �綯���γ���
// С���ĵ綯����������ʱ����ʻ����Ϊ cnt��ÿ��ʻ 1 ��λ�������� 1 ��λ�������һ��� 1 ��λʱ��
// С����ѡ��綯����Ϊ�������ߡ���ͼ�Ϲ��� N �����㣬������Ϊ 0 ~ N-1
// ������ͼ��Ϣ�� [���� A ���,���� B ���,�����м����] ��ʽ�������ڶ�ά���� paths��
// ��ʾ���� A��B �����˫��ͨ·��
// ��ʼ״̬���綯������Ϊ 0��ÿ�����ж����г��׮��
// charge[i] ��ʾ�� i ������ÿ�� 1 ��λ������Ҫ���ѵĵ�λʱ�䡣
// �뷵��С��������Ҫ���Ѷ��ٵ�λʱ��������� start �ִ��յ���� end
// �������� : https://leetcode.cn/problems/DFPeFJ/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Compare{
	bool operator()(const vector<int>&a, const vector<int>&b){
		return a[2] > b[2];
	}
};

int electricCarPlan(vector<vector<int>>& paths, int cnt, int start, int end, vector<int>& charge)
{
	int n = charge.size();
	vector<vector<vector<int>>> graph;
	for(const auto&path : paths){
		graph[path[0]].push_back({path[1], path[2]});
		graph[path[1]].push_back({path[0], path[2]});
	}
	vector<vector<int>> distance(n, vector<int>(cnt + 1, INT_MAX));
	distance[start][0] = 0;
	vector<vector<bool>> visited(n, vector<bool>(cnt + 1, false));
	priority_queue<vector<int>, vector<vector<int>>, Compare> heap;
	heap.push({start, 0, 0});
	while(!heap.empty()){
		int cur = heap.top()[0];
		int power = heap.top()[1];
		int cost = heap.top()[2];
		if(visited[cur][power]){
			continue;
		}
		visited[cur][power] = true;
		if(cur == end){
			return cost;
		}
		if(power < cnt){
			if(!visited[cur][power + 1] && cost + charge[cur] < distance[cur][power + 1]){
				distance[cur][power + 1] = cost + charge[cur];
				heap.push({cur, power + 1, distance[cur][power + 1]});
			}
			
		}
		for(const auto& edge : graph[cur]){
			int nextCity = edge[0];
			int restPower = power - edge[1];
			int nextCost = cost + edge[1];
			if(restPower >= 0 && !visited[nextCity][restPower] && nextCost < distance[nextCity][restPower]){
				distance[nextCity][restPower] = nextCost;
				heap.push({nextCity, restPower, nextCost});
			}
		}
	}
	return -1;
}

int main()
{
	int n, m;
	int cnt, start, end;
	m = 3;
	cin >> n;
	cin >> cnt >> start >> end;
	vector<vector<int>> paths(n, vector<int>(m));
	vector<int> charge(n);

	for(int i = 0; i < n; i++){
		vector<int> tmp;
		int x;
		for(int j = 0; j < m; j++){
			cin >> x;
			tmp.push_back(x);
		}
		paths.push_back(tmp);
	}
	for(int i = 0; i < n; i++){
		cin >> charge[i];
	}
	
	int ans = electricCarPlan(paths, cnt, start, end, charge);
	cout << ans << endl;
	return 0;
}
