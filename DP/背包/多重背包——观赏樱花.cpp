// 观赏樱花 
// 给定一个背包的容量t，一共有n种货物，并且给定每种货物的信息
// 花费(cost)、价值(val)、数量(cnt)
// 如果cnt == 0，代表这种货物可以无限选择
// 如果cnt > 0，那么cnt代表这种货物的数量
// 挑选货物的总容量在不超过t的情况下，返回能得到的最大价值
// 背包容量不超过1000，每一种货物的花费都>0
// 测试链接 : https://www.luogu.com.cn/problem/P1833

#include <iostream>
using namespace std;
const int MAXN = 100001;
const int MAXW = 1001;
int *v = new int[MAXN];
int *w = new int[MAXN];
int *dp = new int[MAXW];
int n,t,m = 0;

int compute()
{
	for(int i = 0; i <= t; i++) dp[i] = 0;
	for(int i = 1; i <= m; i++){
		for(int j = t; j >= w[i]; j--){
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	return dp[t];
}

int main()
{
	int h1,m1,h2,m2;
	scanf("%d:%d %d:%d %d",&h1,&m1,&h2,&m2,&n);
	t = h2 * 60 + m2 - (h1 * 60 + m1);
	//cin >> n >> t;
	int vv,ww,cnt;
	for(int i = 1; i <= n; i++){
		cin >> ww >> vv >> cnt;
		if(cnt == 0) cnt = 1000;
		for(int k = 1; k <= cnt; k << 1){
			v[++m] = k * vv;
			w[m] = k * ww;
			cnt -= k;
		}
		if(cnt > 0){
			v[++m] = cnt * vv;
			w[m] = cnt * ww;
		}
	}
	cout << compute() << endl;
	return 0;
}
