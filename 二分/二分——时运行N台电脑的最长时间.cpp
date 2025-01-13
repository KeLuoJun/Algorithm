// ͬʱ����N̨���Ե��ʱ��
// ���� n ̨���ԡ��������� n ��һ���±�� 0 ��ʼ���������� batteries
// ���е� i ����ؿ�����һ̨���� ���� batteries[i] ����
// ����ʹ����Щ����� ȫ�� n ̨���� ͬʱ ���С�
// һ��ʼ������Ը�ÿ̨�������� ����һ�����
// Ȼ������������ʱ�̣��㶼���Խ�һ̨���������ĵ�ضϿ����ӣ���������һ����أ�����Խ���������� �����
// �����ӵĵ�ؿ�����һ��ȫ�µĵ�أ�Ҳ�����Ǳ�ĵ����ù��ĵ��
// �Ͽ����Ӻ������µĵ�ز��Ứ���κ�ʱ�䡣
// ע�⣬�㲻�ܸ���س�硣
// ���㷵��������� n ̨����ͬʱ���е� � ��������
// �������� : https://leetcode.cn/problems/maximum-running-time-of-n-computers/

#include <iostream>
#include <algorithm>
using namespace std;

// ��num̨���Թ�ͬ����time���ӣ��ܲ�������
bool f(int *arr, int num, int time)
{
	long sum = 0;
	for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		//ֱ��������ص���Ϊһ�����Թ��缴�� 
		if(arr[i] >= time)
			num--;
		else
		// x <= time������Ƭ���
			sum += arr[i];
	}
	if(sum >= (long)(num * time))
		return true;
	else
	 	return false;
}

// �����Ķ��ִ𰸷�
// �ύʱ�Ѻ�������ΪmaxRunTime
// ʱ�临�Ӷ�O(n * log(sum))������ռ临�Ӷ�O(1)
int maxRunTime1(int *arr,int n,int num)
{
	long sum = 0;
	for(int i = 0; i < n; i++)
		sum += arr[i];
	long l = 0,r = sum;
	int ans = 0;
	while(l <= r)
	{
		// m�е㣬��num̨���Թ�ͬ����m���ӣ��ܲ�������
		int m = l + ((r - l) >> 1);
		if(f(arr,num,m))
		{
			ans = m;
			l = m + 1;
		}
		else
			r = m - 1;
	}
	return ans;
}


// ���ִ𰸷� + ���ӷ���(̰��)
// �ύʱ�Ѻ�������ΪmaxRunTime
// ʱ�临�Ӷ�O(n * log(max))������ռ临�Ӷ�O(1)
int maxRunTime2(int *arr, int n, int num)
{
	long sum = 0;
	int Max = 0;
	for(int i = 0; i < n; i++)
	{
		sum += arr[i];
		Max = max(Max, arr[i]);
	}
	// ���е�ص���������max
	// �����ʱsum > (long) max * num��
	// ˵�� : ���յĹ���ʱ��һ���� >= max����������յĹ���ʱ�� >= max
	// ˵�� : �������յĴ�X��˵�����е�ض��ǿ��Ͻ���"��Ƭƴ��"�ĸ���
	// ��ôѰ�� ? * num <= sum ������У�������� ? ����
	// ��sum / num
	if(sum >= (long)(Max * num))
		return sum / num;
	// ���յĹ���ʱ��һ���� < max��Χ��
	// [0, sum]���ַ�Χ�����ܶ��ıȽϴ֣���Ȼ��Ӱ�죬���Ͼ����е���
	// [0, max]���ַ�Χ������ϸ�ķ�Χ�����ִ��������
	int l = 0,r = Max;
	int ans = 0;
	while(l <= r)
	{
		int m = l + ((r - l) >> 1);
		if(f(arr,num,m))
		{
			ans = m;
			l = r + 1;
		}
		else
			r = m - 1;
	}
	return ans;
} 


int main()
{
	int n,num;
	cin >> n >> num;
	int *arr = new int[n];
	for(int i = 0 ; i < n; i++)
		cin >> arr[i];
	//int ans = maxRunTime1(arr,n,num);
	int ans = maxRunTime2(arr,n,num);
	cout << ans << endl;
	delete arr;
	return 0;
} 
