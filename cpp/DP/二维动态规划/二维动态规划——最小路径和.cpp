// ��С·����
// ����һ�������Ǹ������� m x n ���� grid
// ���ҳ�һ�������Ͻǵ����½ǵ�·����ʹ��·���ϵ������ܺ�Ϊ��С��
// ˵����ÿ��ֻ�����»��������ƶ�һ����
// �������� : https://leetcode.cn/problems/minimum-path-sum/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 201;
int m,n;
int grid[MAXN][MAXN];

// ��(0,0)��(i,j)��С·����
// һ��ÿ��ֻ�����һ�������
int f1(int i, int j)
{
	if(i == 0 && j == 0)
		return grid[i][j];
	int up = INT_MAX;
	int left = INT_MAX;
	if(i - 1 >= 0)
		up = f1(i - 1, j);
	if(j - 1 >= 0)
		left  = f1(i, j - 1);
	return grid[i][j] + min(up, left);
}
//�����ݹ� 
int minPathSum1()
{
	return f1(m-1, n-1);
}


//���仰���� 
int f2(int i, int j, int dp[][MAXN])
{
	if(dp[i][j] != -1)
		return dp[i][j];
	int ans;
	if(i == 0 && j == 0)
		ans = grid[0][0];
	else
	{
		int up = INT_MAX;
		int left = INT_MAX;
		if(i - 1 >= 0)
			up = f2(i - 1, j, dp);
		if(j - 1 >= 0)
			left = f2(i, j - 1, dp);
		ans = grid[i][j] + min(up, left);
	 } 
	dp[i][j] = ans;
	return ans;
}
int minPathSum2()
{
	int (*dp)[MAXN] = new int[m][MAXN];
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			dp[i][j] = -1;
	return f2(m-1, n-1, dp);
}

// �ϸ�λ�������Ķ�̬�滮
int minPathSum3()
{
	int (*dp)[MAXN] = new int[m][MAXN];
	dp[0][0] = grid[0][0];
	for(int i = 1; i < m; i++)
		dp[i][0] = dp[i - 1][0] + grid[i][0];
	for(int j = 1; j < n; j++)
		dp[0][j] = dp[0][j - 1] + grid[0][j];
	for(int i = 1; i < m; i++)
	{
		for(int j = 1; j < n; j++)
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
	}
	return dp[m - 1][n - 1];
}


// �ϸ�λ�������Ķ�̬�滮 + �ռ�ѹ������
int minPathSum4()
{
	int *dp = new int[n];
	dp[0] = grid[0][0];
	// ����dp����������еı�ĵ�0�е�����
	for(int j = 1; j < n; j++)
		dp[j] = dp[j - 1] + grid[0][j];
	for(int i = 1; i < m; i++)
	{
		// i = 1��dp���������ж�ά��ĵ�1�е�����
		// i = 2��dp���������ж�ά��ĵ�2�е�����
		// i = 3��dp���������ж�ά��ĵ�3�е�����
		// ...
		// i = n-1��dp���������ж�ά��ĵ�n-1�е�����
		dp[0] += grid[i][0];
		for(int j = 1; j < n; j++)
			dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
	}
	return dp[n - 1];
}


int main()
{
	cin >> m >> n;
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			cin >> grid[i][j];
	
	int ans1 = minPathSum1();
	int ans2 = minPathSum2();
	int ans3 = minPathSum3();
	int ans4 = minPathSum4();
	
	cout << ans1 << endl;
	cout << ans2 << endl;
	cout << ans3 << endl;
	cout << ans4 << endl;
	return 0;
} 
