// 多重背包通过二进制分组转化成01背包(模版)
// 宝物筛选
// 一共有n种货物, 背包容量为t
// 每种货物的价值(v[i])、重量(w[i])、数量(c[i])都给出
// 请返回选择货物不超过背包容量的情况下，能得到的最大的价值
// 测试链接 : https://www.luogu.com.cn/problem/P1776


#include <iostream>
using namespace std;
const int MAXN = 101;
const int MAXM = 1001;
int *v = new int[MAXN];
int *w = new int[MAXN];
int n,t;
int m = 0;   // 作为二进制转化后的新的项数 

// 时间复杂度O(t * (log(第1种商品的个数) + log(第2种商品的个数) + ... + log(第n种商品的个数)))
// 对每一种商品的个数取log，所以时间复杂度虽然大于O(n * t)，但也不会大多少
// 多重背包最常用的方式

// 01背包的空间压缩代码(模版)
int compute()
{
	int *dp = new int[MAXM];
	for(int i = 0; i <= t; i++) dp[i] = 0;
	// 转化后一共变为m项，而不是给定的n项 
	for(int i = 1; i <= m; i++){
		for(int j = t; j >= w[i]; j--){
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	return dp[t];
}


int main()
{
	cin >> n >> t;
	int vv,ww,cnt;
	for(int i = 1; i <= n; i++){
		cin >> vv >> ww >> cnt;
		// 二进制转化 
		for(int k = 1; k <= cnt; k << 1){
			v[++m] = k * vv;
			w[m] = k * ww;
			cnt -= k;
		}
		// 二进制转化后不够二进制位的数量 
		if(cnt > 0){
			v[++m] = cnt * vv;
			w[m] = cnt * ww;
		}
	}
	cout << compute() << endl;
	return 0;
}
