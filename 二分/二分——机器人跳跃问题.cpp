// ��������Ծ����
// ������������һ�����ϵĻ���DOS����Ϸ
// ��Ϸ����N+1����������0��N��ţ�����������
// ���Ϊ0�Ľ����߶�Ϊ0����λ�����Ϊi�Ľ����ĸ߶�ΪH(i)����λ
// ����������ڱ��Ϊ0�Ľ�����
// ÿһ������������һ�����ұߣ�����������������ڵ�k���������������ڵ�����ֵ��E
// ��һ�����������ڸ�k+1����
// ������õ�����ʧȥ��������H(k+1)��E֮�������
// ��� H(k+1) > E ��ô�����˾�ʧȥH(k+1)-E������ֵ�����������õ�E-H(k+1)������ֵ
// ��ϷĿ���ǵ���ڸ�N����������������У�����ֵ����Ϊ��������λ
// ���ڵ������ǻ������Զ�������ֵ��ʼ��Ϸ���ſ��Ա�֤�ɹ������Ϸ
// �������� : https://www.nowcoder.com/practice/7037a3d57bbd4336856b8e16a9cafd71

#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[10000];

bool f(int energy,int Max)
{
	// ע�⣡
	// �����������ֵ�ܴ���ô���������������ǳ��ֲ�
	// ��ȫ�п��ܳ���long�ķ�Χ
	// ����Ҫ�ڱ���ʱ��һ��Ҫ����energy >= max���ж�
	// һ�����������߶����ֵ������϶�ͨ���ˣ�������ǰ������
	// �������
	for(int i = 0; i < n; i++)
	{
		energy += energy - arr[i];
		if(energy >= Max)
			return true;
		if(energy < 0)
			return false;
	}
	return true;
}


// [l,r]ͨ��������С�����ķ�Χ����ͣ����
// max�����н��������߶�
// ʱ�临�Ӷ�O(n * log(max))������ռ临�Ӷ�O(1)
int computer()
{
	int l = 0,r = 0;
	for(int i = 0; i < n; i++)
		r = max(r,arr[i]);
	int Max = r;
	int ans = -1;
	while(l <= r)
	{
		// m�е㣬��ʱͨ������涨�ĳ�ʼ����
		int m = l + ((r - l) >> 1);
		if(f(m,Max))
		{
			ans = m;
			r = m - 1;
		}
		else
			l = m + 1;
	}
	return ans;
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	int ans = computer();
	cout << ans << endl;
	return 0;
 } 
