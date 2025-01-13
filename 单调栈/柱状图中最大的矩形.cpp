// 柱状图中最大的矩形
// 给定 n 个非负整数，用来表示柱状图中各个柱子的高度
// 每个柱子彼此相邻，且宽度为 1 。求在该柱状图中，能够勾勒出来的矩形的最大面积
// 测试链接：https://leetcode.cn/problems/largest-rectangle-in-histogram

#include <iostream>
#include <vector>
using namespace std; 

// 相当于求一行中每个数左右两边离自己最近且比自己小的位置 
int largestRectangleArea(vector<int>& heights) 
{
    int n = heights.size();
    vector<int> stack(n);   // 大压小 
    int r = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
    	// 相同也压入，后面相同的数能弥补前面的错误 
    	//  ...1....3........3..2..
		//     ------              前面相同的数字出现错误 
		//     -----------------   后面相同的位置弥补了错误 
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
        ans = max(ans, (n - left - 1) * heights[cur]);
    }
    return ans;
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int ans = largestRectangleArea(arr);
	cout << ans << endl;
	return 0;
}
