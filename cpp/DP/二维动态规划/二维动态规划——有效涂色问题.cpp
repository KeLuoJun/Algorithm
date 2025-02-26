// ��ЧͿɫ����
// ����n��m��������
// һ����n�����ӣ�ÿ�����ӿ���Ϳ��һ����ɫ����ɫ��m����ѡ
// ��Ϳ��n�����ӣ�����m����ɫ��ʹ���ˣ���һ����Ч����
// ��һ���ж�������Ч��Ϳɫ����
// 1 <= n, m <= 5000
// ����Ƚϴ��� % 1000000007 ֮�󷵻�
// ��������֤

#include <iostream> 
using namespace std;
const int MAXN = 500;
int MOD = 1000000007;

int way1(int n, int m)
{
	int dp[MAXN][MAXN] = {0};
	// dp[i][j]:
	// һ����m����ɫ
	// ǰi������Ϳ��j����ɫ�ķ�����
	for(int i = 1; i <= n; i++)
		dp[i][1] = m;
	for(int i = 2; i <= n; i++)
	{
		for(int j = 2; j <= m; j++)
		{
			//ǰi-1�������Ѿ�Ϳ��j����ɫ�����i��������Ϳj����ɫ 
			dp[i][j] = (int)((long)(dp[i - 1][j] * j) % MOD);
			//ǰi-1������Ϳ��j-1����ɫ�����i��������Ϳʣ�µ���ɫ 
			// m - (j - 1) 
			dp[i][j] = (int)((long)(dp[i - 1][j - 1] * (m - j + 1) + dp[i][j]) % MOD);
		}
	}
	return dp[n][m];
}

int f(int *path, bool *set, int i, int n, int m)
{
	if(i == n){
		for(int j = 0; j <= m; j++){
			set[j] = false;
		}
		int colors = 0;
		for(int j = 0; j < n; j++){
			if(!set[path[j]]){
				set[path[j]] = true;
				colors++;
			}
		}
		// ����n������Ϳɫ������Ӧ����1-m�����ֹ� 
		return colors == m ? 1 : 0;
	}else{
		int ans = 0;
		for(int j = 1; j <= m; j++){
			path[i] = j;
			ans += f(path, set, i + 1, n, m);
		}
		//return ans;
	}
}
// �����ⷨ 
int way2(int n, int m)
{
	int path[n];
	bool set[m + 1] = {false};
	return f(path, set, 0, n, m);
}

int main()
{
	int n,m;
	cin >> n >> m;
	//cout << way1(n, m) << endl;
	cout << way2(n, m) << endl;
	return 0;
}
