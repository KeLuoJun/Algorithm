// 获取所有钥匙的最短路径
// 给定一个二维网格?grid?，其中：
// '.' 代表一个空房间、'#' 代表一堵、'@'?是起点
// 小写字母代表钥匙、大写字母代表锁
// 从起点开始出发，一次移动是指向四个基本方向之一行走一个单位空间
// 不能在网格外面行走，也无法穿过一堵墙
// 如果途经一个钥匙，我们就把它捡起来。除非我们手里有对应的钥匙，否则无法通过锁。
// 假设 k?为 钥匙/锁 的个数，且满足?1 <= k?<= 6，
// 字母表中的前 k?个字母在网格中都有自己对应的一个小写和一个大写字母
// 换言之，每个锁有唯一对应的钥匙，每个钥匙也有唯一对应的锁
// 另外，代表钥匙和锁的字母互为大小写并按字母顺序排列
// 返回获取所有钥匙所需要的移动的最少次数。如果无法获取所有钥匙，返回?-1?。
// 测试链接：https://leetcode.cn/problems/shortest-path-to-get-all-keys

#include <iostream>
#include <vector>
#include <string>
using namespace std;
static const int N = 31;
int moves[] = {-1, 0, 1, 0, -1};
bool visited[N][N][1 << 6];

// 0 : 行
// 1 : 列
// 2 : 收集钥匙的状态
int bfsqueue[N * N * (1 << 6)][3];
int l,r,n,m,key;

void build(vector<string>& grid)
{
	l = r = key = 0;
	n = grid.size();
	m = grid[0].size();
	// 找起始位置
	// 先检查有多少种钥匙 
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
	// 初始化visited 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int s = 0; s <= key; s++){
				visited[i][j][s] = false;
			}
		}
	}
}


// 宽度优先遍历
// 将以点为状态扩展为以（点，收集钥匙的状态） 作为状态 
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
					// 越界或者障碍
					continue;
				}
				if(grid[nx][ny] >= 'A' && grid[nx][ny] <= 'Z' && (ns & (1 << (grid[nx][ny] - 'A'))) == 0){
					// 是锁，又没有对应的钥匙
					continue;
				}
				if(grid[nx][ny] >= 'a' && grid[nx][ny] <= 'z'){
					// 是某一把钥匙
					ns |= 1 << (grid[nx][ny] - 'a');
				}
				if(ns == key){
					// 常见剪枝
					// 发现终点直接返回
					// 不用等都结束
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
