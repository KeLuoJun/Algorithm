// �������ۼӺͱ��뱻7����������ۼӺ�
// ����һ���Ǹ�����nums��
// ��������ѡ��������������У����������е��ۼӺͱ��뱻7����
// ��������ۼӺ�
// ��������֤

#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
using namespace std;
const int N = 1e5;
int n;
int arr[N];

// ��������
// Ϊ����֤
int f(int i, int s)
{
	if(i == n){
		return s % 7 == 0 ? s : 0;
	}
	return max(f(i + 1, s + arr[i]), f(i + 1, s));
}
int maxSum1()
{
	// nums�γɵ����������е��ۼӺͶ������
	// ����%7==0����Щ�ۼӺ��У���������
	// ��������f�����Ĺ���
	return f(0, 0);
}

// ��ʽ����
// ʱ�临�Ӷ�O(n)
int maxSum2()
{
	int (*dp)[7] = new int[n + 1][7];
	memset(dp, 0, sizeof dp);  // ��ʼ��dp�� 
	// dp[i][j] : nums[0...i-1]
	// numsǰi�����γɵ�������һ��Ҫ�������������ۼӺ�%7 == j
	// ����������������ۼӺ��Ƕ���
	// ע�� : dp[i][j] == -1��������������������
	dp[0][0] = 0;
	for(int j = 1; j < 7; j++){
		dp[0][j] = -1;
	}
	
	for(int i = 1, x, cur, need; i <= n; i++){
		x = arr[i - 1];
		cur = arr[i - 1] % 7;
		for(int j = 0; j < 7; j++){
			dp[i][j] = dp[i - 1][j];
			// ������need�Ǻ���
			need = cur <= j ? (j - cur) : (j + 7 - cur);
			// ������������д��Ҳ��
			// need = (7 + j - cur) % 7;
			if(dp[i - 1][need] != -1){
				dp[i][j] = max(dp[i][j], dp[i - 1][need] + x);
			}
		}
	}
	return dp[n][0];
}

// Ϊ�˲���
// �����������
int randomArray(int v)
{
	for(int i = 0; i < n; i++){
		arr[i] = rand() % (v + 1);
	}
}


// Ϊ�˲���
// ������
int main()
{
	srand((unsigned)time(NULL));
	int v = 10000;
	int testTime = 2000;
	cout << "���Կ�ʼ" << endl;
	for(int i = 0; i < testTime; i++){
		n = rand() % 15;  // ���� maxSum1 �������õݹ飬������鲻�ܿ�̫�� 
		randomArray(v);
		int ans1 = maxSum1();
		int ans2 = maxSum2();
		if(ans1 != ans2){
			cout << "��" << i << "�������" << endl;
		}else{
			cout << "��" << i << "����Գɹ�" << endl; 
		}
	}
	cout << "���Խ���" << endl;
	return 0;
}


