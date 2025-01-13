// Ѱ���ظ���
// ����һ������ n + 1 ������������ nums �������ֶ��� [1, n] ��Χ�ڣ����� 1 �� n��
// ��֪���ٴ���һ���ظ���������
// ���� nums ֻ�� һ���ظ������� ������ ����ظ����� ��
// ����ƵĽ���������� ���޸� ���� nums ��ֻ�ó����� O(1) �Ķ���ռ䡣
// �������� : https://leetcode.cn/problems/find-the-duplicate-number/

#include <iostream>
using namespace std;

int main()
{
	int n = 8;
	int arr[n] = {2,5,7,4,9,5,3,1};
	//����ָ���ҵ��뻷�㼴Ϊ�ظ���Ԫ�� 
	int fast = arr[arr[0]];
	int slow = arr[0];
	//fastһ����������slowһ����һ�� 
	while(fast != slow)
	{
		fast = arr[arr[fast]];
		slow = arr[slow];
	}
	//��һ������֮��fast�ص���ʼλ�ã�֮��fastһ����һ�� 
	fast = arr[0];
	//����ָ���ٴ�����
	while(fast != slow)
	{
		fast = arr[fast];
		slow = arr[slow];
	}
	cout << fast << endl;
	return 0; 
} 
