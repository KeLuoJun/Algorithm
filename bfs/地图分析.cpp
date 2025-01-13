// ��ͼ����
// ������������һ�ݴ�СΪ n x n �� ���� grid
// �����ÿ�� ��Ԫ�� ���� 0 �� 1 ��Ǻ������� 0 ������1 ����½�ء�
// �����ҳ�һ������Ԫ���������Ԫ�����������½�ص�Ԫ��ľ���������
// �����ظþ��롣���������ֻ��½�ػ��ߺ����뷵�� -1��
// ��������˵�ľ����ǡ������پ��롹�� Manhattan Distance����
// (x0, y0) �� (x1, y1) ��������Ԫ��֮��ľ����� |x0 - x1| + |y0 - y1| ��
// �������� : https://leetcode.cn/problems/as-far-from-land-as-possible/

#include <iostream>
using namespace std;
const int MAXN = 1001;
int grid[MAXN][MAXN];
int vis[MAXN][MAXN] = {0};
int n,m;
int Queue[MAXN * MAXN][2];
int l,r;
int moved[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int maxDistance()
{
	l = r = 0;
	int seas = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j] == 1){
				vis[i][j] = 1;
				Queue[r][0] = i;
				Queue[r++][1] = j;
			}else{
				seas++;
			}
		}
	}
	if(seas == 0 || seas == n * m){
		return -1;
	}
	int level = 0;
	while(l < r)
	{
		level++;
		int size = r - l;
		for(int k = 0, x, y, nx, ny; k < size; k++){
			x = Queue[l][0];
			y = Queue[l++][1];
			for(int i = 0; i < 4; i++){
				nx = x + moved[i][0];
				ny = y + moved[i][1];
				if(nx >= 0 && nx < n && ny >=  0 && ny < m && !vis[nx][ny]){
					vis[nx][ny] = 1;
					Queue[r][0] = nx;
					Queue[r++][1] = ny;
				}
			}
		}
	}
	// ��Ŀ�涨��һ��Ϊ0�����˽ⷨ�Ǵ�1��ʼ�� 
	return level - 1;
}



int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> grid[i][j];
		}
	}
	cout << maxDistance() << endl;
	return 0;
	
}
