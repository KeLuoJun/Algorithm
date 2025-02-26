// 最大人工岛
// 给你一个大小为 n * n 二进制矩阵 grid 。最多 只能将一格 0 变成 1 。
// 返回执行此操作后，grid 中最大的岛屿面积是多少？
// 岛屿 由一组上、下、左、右四个方向相连的 1 形成
// 测试链接 : https://leetcode.cn/problems/making-a-large-island/


#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 501;
int (*board)[MAXN] = new int[MAXN][MAXN];
int n;

// 将不同的岛屿赋予不同的id 
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
	
	// 遍历得到每个岛屿的大小 
	int size[id + 1] = {0};
	size[0] = 0;
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(board[i][j] > 1)
				ans = max(ans, ++size[board[i][j]]);
		}
	}
	// 检验岛屿是否已经被访问过 
	bool visits[id + 1] = {false};
	int up,down,left,right,merge = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(board[i][j] == 0){
				up = i > 0 ? board[i - 1][j] : 0;
				down = i < n - 1 ? board[i + 1][j] : 0;
				left = j > 0 ? board[i][j - 1] : 0;
				right = j < n - 1 ? board[i][j + 1] : 0;
				merge = 1;  // 包括0本身 
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
