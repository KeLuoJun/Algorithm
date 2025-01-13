// �ҳ���KС�����Ծ���
// ���� (a,b) ������ a �� b ��ɣ������Ծ��붨��Ϊ a �� b �ľ��Բ�ֵ��
// ����һ���������� nums ��һ������ k
// ������ nums[i] �� nums[j] ��������� 0 <= i < j < nums.length
// ���� �������Ծ����� �� k С�����Ծ��롣
// �������� : https://leetcode.cn/problems/find-k-th-smallest-pair-distance/

#include <iostream>
#include <algorithm>
using namespace std;
int n,k;
int arr[100000];

// arr�����������Ĳ�ֵ <= limit
// ������������ԣ��м��ԣ�
int f(int limit)
{
	int ans = 0;
	//�������� 
	for(int l = 0,r = 0; l < n; l++)
	{
		while(r + 1 < n && arr[r + 1] - arr[l] <= limit)
			r++;
		// arr[l...r]��Χ�ϵ�����ֵ�ľ���ֵ��������limit
		// arr[0...3]
		// 0,1
		// 0,2
		// 0,3
		ans += r - l;
	}
	return ans;
}


// ʱ�临�Ӷ�O(n * log(n) + log(max-min) * n)������ռ临�Ӷ�O(1)
int smallestDistancePair()
{
	sort(arr, arr+n);
	int l = 0;
	int r = arr[n-1] - arr[0];
	int ans = 0;
	// [0, ���-��С]����ͣ����
	while(l <= r)
	{
		int m = l + ((r - l) >> 1);
		// �������ֶԵ�����
		int cnt = f(m);
		if(cnt >= k)
		{
			ans = m;
			r = m - 1;
		}
		else
			l = m + 1;
	}
	return ans;
}


int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	int ans = smallestDistancePair();
	cout << ans << endl;
	return 0;
} 
