// �������
// ����һ����n��������ɵ���������pairs
// ���� pairs[i] = [lefti, righti] �� lefti < righti
// ���ڣ����Ƕ���һ�� ���� ��ϵ�����ҽ��� b < c ʱ
// ���� p2 = [c, d] �ſ��Ը��� p1 = [a, b] ����
// ������������ʽ������ ������
// �ҳ��������ܹ��γɵ���������ĳ���
// �������� : https://leetcode.cn/problems/maximum-length-of-pair-chain/

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 101;
int n;
struct pairr
{
	int a;
	int b;
}pairs[MAXN];

bool cmp(pairr x, pairr y)
{
	return x.a <= y.a;
}

// >= num����λ��
int bs(int *ends, int len, int num)
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

int findLongestChain()
{
	// ��β����ֵ
	int *ends = new int[MAXN];
	// ���Ը��ݿ�ʼλ�����򣬴�С����
	// ����λ������ν��
	sort(pairs, pairs + n, cmp);
	int len = 0;
	for(int i = 0; i < n; i++){
		int find = bs(ends, len, pairs[i].a);
		if(find == -1){
			ends[len++] = pairs[i].b;
		}else{
			ends[find] = min(ends[find], pairs[i].b);
		}
	}
	return len;
}



int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> pairs[i].a >> pairs[i].b;
	}
	cout << findLongestChain() << endl;
	return 0;
}
