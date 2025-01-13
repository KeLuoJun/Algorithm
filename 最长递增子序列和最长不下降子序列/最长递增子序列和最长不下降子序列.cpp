// ����������к�����½�������
// ����һ����������nums
// �ҵ�������ϸ���������г��ȡ�����½������г���
// �������� : https://leetcode.cn/problems/longest-increasing-subsequence/

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2510;
const int MAXM = 1e8;
int nums[MAXN];
int n;

// ��ͨ�ⷨ�Ķ�̬�滮
// ʱ�临�Ӷ�O(n^2)�������Դ�ͻᳬʱ
int lengthOfLIS1()
{
	int *dp = new int[n];
	int ans = 0;
	for(int i = 0; i < n; i++){
		dp[i] = 1;
		for(int j = 0; j < i; j++){
			if(nums[j] < nums[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}
	return ans;
}



// "�����������"ʹ�����¶������� :
// ends[0...len-1]���ϸ�����ģ��ҵ�>=num������λ��
// ��������ڷ���-1
int bs1(int *ends, int len, int num)
{
	int l = 0, r = len - 1, ans = -1;
	while(l <= r){
		int m = l + ((r - l) >> 1);
		if(ends[m] >= num){
			ans = m;
			r = m - 1;
		}else{
			l = m + 1;
		}
	}
	return ans;
}

// ���������½������У���ôʹ�����µĶ������� :
// ends[0...len-1]�ǲ������
// �������ҵ�>num������λ�ã���������ڷ���-1
// ���������½������У�����lengthOfLIS�а�bs1��������bs2����
int bs2(int *ends, int len, int num)
{
	int l = 0, r = len - 1, ans = -1;
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


// ���Ž�
// ʱ�临�Ӷ�O(n * logn)
int lengthOfLIS2()
{
	int *ends = new int[n];
	// len��ʾends����Ŀǰ����Ч������
	// ends[0...len-1]����Ч������Ч���ڵ�����һ���ϸ�����
	int len = 0;
	for(int i = 0; i < n; i++){
		int find = bs1(ends, len, nums[i]);
		if(find == -1){
			ends[len++] = nums[i];
		}else{
			ends[find] = nums[i];
		}
	}
	return len;
}

int main()
{
	srand((unsigned)time(NULL));
	n = rand() % (MAXN + 1);
	for(int i = 0; i < n; i++){
		nums[i] = rand() % MAXM - 1e4;
	}
	int ans1 = lengthOfLIS1();
	int ans2 = lengthOfLIS2();
	
	cout << ans1 << endl;
	cout << ans2 << endl;
	return 0;
 } 
