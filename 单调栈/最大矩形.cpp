// 最大矩形
// 给定一个仅包含 0 和 1 、大小为 rows * cols 的二维二进制矩阵
// 找出只包含 1 的最大矩形，并返回其面积
// 测试链接：https://leetcode.cn/problems/maximal-rectangle/


#include <iostream>
#include <vector>
using namespace std;

// 经典求柱状图中最大矩阵问题
// 相当于求一行中每个数左右两边离自己最近且比自己小的位置 
int largestRectangleArea(vector<int>&heights, int m)
{
    vector<int> stack(m);
    int r = 0;
    int ans = 0;
    for(int i = 0; i < m; i++){
        while(r > 0 && heights[stack[r - 1]] >= heights[i]){
            int cur = stack[--r];
            int left = r == 0 ? -1 : stack[r - 1];
            ans = max(ans, (i - left - 1) * heights[cur]);
        }
        stack[r++] = i;
    }
    while(r > 0){
        int cur = stack[--r];
        int left = r == 0 ? -1 : stack[r - 1];
        ans = max(ans, (m - left - 1) * heights[cur]);
    }
    return ans;
}

int maximalRectangle(vector<vector<char>>& matrix) 
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int>heights(m);
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
        	// 从上往下，将题目分解为求每一行往上区域的柱状图最大矩阵问题
			// 下面每一行的高度为上一行的高度+1 
			// 注意：当改行中某列出现0时，则视为该列的高度为0
            heights[j] = matrix[i][j] == '0' ? 0 : (matrix[i][j] - '0') + heights[j];
        }
        ans = max(ans, largestRectangleArea(heights, m));
    }
    return ans;
}

int main()
{
	int n,m;
	cin >> n >> m;
	vector<vector<char>> matrix(n, vector<char>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> matrix[i][j];
		}
	}
	int ans = maximalRectangle(matrix);
	cout << ans << endl;
	return 0;
}
