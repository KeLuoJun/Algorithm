// ÿ���˴���ͬñ�ӵķ�����
// �ܹ��� n ���˺� 40 �ֲ�ͬ��ñ�ӣ�ñ�ӱ�Ŵ� 1 �� 40
// ����һ�������б���б� hats ������ hats[i] �ǵ� i ��������ϲ��ñ�ӵ��б�
// �����ÿ���˰���һ����ϲ����ñ�ӣ�ȷ��ÿ���˴���ñ�Ӹ����˶���һ���������ط�����
// ���ڴ𰸿��ܴܺ��뷵������10^9+7ȡ���Ľ��
// �������� : https://leetcode.cn/problems/number-of-ways-to-wear-different-hats-to-each-other

#include <iostream>
using namespace std;
const int MAXN = 41;
const int MOD = 1e9 + 7;
int n, maxx = 0;
int m[MAXN];
int arr[MAXN][MAXN];

// m : ñ����ɫ�����ֵ, 1 ~ m
// n : �˵�������0 ~ n-1
// i : ������ʲô��ɫ��ñ��
// s : n���ˣ�˭û����״̬����0��˭������״̬����1
// dp : ���仯�����ı�
// ���� : �ж����ַ���
int f(int *hats, int m, int n, int i, int s, int (*dp)[11])
{
	if(s == (1 << n) - 1)
		return 1;
	// ������û����
	if(i == m + 1)
		return 0;
	if(dp[i][s] != -1)
		return dp[i][s];
	// ������1 : i��ɫ��ñ�ӣ���������κ���
	int ans = f(hats, m, n, i + 1, s, dp);
	// ������2 : i��ɫ��ñ�ӣ���������ܵ�ÿһ����
	int cur = hats[i];
	// ��forѭ����0 ~ n-1ö��ÿ����
	for(int p = 0; p < n; p++){
		// (s & (1 << p)) == 0 �����֮ǰû�б������ 
		if((cur & (1 << p)) != 0 && (s & (1 << p)) == 0){
			ans = (ans + f(hats, m, n, i + 1, s | (1 << p), dp)) % MOD;
		}
	}
	dp[i][s] = ans;
	return ans;
}


int compute()
{
	int hats[maxx + 1];
	// 1 ~ m ñ�ӣ���������Щ�ˣ�״̬��Ϣ -> int
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m[i]; j++){
			hats[arr[i][j]] |= 1 << i;
		}
	}
	int (*dp)[11] = new int[maxx + 1][11];
	for(int i = 0; i <= maxx; i++){
		for(int j = 0; j <= 11; j++)
			dp[i][j] = -1;
	}
	return f(hats, maxx, n, 1, 0, dp);
} 


int main()
{
	cout << "�������ж��ٸ��ˣ�" ;
	cin >> n;
	for(int i = 0; i < n; i++){
		cout << "�������" << i+1 << "����ϲ��ñ�ӵ�������";
		cin >> m[i];
		cout << "�������" << i+1 << "����ϲ��ñ�ӵı�ţ�"; 
		for(int j = 0; j < m[i]; j++){
			cin >> arr[i][j];
			maxx = max(maxx, arr[i][j]);
		}
	}
	cout << compute() << endl;
	return 0;
 } 
