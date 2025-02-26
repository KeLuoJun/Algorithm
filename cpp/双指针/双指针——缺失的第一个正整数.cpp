// ȱʧ�ĵ�һ������
// ����һ��δ������������� nums �������ҳ�����û�г��ֵ���С����������
// ����ʵ��ʱ�临�Ӷ�Ϊ O(n) ����ֻʹ�ó����������ռ�Ľ��������
// �������� : https://leetcode.cn/problems/first-missing-positive/

#include <iostream>
#include <algorithm>
using namespace std;
int arr[10000];
int n;

// ʱ�临�Ӷ�O(n)������ռ临�Ӷ�O(1)
void firstMissingPositive()
{
	// l����ߣ���������iλ���Ϸ���i+1������
	// ��Զ����lλ�õ����ֿ������ܲ�������(l++)
	int l = 0;
	// [r....]������
	// ��õ�״���£���Ϊ1~r�ǿ����ռ�ȫ�ģ�ÿ�������ռ�1��������������
	// �������أ�Ԥ�ھͻ���(r--)
	int r = n;
	while(l < r)
	{
		if(arr[l] <= l || arr[l] > r || arr[arr[l] - 1] == arr[l])
			swap(arr[l],arr[--r]);
		else if(arr[l] == l + 1)
			l++;
		else
			swap(arr[l], arr[arr[l] - 1]);
	}
	cout << l + 1 << endl;
}



int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	firstMissingPositive();
	return 0;
} 
