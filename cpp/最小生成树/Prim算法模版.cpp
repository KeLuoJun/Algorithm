// 1�������ĵ�ļ��Ͻ�set����ͨ���ϣ��������ıߵļ��Ͻ�heap��С���ѣ�
// set��heap��Ϊ��
// 2�����Դ�����㿪ʼ����ʼ����뵽set�У���ʼ������б߼��뵽heap��
// 3����heap�е���Ȩֵ��С�ı�e���鿴��e��ȥ���ĵ�x
//    A�����x�Ѿ���set�У���e�������ظ�����3
//    B�����x����set�У���e������С����������x����set���ظ�����3
// 4����heapΪ�գ��õ���С������ 

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ������󶥵�����
int MaxVexNum = 10;
int n;   // ��ĸ��� 

// �洢�ߵ����飬ÿ��Ԫ��Ϊ{��㣬�յ㣬Ȩ��}
int edges[11][3] = {{1, 2, 4}, {2, 0, 8}, {2, 5, 9}, {3, 5, 6}, {3, 2, 5},
					{4, 3, 5}, {5, 4, 1}, {5, 0, 3}, {0, 5, 3}, {0, 1, 5}, {0, 3, 7}};
						  
// ͼ���ڽӱ�ʹ����ά�����洢�������ʾ�ߵ���Ϣ���յ㣬Ȩ�أ�
vector<vector<vector<int>>> graph(MaxVexNum);

// ����ͼ���ڽӱ�
void build()
{
	for(const auto& edge : edges){
		// ��ÿ���ߵ���Ϣ�����Ӧ�������ڽӱ���
		graph[edge[0]].push_back({edge[1], edge[2]});
	}
	// ���ö�������
	n = 6;
}

// ��ӡͼ���ڽӱ�
void showGraph()
{
	cout << "ͼ���ڽӱ�Ϊ��" << endl;
	for(int i = 0; i < n; i++){
		cout << i; // ��ӡ��ǰ������
		// �����ö�������г��߲���ӡ
		for(const auto& edge : graph[i]){
			cout << " --(" << edge[1] << ")-->" << edge[0]; 
		}
		cout << endl; // ����
	}
}

// �Զ���Ƚ���������С���ѣ����ߵ�Ȩ������
struct Compare{
	bool operator()(const vector<int>&a, const vector<int>&b){
		return a[2] > b[2]; // ���a��Ȩ�ش���b��Ȩ�أ���a��b֮ǰ���󶥶ѣ�����������priority_queue��Ҫ�ߵ��Ƚ��߼�ʵ��С����
	}
};

// Prim�㷨ʵ����С������
vector<vector<int>> PrimAlgorithm()
{
	// ʹ�����ȶ��У�С���ѣ��洢������ı�
	priority_queue<vector<int>, vector<vector<int>>, Compare> heap;
	// ��ʼ���Ѽ�����С�������Ķ��㼯��
	vector<bool> set(n, false);
	// ��ʼ���Ѽ�����С�������Ķ������
	int nodeCnt = 1;
	// �������뼯��
	set[0] = true;
	// ���������г��߼������
	for(const auto& edge : graph[0]){
		heap.push(edge);
	}
	// �洢��С�������Ľ��
	vector<vector<int>> ans;
	// �����ʼ�㵽����У�Ȩֵ��Ϊ0����ʼ�㣩
	ans.push_back({0, 0});
	// ѭ��ֱ�����ж��㶼��������С������
	while(!heap.empty()){
		// ȡ��Ȩֵ��С�ı�
		int next = heap.top()[0];
		int cost = heap.top()[1];
		heap.pop();
		// ����ñߵ��յ�δ������С������
		if(!set[next]){
			// �����¶���
			nodeCnt++;
			set[next] = true;
			// �������߼�����
			ans.push_back({next, cost});
			// ���¼��붥������г��߼������
			for(const auto& e : graph[next]){
				heap.push(e);
			}
		}
	}
	return ans;
} 

// ������
int main()
{
	// ����ͼ
	build();
	// ��ʾͼ���ڽӱ�
	showGraph();
	// ����Prim�㷨����ȡ��С������
	vector<vector<int>> ans = PrimAlgorithm();
	cout << endl;
	cout << "��С��������" << endl;
	// ��ӡ��С�������ı�
	for(int i = 0; i < ans.size(); i++){
		// ��ʼ�㲻��ӡ���ӷ���Ȩֵ
		if(ans[i][1] == 0){
			cout << ans[i][0];
		}else{
			cout << " --(" << ans[i][1] << ")-->" << ans[i][0]; 
		}
	}
	return 0;
}	  
