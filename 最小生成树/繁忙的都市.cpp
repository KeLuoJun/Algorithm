// ��æ�Ķ���
// һ���ǳ���æ�Ĵ��У������еĵ�·ʮ�ֵ�ӵ���������г����������еĵ�·���и���
// ���еĵ�·�������ֲ��ģ���������n������·�ڣ���Щ����·��֮���е�·����
// ��������·��֮�������һ����·�����ӣ���Щ��·��˫���
// �Ұ����еĽ���·��ֱ�ӻ��ӵ�����������
// ÿ����·����һ����ֵ����ֵԽС��ʾ�����·Խ��æ��Խ��Ҫ���и���
// �������������ʽ����ޣ��г�ϣ�����и���ĵ�·Խ��Խ�ã���������������Ҫ��
// 1. �������Щ��·�ܹ������еĽ���·��ֱ�ӻ��ӵ���ͨ����
// 2. ������Ҫ��1������£�����ĵ�·������
// 3. ������Ҫ��1��2������£��������Щ��·�з�ֵ���ĵ�·��ֵ����С
// ��Ϊ�й滮�ֵ��㣬Ӧ��������ѵľ��ߣ�ѡ����Щ��·Ӧ�����޽�
// ����ѡ���˼�����· �Լ� ��ֵ����������·�ķ�ֵ�Ƕ���
// �������� : https://www.luogu.com.cn/problem/P2330

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 301;
const int MAXM = 8001;
int father[MAXN];
vector<vector<int>> edges(MAXN, vector<int>(3));
int n, m;

void build()
{
	for(int i = 1; i <= n; i++){
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
			ans = max(ans, edge[2]);
		}
		if(edgeCnt == n - 1){
			break;
		}
	}
	cout << n - 1 << " " << ans << endl;
	return 0;
}
