// 刀砍毒杀怪兽问题
// 怪兽的初始血量是一个整数hp，给出每一回合刀砍和毒杀的数值cuts和poisons
// 第i回合如果用刀砍，怪兽在这回合会直接损失cuts[i]的血，不再有后续效果
// 第i回合如果用毒杀，怪兽在这回合不会损失血量，但是之后每回合都损失poisons[i]的血量
// 并且你选择的所有毒杀效果，在之后的回合都会叠加
// 两个数组cuts、poisons，长度都是n，代表你一共可以进行n回合
// 每一回合你只能选择刀砍或者毒杀中的一个动作
// 如果你在n个回合内没有直接杀死怪兽，意味着你已经无法有新的行动了
// 但是怪兽如果有中毒效果的话，那么怪兽依然会在血量耗尽的那回合死掉
// 返回至少多少回合，怪兽会死掉
// 数据范围 : 
// 1 <= n <= 10^5
// 1 <= hp <= 10^9
// 1 <= cuts[i]、poisons[i] <= 10^9

#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100000;
int cuts[MAXN];
int poisons[MAXN];
int hp,n,m;

bool f(int limit, int &hp1)
{
	int k = min(n,limit);
	for(int i = 0,j = 1; i < k; i++,j++)
	{
		hp1 -= max(cuts[i],(limit - j) * poisons[i]);
		if(hp1 <= 0)
			return true;
	}
	return false;
}


int fast()
{
	int l = 0;
	int r = hp + 1;
	int ans = 0;
	while(l <= r)
	{
		int m = l + ((r - l ) >> 1);
		if(f(m,hp))
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
	cin >> hp >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> cuts[i];
	for(int i = 0; i < m; i++)
		cin >> poisons[i]; 
	int ans = fast();
	cout << ans << endl;
	return 0;
}

