// 岛屿数量
// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成
// 此外，你可以假设该网格的四条边均被水包围
// 测试链接 : https://leetcode.cn/problems/number-of-islands/

#include <iostream>
using namespace std;
const int MAXN = 10001;
int *father = new int[MAXN];
int sets;
int n,m;


// 二维坐标转化为一维坐标 
int index(int a, int b)
{
	return a * m + b;
}


// 给定每个1不同的下标值 
void build(int board[][MAXN])
{
	sets = 0;
	int pos;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(board[i][j] == 1){
				pos = index(i, j);
				father[pos] = pos;
				sets++;
			}
		}
	}
}

int find(int i)
{
	if(i != father[i]){
		father[i] = find(father[i]);
	}
	return father[i];
}


void unions(int a, int b, int c, int d)
{
	int fx = find(index(a, b));
	int fy = find(index(c, d));
	if(fx != fy){
		father[fx] = fy;
		sets--;
	}
}


int main()
{
	cin >> n >> m;
	int (*board)[MAXN] = new int[n][MAXN];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> board[i][j];
	build(board);
	 for(int i = 0; i < n; i++){
	 	for(int j = 0; j < m; j++){
	 		if(board[i][j] == 1){
	 			if(j > 0 && board[i][j - 1] == 1){
	 				unions(i, j, i, j - 1);
				 }
				if(i > 0 && board[i - 1][j] == 1){
					unions(i, j, i - 1, j);
				}
			 }
		}
	 }
	cout << sets << endl;
	return 0;
} 
