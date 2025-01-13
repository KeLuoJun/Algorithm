// ����ͧ
// �������� people
// people[i]��ʾ�� i ���˵����� �������������ޣ�ÿ�Ҵ����Գ��ص��������Ϊ limit
// ÿ�Ҵ�����ͬʱ�����ˣ�����������Щ�˵�����֮�����Ϊ limit
// ���� �����������������С����
// �������� : https://leetcode.cn/problems/boats-to-save-people/

#include <iostream>
#include <algorithm>
using namespace std;
int n,limit;
int people[10000];

// ʱ�临�Ӷ�O(n * logn)����Ϊ�����򣬶���ռ临�Ӷ�O(1)
void numRescueBoats() 
{
	sort(people,people+n);
	int l = 0,r = n-1;
	int ans = 0;
	while(l <= r)
	{
		int sum = l == r ? people[l] : people[l] + people[r];
		if(sum <= limit)
			l++,r--;
		else
			r--;
		ans++;
	}
	cout << ans << endl;
}

int main()
{
	cin >> n >> limit;
	for(int i = 0; i < n; i++)
		cin >> people[i];
	numRescueBoats();
	return 0;
}
