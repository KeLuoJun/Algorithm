// ��Χ�Ƶ�����
// ����һ�� m x n �ľ��� board ���������ַ� 'X' �� 'O' ���ҵ����б� 'X' Χ�Ƶ�����
// ������Щ���������е� 'O' �� 'X' ��䡣
// �������� : https://leetcode.cn/problems/surrounded-regions/

#include <iostream>
using namespace std;
const int MAXN = 201;
char (*board)[MAXN] = new char[MAXN][MAXN];
int n,m;

void dfs(int i, int j)
{
	if(i < 0 || i == n || j < 0 || j == m || board[i][j] != '0')
		return;
	board[i][j] = 'F';
	dfs(i, j - 1);
	dfs(i, j + 1);
	dfs(i - 1, j);
	dfs(i + 1, j);
}


int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> board[i][j];
		}
	}
			
	for(int i = 0; i < n; i++){
		if(board[i][0] == '0'){
			dfs(i, 0);
		}
		if(board[i][m - 1] == '0'){
			dfs(i, m - 1);
		}
	}	
	for(int j = 0; j < m; j++){
		if(board[0][j] == '0'){
			dfs(0, j);
		}
		if(board[n - 1][j] == '0'){
			dfs(n - 1, j);
		}
	}	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(board[i][j] == '0')
				board[i][j] = 'X';
			else if(board[i][j] == 'F')
				board[i][j] = '0';
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
 } 
