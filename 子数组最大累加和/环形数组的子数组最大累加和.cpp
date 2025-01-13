// �������������������ۼӺ�
// ����һ������nums������Ϊn
// nums��һ���������飬�±�0���±�n-1������һ���
// ���ػ��������У�����������ۼӺ�
// �������� : https://leetcode.cn/problems/maximum-sum-circular-subarray/


#include <iostream>
using namespace std;
const int MAXN = 1e5;
int *nums = new int[MAXN];
int n;

int maxSubarraySumCircular()
{
	int all = nums[0], maxsum = nums[0], minsum = nums[0];
	for(int i = 1, premax = 0, premin = 0; i < n; i++){
		all += nums[i];
		premax = max(nums[i], premax + nums[i]);
		maxsum = max(maxsum, premax);
		premin = min(nums[i], premin + nums[i]);
		minsum = min(minsum, premin);
	}
	return all == minsum ? maxsum : max(maxsum, all - minsum);
}


int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)	
		cin >> nums[i];
	cout << maxSubarraySumCircular() << endl;
	return 0;
}
