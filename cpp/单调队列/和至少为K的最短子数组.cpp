// ������ΪK�����������
// ����һ������arr�����е�ֵ�п�����������0
// ����һ������k
// �����ۼӺ�>=k�������������У���̵������鳤��
// �������� : https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/

#include <iostream>
using namespace std;
typedef long long ll;
const int N = 100001;
int n, k;
int arr[N];
ll sum[N];
int dq[N];
int h,t;

int shortestSubarray()
{
	// sum[0] : ǰ0������ǰ׺��
	// sum[i] : ǰi������ǰ׺��
	sum[0] = 0;
	for(int i = 0; i < n; i++){
		// [3,4,5]
		//  0 1 2
		// sum[0] = 0
		// sum[1] = 3
		// sum[2] = 7
		// sum[3] = 12
		sum[i + 1] = sum[i] + arr[i];
	}
	h = t = 0;
	int ans = INT_MAX;
	for(int i = 0; i <= n; i++){
		// ǰ0����ǰ׺��
		// ǰ1����ǰ׺��
		// ǰ2����ǰ׺��
		// ...
		// ǰn����ǰ׺��
		while(h != t && sum[i] - sum[dq[h]] >= k){
			// �����ǰ��ǰ׺�� - ͷǰ׺�ͣ���꣡
			ans = min(ans, i - dq[h++]);
		}
		// ǰi����ǰ׺�ͣ���β������
		// С ��
		while(h != t && sum[dq[t - 1]] >= sum[i]){
			t--;
		}
		dq[t++] = i;
	}
	return ans != INT_MAX ? ans : -1;
}


int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int ans = shortestSubarray();
	cout << ans << endl;
	return 0;
}
