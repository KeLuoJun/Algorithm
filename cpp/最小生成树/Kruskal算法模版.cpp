// Kruskal算法模版（洛谷）
// 静态空间实现
// 测试链接 : https://www.luogu.com.cn/problem/P3366
// 并查集 + 对边的权值排序 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 5001;
const int MAXM = 200001;
int father[MAXN];
vector<vector<int>> edges(MAXM, vector<int>(3));
int n, m;

void build()
{
	for(int i  =1; i <= n; i++){
		father[i] = i;
	}
}

int find(int i)
{
	if(i != father[i]){
		father[i] = find(father[i]);
	}
	return father[i];
}

bool unions(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if(fx != fy){
		father[fx] = fy;
		return true;
	}else{
		return false;
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		vector<int> tmp;
		int x;
		for(int j = 0; j < 3; j++){
			cin >> x;
			tmp.push_back(x);
		}
		edges.push_back(tmp);
	}
	sort(edges.begin(), edges.end(), [](const vector<int>&a, const vector<int>&b){
		return a[2] < b[2];
	});
	build();
	int ans = 0;
	int edgeCnt = 0;
	for(vector<int> edge : edges){
		if(unions(edge[0], edge[1])){
			edgeCnt++;
			ans += edge[2];
		}
	}
	if(edgeCnt == n - 1){
		cout << ans << endl;
	}else{
		cout << "orz" << endl;
	}
	return 0;
}

