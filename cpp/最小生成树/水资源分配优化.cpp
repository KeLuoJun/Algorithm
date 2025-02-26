// 水资源分配优化
// 村里面一共有 n 栋房子。我们希望通过建造水井和铺设管道来为所有房子供水。
// 对于每个房子 i，我们有两种可选的供水方案：一种是直接在房子内建造水井
// 成本为 wells[i - 1] （注意 -1 ，因为 索引从0开始 ）
// 另一种是从另一口井铺设管道引水，数组 pipes 给出了在房子间铺设管道的成本，
// 其中每个 pipes[j] = [house1j, house2j, costj] 
// 代表用管道将 house1j 和 house2j连接在一起的成本。连接是双向的。
// 请返回 为所有房子都供水的最低总成本
// 测试链接 : https://leetcode.cn/problems/optimize-water-distribution-in-a-village/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 10010;
int n, m;
int wells[N];
int pipes[N][3];
vector<vector<int>> edges(N, vector<int>(3));
int father[N];
int cnt;   // 重新设计后的边的数量 
// 模型将 在每个房子打井的成本 设定为：
// 存在一个公共水源，编号为0
// 公共水源到每一个房子的距离为打井的成本 

void build()
{
	cnt = 0;
	for(int i = 1; i <= n; i++){
		father[i] = i;
	}
}

int find(int i)
{
	if(father[i] != i){
		father[i] = find(father[i]);
	}
	return father[i];
}

// 如果x和y，原本是一个集合，返回false
// 如果x和y，不是一个集合，合并之后后返回true
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

int minCostToSupplyWater()
{
	build();
	for(int i = 0; i < n; i++, cnt++){
		vector<int>tmp;
		tmp.push_back(0);
		tmp.push_back(i + 1);
		tmp.push_back(wells[i]);
		edges.push_back(tmp);
	}
	for(int i = 0; i < m; i++, cnt++){
		vector<int> tmp;
		for(int j = 0; j < 3; j++){
			tmp.push_back(pipes[i][j]);
		}
		edges.push_back(tmp);
	}
	sort(edges.begin(), edges.end(), [](const vector<int>&a, const vector<int>&b){
		return a[2] < b[2];
	});
	int ans = 0;
	for(vector<int> edge : edges){
		if(unions(edge[0], edge[1])){
			ans += edge[2];
		}
	}
	return ans;
}



int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> wells[i];
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < 3; j++){
			cin >> pipes[i][j];
		}
	}
	int ans = minCostToSupplyWater();
	cout << ans << endl;
	return 0;
}


