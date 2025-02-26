// �����㽶������
// ����ϲ�����㽶�������� n ���㽶���� i ������ piles[i] ���㽶
// �����Ѿ��뿪�ˣ����� h Сʱ�������
// ������Ծ��������㽶���ٶ� k ����λ����/Сʱ)
// ÿ��Сʱ��������ѡ��һ���㽶�����гԵ� k ��
// �������㽶���� k ���������Ե���ѵ������㽶��Ȼ����һСʱ�ڲ����ٳԸ�����㽶
// ����ϲ�������ԣ�����Ȼ���ھ�������ǰ�Ե����е��㽶��
// ������������ h Сʱ�ڳԵ������㽶����С�ٶ� k��k Ϊ������
// �������� : https://leetcode.cn/problems/koko-eating-bananas/

#include <iostream>
using namespace std;
int piles[10000];
int n,h;

// �㽶��������piles
// �ٶȾͶ���speed
// ���س������е��㽶���ķѵ�Сʱ����
int f(int speed)
{
	int ans = 0;
	for(int i = 0; i < n; i++)
	// (a/b)�������ȡ�������a��b���ǷǸ���������д��(a+b-1)/b
	// "����032-λͼ"��������д���������ͬѧ����ȥ����
		ans += (piles[i] + speed - 1) / speed;
	return ans;
}

// ʱ�临�Ӷ�O(n * log(max))������ռ临�Ӷ�O(1)
int minEatingSpeed()
{
	int ans;
	// ��С�Ҵ����ٶȣ���Χ[l,r]
	int l = 1;
	int r = 0;
	for(int i = 0; i < n; i++)
		r = max(r, piles[i]);
	// [l,r]��ͣ����
	while(l <= r)
	{
		int m = l + ((r - l) >> 2);
		if(f(m) <= h)
		{
			// ��꣡
			// ��¼�𰸣�ȥ������
			ans = m;
			// l....m....r
			// l..m-1
			r = m - 1;
		}
		else
			l = m + 1;
	}
	return ans;
}




int main()
{
	cin >> n >> h;
	for(int i = 0; i < n; i++)
		cin >> piles[i];
	int ans = minEatingSpeed();
	cout << ans << endl;
	return 0;
}
