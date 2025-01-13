// ����ͧ
// �������� people
// people[i]��ʾ�� i ���˵����� �������������ޣ�ÿ�Ҵ����Գ��ص��������Ϊ limit
// ÿ�Ҵ�����ͬʱ�����ˣ�����������Щ�˵�����֮�����Ϊ limit
// ���� �����������������С����
// ���ף�ÿ�Ҵ��ϵ������ر���Ϊż�� 

#include <iostream>
#include <algorithm>
using namespace std;
int person[10000];
int n,limit;
int l,r;
int ans = 0;

//��ż���룬���棬��ż 
void separte()
{
	l = 0,r = n-1;
	while(l < r)
	{
		while((person[l] & 1) == 1)
			l++;
		while((person[r] & 1) != 1)
			r--;
		swap(person[l++],person[r--]);
	}
	if(l == r)
	{
		if((person[l] & 1) == 1) r++;
		else l--;
	}
}

void numRescueBoats(int a,int b) 
{
	sort(person, person + b - a + 1);
	while(a <= b)
	{
		int sum = a == b ? person[a] : person[a] + person[b];
		if(sum <= limit) a++,b--;
		else b--;
		ans++; 
	}
}

void func()
{
	separte();
	numRescueBoats(0,l);
	numRescueBoats(r,n-1);
	cout << ans << endl;
}


int main()
{
	cin >> n >> limit;
	for(int i = 0; i < n; i++)
		cin >> person[i];
	func();
	return 0;
}
