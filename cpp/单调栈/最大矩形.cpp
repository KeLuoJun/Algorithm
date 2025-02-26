// ������
// ����һ�������� 0 �� 1 ����СΪ rows * cols �Ķ�ά�����ƾ���
// �ҳ�ֻ���� 1 �������Σ������������
// �������ӣ�https://leetcode.cn/problems/maximal-rectangle/


#include <iostream>
#include <vector>
using namespace std;

// ��������״ͼ������������
// �൱����һ����ÿ���������������Լ�����ұ��Լ�С��λ�� 
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
        	// �������£�����Ŀ�ֽ�Ϊ��ÿһ�������������״ͼ����������
			// ����ÿһ�еĸ߶�Ϊ��һ�еĸ߶�+1 
			// ע�⣺��������ĳ�г���0ʱ������Ϊ���еĸ߶�Ϊ0
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
