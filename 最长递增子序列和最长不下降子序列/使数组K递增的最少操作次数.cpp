// ʹ����K���������ٲ�������
// ����һ���±��0��ʼ����n��������������arr����һ��������k
// �������ÿ������ k <= i <= n-1 ���±� i
// ���� arr[i-k] <= arr[i] ����ô�� arr ��K������
// ÿһ�β����У������ѡ��һ���±�i����arr[i]�ĳ�����������
// ���㷵�ض��ڸ����� k ��ʹ������K���������ٲ�������
// �������� : https://leetcode.cn/problems/minimum-operations-to-make-the-array-k-increasing/

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1;
int arr[MAXN];
int nums[MAXN];
int n,k;

int bs(int *ends, int len, int num)
{
	int l = 0, r  = len - 1, ans = -1;
	while(l <= r){
		int m = l + ((r - l) >> 1);
		if(ends[m] > num){
			ans = m;
			r = m - 1;
		}else{
			l = m + 1;
		}
	}
	return ans;
}

// nums[0...size-1]�е�����½������г���
int lengthOfNoDecreasing(int size)
{
	int *ends = new int[size];
	int len = 0;
	for(int i = 0; i < size; i++){
		int find = bs(ends, len, nums[i]);
		if(find == -1){
			ends[len++] = nums[i];
		}else{
			ends[find] = nums[i];
		}
	}
	return len;
}

int kIncreasing()
{
	int ans = 0;
	for(int i = 0; i < k; i++){
		int size = 0;
		// ��ÿһ������ַ�������
		for(int j = i; j < n; j += k){
			nums[size++] = arr[j];
		}
		// ��ǰ�鳤�� - ��ǰ������½������г��� = ��ǰ��������Ҫ�޸ĵ����ָ���
		ans += size - lengthOfNoDecreasing(size);
	}
	return ans;
}


int main()
{
	srand((unsigned)time(NULL));
	n = rand() % (MAXN + 1);
	k = rand() % n;
	cout << n << " " << k << endl;
	for(int i = 0; i < n; i++){
		arr[i] = rand() % (MAXN + 1);
		cout << arr[i] << " ";
		if(i % 9 == 0)
			cout << endl;
	}
	cout << endl;
	cout << kIncreasing() << endl;
	return 0;
}
