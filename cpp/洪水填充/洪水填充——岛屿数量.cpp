// 岛屿数量
// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成
// 此外，你可以假设该网格的四条边均被水包围
// 测试链接 : https://leetcode.cn/problems/number-of-islands/


#include <iostream>
using namespace std;
const int MAXN = 301;
int (*board)[MAXN] = new int[MAXN][MAXN];
int n,m;

void dfs(int i, int j)
{
	if(i < 0 || i == n || j < 0 || j == m || board[i][j] != 1)
		return;
	board[i][j] = 0;
	dfs(i, j - 1);
	dfs(i, j + 1);
	dfs(i - 1, j);
	dfs(i + 1, j);
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cin >> board[i][j];
	}
	int islands = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(board[i][j] == 1){
				islands++;
				dfs(i, j);
			}
		}
	}
	cout << islands << endl;
	return 0;
} 
