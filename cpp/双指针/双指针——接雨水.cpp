// ����ˮ
// ���� n ���Ǹ�������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ�����㰴�����е����ӣ�����֮���ܽӶ�����ˮ
// �������� : https://leetcode.cn/problems/trapping-rain-water/

#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000];

// ��������Ľⷨ���������Ž⣩
// ʱ�临�Ӷ�O(n)������ռ临�Ӷ�O(n)
// �ύʱ����Ϊtrap
void trap1(int n)
{
	int *lmax = new int[n]; //�Ӹ�λ�õ��������λ 
	int *rmax = new int[n]; //�Ӹ�λ�õ��Ҳ�����λ 
	lmax[0] = arr[0];
	for(int i = 1; i < n; i++)
		lmax[i] = max(lmax[i-1],arr[i]);
	rmax[n-1] = arr[n-1];
	for(int i = n-2; i >= 0; i--)
		rmax[i] = max(rmax[i+1],arr[i]);
	int ans = 0;
	//ֻ����� 1......n-1 
	for(int i = 1; i < n-1; i++)
	{
		ans += max(0, min(lmax[i-1], rmax[i+1]) - arr[i]);
	}
	cout << ans << endl;
	delete lmax,rmax;
}

// ˫ָ��Ľⷨ�����Ž⣩
// ʱ�临�Ӷ�O(n)������ռ临�Ӷ�O(1)
// �ύʱ����Ϊtrap
void trap2(int n)
{
	//����lλ����˵��lmaxΪl������ʵ���λ 
	//����rλ����˵��rmaxΪr�Ҳ����ʵ���λ 
	int lmax = arr[0];
	int rmax = arr[n-1];
	int l = 1;
	int r = n-2;
	int ans = 0;
	while(l <= r)
	{
		//�������λ�������Ҳ���ٵ����λ
		//������lλ����˵���Ҳ�Ŀǰ�����ֵ��һ����l�Ҳ���ܵ����ֵ
		//�����Ҳ���ڱ�Ŀǰrmax���ߵ��� 
		if(lmax <= rmax)
		{
			ans += max(0, lmax - arr[l]);
			lmax = max(lmax, arr[l++]);
		}
		else
		{
			ans += max(0,rmax - arr[r]);
			rmax = max(rmax, arr[r--]);
		}
	}
	cout << ans << endl;
} 


int main()
{
	int n;
	cin >> n;
	for(int i = 0 ; i < n; i++)
		cin >> arr[i];
	//trap1(n);
	trap2(n);
	return 0;
}
