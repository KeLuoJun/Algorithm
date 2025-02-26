// 边框为1的最大正方形
// 给你一个由若干 0 和 1 组成的二维网格 grid
// 请你找出边界全部由 1 组成的最大 正方形 子网格
// 并返回该子网格中的元素数量。如果不存在，则返回 0。
// 测试链接 : https://leetcode.cn/problems/largest-1-bordered-square/

#include <iostream>
using namespace std;
#define MAXN 10000

int g[MAXN][MAXN];
int n,m;

int get(int i, int j) {
	return (i < 0 || j < 0) ? 0 : g[i][j];
}


void build() {
	//从(0,0) 到 (i,j) 的前缀和 
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		//加左上角加右上角减掉重叠的部分 
			g[i][j] += get(i,j-1) + get(i-1,j) - get(i-1,j-1);
}

// (a,b) 到 (c,d) 的前缀和
int sum(int a,int b,int c,int d) {
	// 左上角 跑到 右下角的后面 
	return a > c ? 0 : g[c][d] - get(c,b-1) - get(a-1,d) + get(a-1,b-1);
}


int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> g[i][j];
	build();
	if(g[n-1][m-1] == 0) return 0;

	int ans = 1;
	for(int a = 0; a < n; a++) {
		for(int b = 0; b < m; b++) {
			//a b 为左上角的点
			//k 为边长 ans为目前的最大边长 
			for(int c = a + ans,d = b + ans,k = ans + 1; c < n && d < m; c++,d++,k++)
					if(sum(a,b,c,d) - sum(a+1,b+1,c-1,d-1) == (k - 1) * 4)
						ans = k;
			}
	}
	cout << ans * ans << endl;
	return 0;
}
