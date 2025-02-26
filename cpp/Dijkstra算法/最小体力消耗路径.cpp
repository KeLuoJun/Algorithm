// ��С��������·��
// ��׼���μ�һ��Զ��������һ����ά rows x columns �ĵ�ͼ heights
// ���� heights[row][col] ��ʾ���� (row, col) �ĸ߶�
// һ��ʼ���������Ͻǵĸ��� (0, 0) ������ϣ��ȥ�����½ǵĸ��� (rows-1, columns-1) 
// ��ע���±�� 0 ��ʼ��ţ�����ÿ�ο����� �ϣ��£����� �ĸ�����֮һ�ƶ�
// ����Ҫ�ҵ��ķ� ���� ��С��һ��·��
// һ��·���ķѵ�����ֵ��·���ϣ����ڸ���֮��߶Ȳ����ֵ�����ֵ
// ���㷵�ش����Ͻ��ߵ����½ǵ���С ��������ֵ
// �������� ��https://leetcode.cn/problems/path-with-minimum-effort/

#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
const int N = 101;
// 0:�ϣ�1:�ң�2:�£�3:��
int moves[] = {-1, 0, 1, 0, -1};

struct Compare{
	// ����Դ�㵽��ǰ���ӵĴ��������� 
	bool operator()(const vector<int>&a, const vector<int>&b){
		return a[2] > b[2];
	}
};

int minimumEffortPath(vector<vector<int>>& heights)
{
	// (0,0)Դ��
	// -> (x,y)
	int n = heights.size();
	int m = heights[0].size();
	// ��άvector�����ʼ�� 
	vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
	distance[0][0] = 0;
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	// 0 : ���ӵ���
	// 1 : ���ӵ���
	// 2 : Դ�㵽��ǰ���ӵĴ���
	priority_queue<vector<int>, vector<vector<int>>, Compare> heap;
	heap.push({0, 0, 0});
	while(!heap.empty()){
		int x = heap.top()[0];
		int y = heap.top()[1];
		int c = heap.top()[2];
		heap.pop();
		if(visited[x][y]){
			continue;
		}
		visited[x][y] = true;
		if(x == n - 1 && y == m - 1){
			// ������֦
			// �����յ�ֱ�ӷ���
			// ���õȶ�����
			return c;
		}
		
		for(int i = 0; i < 4; i++){
			int nx = x + moves[i];
			int ny = y + moves[i + 1];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]){
				// ��ģ������� 
				int nc = max(c, abs(heights[x][y] - heights[nx][ny]));
				if(nc < distance[nx][ny]){
					distance[nx][ny] = nc;
					heap.push({nx, ny, nc});
				}
			}
		}
	}
	return -1;
}



int main()
{
	int n, m;
	vector<vector<int>> heights;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		vector<int>tmp;
		int x;
		for(int j = 0; j < m; j++){
			cin >> x;
			tmp.push_back(x);
		}
		heights.push_back(tmp);
	}
	int ans = minimumEffortPath(heights);
	cout << ans << endl;
	return 0;
} 
