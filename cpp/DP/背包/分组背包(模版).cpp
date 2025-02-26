// ���鱳��(ģ��)
// ����һ������m��ʾ��������������n������ɹ���ѡ
// ÿ���������Լ������(��������)����ֵ(�������)�����(����)
// ͬһ�������Ʒֻ����ѡ1����������ѡ��Ʒ������ܺͲ��ܳ�����������
// ��ô��ѡ�����ܴﵽ��ֵ��󣬷������ļ�ֵ
// �������� : https://www.luogu.com.cn/problem/P1757

#include <iostream>
using namespace std;
const int MAXN = 1001;
int n,m;   //nΪ��Ʒ������ mΪ������ 
int (*arr)[3] = new int[MAXN][3];


int compute1()
{
	int teams = 1;
	// ���� 
	for(int i = 2; i <= n; i++){
		if(arr[i - 1][2] != arr[i][2])
			teams++;
	}
	// ��ı��1~teams
	// dp[i][j] : 1~i����ķ�Χ��ÿ�������Ʒ��һ��������������j������£��������
	int (*dp)[MAXN] = new int[MAXN][MAXN];
	// dp[0][....] = 0
	for(int j = 0; j <= m; j++) dp[0][j] = 0;
	// start ... end-1 -> i��
	int start = 1, end = 2; 
	for(int i = 1; start <= n; i++)
	{
		// endΪ��ǰ���ĩβ 
		while(end <= n && arr[end][2] == arr[start][2])
			end++;
		for(int j = 0; j <= m; j++){
			// arr[start...end-1]�ǵ�ǰ�飬���һ��
			// ���е�ÿһ����Ʒö��һ��
			dp[i][j] = dp[i-1][j];
			for(int k = start; k < end; k++){
				// k�����ڵ�һ����Ʒ���
				if(j - arr[k][0] >= 0)
					dp[i][j] = max(dp[i][j], dp[i-1][j - arr[k][0]] + arr[k][1]);
			}
		}
		// startȥ����һ��ĵ�һ����Ʒ
		// ��������ʣ�µ���
		start = end++;
	}
	return dp[teams][m];
}

//�ռ�ѹ�� 
int compute2()
{
	int *dp = new int[MAXN];
	for(int i = 0; i <= m; i++)
		dp[i] = 0;
	for(int start = 1, end = 2; start <= n; ){
		while(end <= n && arr[end][2] == arr[start][2])
			end++;
		//����������� 
		for(int j = m; j >= 0; j--){
			for(int k = start; k < end; k++){
				if(j - arr[k][0] >= 0)
					dp[j] = max(dp[j], dp[j - arr[k][0]] + arr[k][1]);
			}
		}
		start = end++;
	}
	return dp[m];
} 



int main()
{
	cin >> m >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < 3; j++)
			cin >> arr[i][j];
	//arr[i][0]��ʾ����   arr[i][1]��ʾ��ֵ  arr[i][2]��ʾ��� 
	//������Ĵ�С�������� 
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n-i; j++)
		{
			if(arr[j][2] >= arr[j + 1][2])
			{
				for(int k = 0; k < 3; k++)
				{
					int t = arr[j][k];
					arr[j][k] = arr[j + 1][k];
					arr[j + 1][k] = t;
				}
			}
		}
	}
	
	int ans1 = compute1();
	int ans2 = compute2();
	
	cout << ans1 << endl;
	cout << ans2 << endl;
	return 0; 
 } 
