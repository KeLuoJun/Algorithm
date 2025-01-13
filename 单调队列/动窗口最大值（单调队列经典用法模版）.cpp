// �����������ֵ���������о����÷�ģ�棩
// ����һ���������� nums����һ����СΪ k �Ļ������ڴ������������ƶ�����������Ҳ�
// ��ֻ���Կ����ڻ��������ڵ� k �����֡���������ÿ��ֻ�����ƶ�һλ��
// ���� ���������е����ֵ ��
// �������� : https://leetcode.cn/problems/sliding-window-maximum/

#include <iostream>
using namespace std;
const int N = 100001;
int n,k;
int nums[N];
int dq[N];
int ans[N];
int h, t;

void maxSlidingWindow()
{
	h = t = 0;
	// ���γɳ���Ϊk-1�Ĵ���
	for(int i = 0; i < k - 1; i++){
		// �� -> С �������ֵ��
		// С -> �� ������Сֵ�� 
		while(h < t && nums[dq[t - 1]] <= nums[i]){
			t--;
		}
		dq[t++] = i;
	}
	int m = n - k + 1;
	// ��ǰ����k-1����
	for(int l = 0, r = k - 1; l < m; l++, r++){
		// ��һ����Ҫ��rλ�õ�������
		while(h < t && nums[dq[t - 1]] <= nums[r]){
			t--;
		}
		dq[t++] = r;
		// �ռ���
		ans[l] = nums[dq[h]];
		// lλ�õ�����ȥ
		if(dq[h] == l){
			h++;
		}
	}
}



int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> nums[i];
	}
	maxSlidingWindow();
	for(int i = 0; i < n - k + 1; i++){
		cout << ans[i] << " ";
	}
	return 0;
	
}
