// ���������в���ѡ����Ԫ�ص�����ۼӺ�
// ����һ������nums������Ϊn
// nums��һ���������飬�±�0���±�n-1������һ���
// ��������ѡ�����֣����ǲ���ѡ�����ڵ�����
// �����ܵõ�������ۼӺ�
// �������� : https://leetcode.cn/problems/house-robber-ii/

#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 101;
int *nums = new int[MAXN];
int n;

int best(int l, int r)
{
	if(l > r)
		return 0;
	if(l == r)
		return nums[l];
	if(l == r - 1)
		return max(nums[l], nums[r]);
	int prepre = nums[l];
	int pre = max(nums[l], nums[l + 1]);
	for(int i = l + 2, cur; i <= r; i++){
		cur = max(pre, max(nums[i], prepre + nums[i]));
		prepre = pre;
		pre = cur;
	}
	return pre;	
}



int rob()
{
	if(n == 1)
		return nums[0];
	// best(1, n - 1) ��ʾ����nums[0]λ�õ������������ 1 �� n-1 λ�õ����еõ�������
	// nums[0] + best(2, n - 2) ��ʾ��nums[0]λ�õ������������ 2 �� n-2 λ�õ����еõ�������
	return max(best(1, n - 1), nums[0] + best(2, n - 2));
}


int main()
{
	cin >> n; 
	for(int i = 0; i < n; i++){
		cin >> nums[i];
	}
	cout << rob() << endl;
	return 0;
}
