// �ָ���������ֵ(��������)
// ����һ���Ǹ��������� nums ��һ������ m
// ����Ҫ���������ֳ� m ���ǿյ����������顣
// ���һ���㷨ʹ���� m ����������Ժ͵����ֵ��С��
// �������� : https://leetcode.cn/problems/split-array-largest-sum/

#include <iostream>
using namespace std;
int nums[10000];
int n,k;

// ����������arrÿһ���ֵ��ۼӺ� <= limit�����ʻ��ֳɼ������ֲŹ�!
// ������Ҫ�Ĳ�������
int f(int limit)
{
	int ans = 1;
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		if(nums[i] > limit)
			return INT_MAX;
		if(sum + nums[i] > limit)
		{
			ans++;
			sum = nums[i];
		}
		else
			sum += nums[i];
	}
	return ans;
}

// ʱ�临�Ӷ�O(n * log(sum))������ռ临�Ӷ�O(1)
int splitArray()
{
	int sum = 0;
	// [0,sum]����
	for(int i = 0; i < n; i++)
		sum += nums[i];
	int l = 0,r = sum;
	int m,need,ans;
	// ����������ÿһ���ֵ��ۼӺ� <= m�����ʻ��ֳɼ������ֲŹ�!
	while(l <= r)
	{
		m = l + (r - l) / 2;
		need = f(m);
		if(need <= k)
		{
			// ���
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
		cin >> nums[i];
	int ans = splitArray();
	cout << ans << endl;
	return 0;
}
