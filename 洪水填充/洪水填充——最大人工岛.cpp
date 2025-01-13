// ����˹���
// ����һ����СΪ n * n �����ƾ��� grid ����� ֻ�ܽ�һ�� 0 ��� 1 ��
// ����ִ�д˲�����grid �����ĵ�������Ƕ��٣�
// ���� ��һ���ϡ��¡������ĸ����������� 1 �γ�
// �������� : https://leetcode.cn/problems/making-a-large-island/


#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 501;
int (*board)[MAXN] = new int[MAXN][MAXN];
int n;

// ����ͬ�ĵ��츳�費ͬ��id 
void dfs(int i, int j, int id)
{
	if(i < 0 || i == n || j < 0 || j == n || board[i][j] != 1)
		return;
	board[i][j] = id;
	dfs(i, j - 1, id);
	dfs(i, j + 1, id);
	dfs(i - 1, j, id);
	dfs(i + 1, j, id);
}


int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> board[i][j];
	
	int id = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(board[i][j] == 1){
				dfs(i, j, ++id);
			}
		}
	}
	
	// �����õ�ÿ������Ĵ�С 
	int size[id + 1] = {0};
	size[0] = 0;
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(board[i][j] > 1)
				ans = max(ans, ++size[board[i][j]]);
		}
	}
	// ���鵺���Ƿ��Ѿ������ʹ� 
	bool visits[id + 1] = {false};
	int up,down,left,right,merge = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(board[i][j] == 0){
				up = i > 0 ? board[i - 1][j] : 0;
				down = i < n - 1 ? board[i + 1][j] : 0;
				left = j > 0 ? board[i][j - 1] : 0;
				right = j < n - 1 ? board[i][j + 1] : 0;
				merge = 1;  // ����0���� 
				if(!visits[up]){
					merge += size[up];
					visits[up] = true;
				}
				if(!visits[down]){
					merge += size[down];
					visits[down] = true;
				}
				if(!visits[left]){
					merge += size[left];
					visits[left] = true;
				}
				if(!visits[right]){
					merge += size[right];
					visits[right] = true;
				}
				ans = max(ans, merge);
				visits[up] = false;
				visits[down] = false;
				visits[left] = false;
				visits[right] = false;
			}
		}
	}
	cout << ans << endl;
	return 0;
 } 
