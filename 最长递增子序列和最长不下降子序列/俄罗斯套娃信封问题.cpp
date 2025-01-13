// ����˹�����ŷ�����
// ����һ����ά��������envelopes ������envelopes[i]=[wi, hi]
// ��ʾ�� i ���ŷ�Ŀ�Ⱥ͸߶�
// ����һ���ŷ�Ŀ�Ⱥ͸߶ȶ�������ŷ���ʱ��
// ����ŷ�Ϳ��ԷŽ���һ���ŷ����ͬ����˹����һ��
// ����� ������ж��ٸ��ŷ������һ�顰����˹���ޡ��ŷ�
// �����԰�һ���ŷ�ŵ���һ���ŷ����棬ע�ⲻ������ת�ŷ�
// �������� : https://leetcode.cn/problems/russian-doll-envelopes/

#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 1;
int n;

struct envelope
{
	int a;
	int b;
}envelopes[MAXN];

bool cmp(envelope x, envelope y)
{
	if(x.a == y.a)
		return x.b >= y.b;
	return x.a <= y.a;
}

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


int maxEnvelopes()
{
	// �������:
	// ��ȴ�С����
	// ���һ�����߶ȴӴ�С
	sort(envelopes, envelopes + n, cmp);
	int *ends = new int[n];
	int len = 0;
	for(int i = 0; i < n; i++){
		int num = envelopes[i].b;
		int find = bs(ends, len, num);
		if(find == -1){
			ends[len++] = num;
		}else{
			ends[find] = num;
		}
	}
	return len;
}


int main()
{
	cin >> n;
	int a,b;
	vector<int> v;
	for(int i = 0; i < n; i++){
		cin >> envelopes[i].a >> envelopes[i].b;
	}
	int ans = maxEnvelopes();
	cout << ans << endl;
	return 0;
}
