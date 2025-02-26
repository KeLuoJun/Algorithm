// �����������������
// ����һ����������nums������Ҫ�ҳ�һ�� ����������
// ���������������������������ô�������鶼���Ϊ��������
// �����ҳ������������������飬��������ĳ���
// �������� : https://leetcode.cn/problems/shortest-unsorted-continuous-subarray/

#include <iostream>
using namespace std;
const int MAXN = 1e6;
int n;
int arr[MAXN];

int findUnsortedSubarray()
{
	// max > ��ǰ������Ϊ�����
	// �������ұ�������¼���Ҳ�����λ��
	int right = -1;
	int maxx = INT_MIN;
	for(int i = 0; i < n; i++){
		if(maxx > arr[i]){
			right = i;
		}
		maxx = max(maxx, arr[i]);
	}
	// min < ��ǰ������Ϊ�����
	// ���������������¼���󲻴���λ��
	int minn = INT_MAX;
	int left = n;
	for(int i = n - 1; i >= 0; i--){
		if(minn < arr[i]){
			left = i;
		}
		minn = min(minn, arr[i]);
	}
	return max(0, right - left + 1);
}


int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cout << findUnsortedSubarray() << endl;
	return 0;
 } 
