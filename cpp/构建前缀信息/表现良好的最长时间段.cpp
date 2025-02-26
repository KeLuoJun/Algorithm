// �������õ��ʱ���
// ����һ�ݹ���ʱ��� hours�������¼��ĳһλԱ��ÿ��Ĺ���Сʱ��
// ������Ϊ��Ա��һ���еĹ���Сʱ������ 8 Сʱ��ʱ����ô��һ����� ���۵�һ��
// ��ν �������õ�ʱ��� ����ζ�����ʱ���ڣ������۵����������ϸ� ���� �����۵�����
// ���㷵�� ��������ʱ��� ����󳤶�
// �������� : https://leetcode.cn/problems/longest-well-performing-interval/

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
int arr[MAXN];
int n;

int solve()
{
	int ans = 0;
	map<int, int> m;
	m.insert({0, -1});
	for(int i = 0, sum = 0; i < n; i++){
		sum += arr[i];
		if(sum > 0){
			ans = i + 1;
		}else{
			if(m.find(sum - 1) != m.end())
				ans = max(ans, i - m[sum - 1]);
		}
		if(m.find(sum) == m.end()){
			m.insert({sum, i});
		}
	}
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		arr[i] = arr[i] > 8 ? 1 : -1;
	}
	cout << solve() << endl;
	return 0;
}
