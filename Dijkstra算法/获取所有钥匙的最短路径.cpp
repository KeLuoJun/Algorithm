// ��ȡ����Կ�׵����·��
// ����һ����ά����?grid?�����У�
// '.' ����һ���շ��䡢'#' ����һ�¡�'@'?�����
// Сд��ĸ����Կ�ס���д��ĸ������
// ����㿪ʼ������һ���ƶ���ָ���ĸ���������֮һ����һ����λ�ռ�
// �����������������ߣ�Ҳ�޷�����һ��ǽ
// ���;��һ��Կ�ף����ǾͰ������������������������ж�Ӧ��Կ�ף������޷�ͨ������
// ���� k?Ϊ Կ��/�� �ĸ�����������?1 <= k?<= 6��
// ��ĸ���е�ǰ k?����ĸ�������ж����Լ���Ӧ��һ��Сд��һ����д��ĸ
// ����֮��ÿ������Ψһ��Ӧ��Կ�ף�ÿ��Կ��Ҳ��Ψһ��Ӧ����
// ���⣬����Կ�׺�������ĸ��Ϊ��Сд������ĸ˳������
// ���ػ�ȡ����Կ������Ҫ���ƶ������ٴ���������޷���ȡ����Կ�ף�����?-1?��
// �������ӣ�https://leetcode.cn/problems/shortest-path-to-get-all-keys

#include <iostream>
#include <vector>
#include <string>
using namespace std;
static const int N = 31;
int moves[] = {-1, 0, 1, 0, -1};
bool visited[N][N][1 << 6];

// 0 : ��
// 1 : ��
// 2 : �ռ�Կ�׵�״̬
int bfsqueue[N * N * (1 << 6)][3];
int l,r,n,m,key;

void build(vector<string>& grid)
{
	l = r = key = 0;
	n = grid.size();
	m = grid[0].size();
	// ����ʼλ��
	// �ȼ���ж�����Կ�� 
	for(int i = 0 ; i < n; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j] == '@'){
				bfsqueue[r][0] = i;
				bfsqueue[r][1] = j;
				bfsqueue[r++][2] = 0;
			}
			if(grid[i][j] >= 'a' && grid[i][j] <= 'z'){
				key |= 1 << (grid[i][j] - 'a');
			}
		}
	}
	// ��ʼ��visited 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int s = 0; s <= key; s++){
				visited[i][j][s] = false;
			}
		}
	}
}


// ������ȱ���
// ���Ե�Ϊ״̬��չΪ�ԣ��㣬�ռ�Կ�׵�״̬�� ��Ϊ״̬ 
int shortestPathAllKeys(vector<string>& grid)
{
	build(grid);
	int level = 1;
	while(l < r){
		for(int k = 0, size = r - l; k < size; k++){
			int x = bfsqueue[l][0];
			int y = bfsqueue[l][1];
			int s = bfsqueue[l++][2];
			for(int i = 0; i < 4; i++){
				int nx = x + moves[i];
				int ny = y + moves[i + 1];
				int ns = s;
				if(nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == '#'){
					// Խ������ϰ�
					continue;
				}
				if(grid[nx][ny] >= 'A' && grid[nx][ny] <= 'Z' && (ns & (1 << (grid[nx][ny] - 'A'))) == 0){
					// ��������û�ж�Ӧ��Կ��
					continue;
				}
				if(grid[nx][ny] >= 'a' && grid[nx][ny] <= 'z'){
					// ��ĳһ��Կ��
					ns |= 1 << (grid[nx][ny] - 'a');
				}
				if(ns == key){
					// ������֦
					// �����յ�ֱ�ӷ���
					// ���õȶ�����
					return level;
				}
				if(!visited[nx][ny][ns]){
					visited[nx][ny][ns] = true;
					bfsqueue[r][0] = nx;
					bfsqueue[r][1] = ny;
					bfsqueue[r++][2] = ns;
				}
			}
		}
		level++;
	}
	return -1;
}

int main()
{
	int n;
	cin >> n;
	vector<string> grid;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		grid.push_back(s);
	}
	int ans = shortestPathAllKeys(grid);
	cout << ans << endl;
	return 0;
}
