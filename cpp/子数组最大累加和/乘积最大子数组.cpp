// �˻����������
// ����һ���������� nums
// �����ҳ������г˻����ķǿ�����������
// �����ظ�����������Ӧ�ĳ˻�
// �������� : https://leetcode.cn/problems/maximum-product-subarray/

#include <iostream>
using namespace std;
const int N = 1e5;
int n;
int arr[N];

int maxProduct()
{
	int ans = arr[0];
	int maxnum = arr[0];
	int minnum = arr[0];
	int curmax, curmin;
	for(int i = 1; i < n; i++){
		curmin = min(arr[i], min(minnum * arr[i], maxnum * arr[i]));
		curmax = max(arr[i], max(minnum * arr[i], maxnum * arr[i]));
		minnum = curmin;
		maxnum = curmax;
		ans = max(ans, maxnum);
	}
	return ans;
}



int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int ans = maxProduct();
	cout << ans << endl;
	return 0;
	
 } 
