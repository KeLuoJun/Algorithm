// 쳲�������
// 쳲������� ��ͨ���� F(n) ��ʾ���γɵ����г�Ϊ 쳲���������
// �������� 0 �� 1 ��ʼ�������ÿһ�����ֶ���ǰ���������ֵĺ͡�
// Ҳ���ǣ�F(0) = 0��F(1) = 1
// F(n) = F(n - 1) + F(n - 2)������ n > 1
// ���� n ������� F(n)
// �������� : https://leetcode.cn/problems/fibonacci-number/
// ע�⣺���Ž����Ծ�������ݣ�ʱ�临�Ӷȿ�������O(log n)

#include <iostream>
using namespace std;
const int MAXN = 10000;
int arr[MAXN];
int n;


//�����ݹ� 
int fib1(int k)
{
	if(k == 0) return 0;
	if(k == 1) return 1;
	return fib1(k - 1) + fib1(k - 2);
}


//���仯�ݹ� 
int f2(int *dp, int k)
{
	if(k == 0) return 0;
	if(k == 1) return 1;
	if(dp[k] != -1) return dp[k];
	int ans = f2(dp, k - 1) + f2(dp, k - 2);
	dp[k] = ans;
	return ans;
}

int fib2(int k)
{
	int *dp = new int[k+1];
	for(int i = 0; i <= k; i++) dp[i] = -1;
	int ans = f2(dp,k);
	delete[] dp;
	return ans;
}



//��̬�滮������ͣ� 
long long fib3(int k)
{
	if(k == 0) return 0;
	if(k == 1) return 1;
	long long *dp = new long long[k + 1];
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 2; i <= k; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	return dp[k];
}

//��̬�仯�������ͣ� 
long long fib4(int k)
{
	if(k == 0) return 0;
	if(k == 1) return 1;
	long long lastlast = 0,last = 1;
	for(int i = 2; i <= k; i++)
	{
		long long cur = lastlast + last;
		lastlast = last;
		last = cur;
	}
	return last;
}


int main()
{
	cin >> n;
//	int ans1 = fib1(n);
//	int ans2 = fib2(n);
	long long ans3 = fib3(n);
	long long ans4 = fib4(n);
	
//	cout << ans1 << endl;
//	cout << ans2 << endl;
	cout << ans3 << endl;
	cout << ans4 << endl;
	return 0;
}
