// ˮλ������Ӿ������Ӿ
// ��һ�� n x n ���������� grid ��
// ÿһ�������ֵ grid[i][j] ��ʾλ�� (i, j) ��ƽ̨�߶�
// ����ʼ����ʱ����ʱ��Ϊ t ʱ��ˮ���е�ˮλΪ t
// ����Դ�һ��ƽ̨�����������ڵ�����һ��ƽ̨������ǰ���Ǵ�ʱˮλ����ͬʱ��û������ƽ̨
// �ٶ������˲���ƶ����޾��룬Ҳ����Ĭ���ڷ����ڲ��ζ��ǲ���ʱ��
// ��Ȼ��������Ӿ��ʱ�������������귽�����档
// ������귽�������ƽ̨ (0��0) ����
// ���� �㵽�����귽�������ƽ̨ (n-1, n-1) ���������ʱ��
// �������� : https://leetcode.cn/problems/swim-in-rising-water/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 51;
int moves[] = {-1, 0, 1, 0, -1};


struct Compare{
	bool operator()(const vector<int>&a, const vector<int>&b){
		return a[2] > b[2];
	}
};

int swimInWater(vector<vector<int>>& grid)
{
	int n = grid.size();
	int m = grid[0].size();
	vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
	distance[0][0] = grid[0][0];
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	priority_queue<vector<int>, vector<vector<int>>, Compare> heap;
	heap.push({0, 0, grid[0][0]});
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
			return c;
		}
		for(int i = 0; i < 4; i++){
			int nx = x + moves[i];
			int ny = y + moves[i + 1];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]){
				int nc = max(c, grid[nx][ny]);
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
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		int x;
		vector<int>tmp;
		for(int j = 0; j < m; j++){
			cin >> x;
			tmp.push_back(x);
		}
		grid.push_back(tmp);
	}
	int ans = swimInWater(grid);
	cout << ans << endl;
	return 0;
}
