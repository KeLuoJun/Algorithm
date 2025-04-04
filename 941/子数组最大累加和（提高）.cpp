// ���´���Ϊ���������ʵ��
// ���������ҵ�ӵ������ۼӺ͵�������
// ����������������Ϣ:
// 1) ����ۼӺ�������Ŀ�ͷleft
// 2) ����ۼӺ�������Ľ�βright
// 3) ����ۼӺ���������ۼӺ�sum
// �����ֹһ��������ӵ������ۼӺͣ���ô�ҵ���һ��������
// �������� : https://leetcode.cn/problems/maximum-subarray/

#include <iostream>
using namespace std;
const int MAXN = 1e5+1;
int *nums = new int[MAXN];
int sum = INT_MIN;
int n;


void extra(int &left, int &right)
{
	int l = 0,r = 1;
	for(int i = 1,pre = nums[0]; i < n; i++,r++){
		if(pre > 0){
			pre += nums[i];
		}
		else{
			pre = nums[i];
			l = r;
		}
		if(pre > sum){
			sum = pre;
			left = l;
			right = r;
		}
	}
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> nums[i];
	}
	int left,right;
	extra(left,right);
	cout << left << right << sum << endl;
	return 0;
}

