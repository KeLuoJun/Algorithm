// ˮ��Դ�����Ż�
// ������һ���� n �����ӡ�����ϣ��ͨ������ˮ��������ܵ���Ϊ���з��ӹ�ˮ��
// ����ÿ������ i�����������ֿ�ѡ�Ĺ�ˮ������һ����ֱ���ڷ����ڽ���ˮ��
// �ɱ�Ϊ wells[i - 1] ��ע�� -1 ����Ϊ ������0��ʼ ��
// ��һ���Ǵ���һ�ھ�����ܵ���ˮ������ pipes �������ڷ��Ӽ�����ܵ��ĳɱ���
// ����ÿ�� pipes[j] = [house1j, house2j, costj] 
// �����ùܵ��� house1j �� house2j������һ��ĳɱ���������˫��ġ�
// �뷵�� Ϊ���з��Ӷ���ˮ������ܳɱ�
// �������� : https://leetcode.cn/problems/optimize-water-distribution-in-a-village/


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
int cnt;   // ������ƺ�ıߵ����� 
// ģ�ͽ� ��ÿ�����Ӵ򾮵ĳɱ� �趨Ϊ��
// ����һ������ˮԴ�����Ϊ0
// ����ˮԴ��ÿһ�����ӵľ���Ϊ�򾮵ĳɱ� 

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

// ���x��y��ԭ����һ�����ϣ�����false
// ���x��y������һ�����ϣ��ϲ�֮��󷵻�true
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


