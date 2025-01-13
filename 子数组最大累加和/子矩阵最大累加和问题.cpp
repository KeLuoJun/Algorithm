// 子矩阵最大累加和问题
// 给定一个二维数组grid，找到其中子矩阵的最大累加和
// 返回拥有最大累加和的子矩阵左上角和右下角坐标
// 如果有多个子矩阵都有最大累加和，返回哪一个都可以
// 测试链接 : https://leetcode.cn/problems/max-submatrix-lcci/

#include <iostream>
using namespace std;
const int MAXN = 201;
int (*nums)[MAXN] = new int[MAXN][MAXN];
int n,m;
int a = 0,b = 0,c = 0,d = 0;

void fill(int *&dp, int m)
{
	for(int i = 0; i < m; i++)	
		dp[i] = 0;
}

// 如果行和列的规模都是n，时间复杂度O(n^3)，最优解了
void getMaxMatrix()
{
	int *dp = new int[m];
	int maxsum = INT_MIN;
	for(int up = 0; up < n; up++){
		fill(dp, m);   // 刷新dp的值 
		// 遍历 0-0 0-1 0-2 .... 0-n-1
		// 1-1 1-2 .... 1-n-1
		// ........
		// n-n 
		for(int down = up; down < n; down++){
			// 如下代码就是题目1的附加问题 :
			// 子数组中找到拥有最大累加和的子数组
			for(int l = 0, r = 0, pre = INT_MIN; r < m; r++){
				dp[r] += nums[down][r];
				if(pre >= 0)
					pre += dp[r];
				else{
					pre = dp[r];
					l = r;
				}
				if(pre > maxsum){
					maxsum = pre;
					a = up;
					b = l;
					c = down;
					d = r;
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cin >> nums[i][j];
	}
	getMaxMatrix();
	cout << a << " " << b << " " << c << " " << d << endl;
	return 0;
} 
