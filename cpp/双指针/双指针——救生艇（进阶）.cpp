// 救生艇
// 给定数组 people
// people[i]表示第 i 个人的体重 ，船的数量不限，每艘船可以承载的最大重量为 limit
// 每艘船最多可同时载两人，但条件是这些人的重量之和最多为 limit
// 返回 承载所有人所需的最小船数
// 进阶：每艘船上的总体重必须为偶数 

#include <iostream>
#include <algorithm>
using namespace std;
int person[10000];
int n,limit;
int l,r;
int ans = 0;

//奇偶分离，左奇，右偶 
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
