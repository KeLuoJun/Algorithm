//����һ������������ nums�������Ƴ� ��� �����飨����Ϊ �գ���
//ʹ��ʣ��Ԫ�ص� �� �ܱ� p ������ ������ ���������鶼�Ƴ���
//���㷵������Ҫ�Ƴ������������ĳ��ȣ�����޷�������ĿҪ�󣬷��� -1 ��
//�������ӣ�https://leetcode.cn/problems/make-sum-divisible-by-p/ 

#include <iostream>
using namespace std;
#include <map>
#include <climits>

int min(int a,int b)
{
	return a > b ? b : a;
}

int main()
{
	int n,p;
	cin >> n >> p;
	int *num = new int[n];
	
	int mod = 0;  //�����ģ 
	for(int i = 0; i < n; i++)
	{
		cin >> num[i];
		mod = (mod + num[i]) % p;
		// ���� mod += (mod + num[i]) % p; 
	}
	if(mod == 0) return 0;
	map<int,int> m;
	m[0] = -1;
	int ans = INT_MAX;
	for(int i = 0, cur = 0, find; i < n; i++)
	{
		cur = (cur + num[i]) % p;  //��ǰλ��֮ǰ���������ģ 
		find = cur >= mod ? (cur - mod) : (cur + p - mod);
		// find  = (cur + p - mod) % p;
		if(m.find(find) != m.end())
			ans = min(ans, i - m[find]);
		m[cur] = i; //����ģΪcur������λ�� 
	}
	if(ans == n) ans = -1;
	cout << ans << endl;
	delete num; 
	return 0;
}
