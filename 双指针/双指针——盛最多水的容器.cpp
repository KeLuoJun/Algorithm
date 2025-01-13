// ʢ���ˮ������
// ����һ������Ϊ n ���������� height ���� n �����ߣ��� i ���ߵ������˵��� (i, 0) �� (i, height[i]) ��
// �ҳ����е������ߣ�ʹ�������� x �Ṳͬ���ɵ�����������������ˮ
// �����������Դ�������ˮ��
// ˵�����㲻����б����
// �������� : https://leetcode.cn/problems/container-with-most-water/

#include <iostream>
#include <algorithm>
using namespace std;
int height[10000];
int n;

// ʱ�临�Ӷ�O(n)������ռ临�Ӷ�O(1)
void maxArea()
{
	int ans = 0;
	int l = 0, r = n-1;
	while(l < r)
	{
		ans = max(ans, min(height[l], height[r]) * (r - l));
		if(height[l] <= height[r]) l++;
		else r--;
	}
	cout << ans << endl;
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> height[i];
	maxArea();
	return 0;
 } 
