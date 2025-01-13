// 最长数对链
// 给你一个由n个数对组成的数对数组pairs
// 其中 pairs[i] = [lefti, righti] 且 lefti < righti
// 现在，我们定义一种 跟随 关系，当且仅当 b < c 时
// 数对 p2 = [c, d] 才可以跟在 p1 = [a, b] 后面
// 我们用这种形式来构造 数对链
// 找出并返回能够形成的最长数对链的长度
// 测试链接 : https://leetcode.cn/problems/maximum-length-of-pair-chain/

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 101;
int n;
struct pairr
{
	int a;
	int b;
}pairs[MAXN];

bool cmp(pairr x, pairr y)
{
	return x.a <= y.a;
}

// >= num最左位置
int bs(int *ends, int len, int num)
{
	int l = 0, r = len - 1, ans = -1;
	while(l <= r){
		int m = l + ((r - l) >> 1);
		if(ends[m] >= num){
			ans = m;
			r = m - 1;
		}else{
			l = m + 1;
		}
	}
	return ans;
}

int findLongestChain()
{
	// 结尾的数值
	int *ends = new int[MAXN];
	// 数对根据开始位置排序，从小到大
	// 结束位置无所谓！
	sort(pairs, pairs + n, cmp);
	int len = 0;
	for(int i = 0; i < n; i++){
		int find = bs(ends, len, pairs[i].a);
		if(find == -1){
			ends[len++] = pairs[i].b;
		}else{
			ends[find] = min(ends[find], pairs[i].b);
		}
	}
	return len;
}



int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> pairs[i].a >> pairs[i].b;
	}
	cout << findLongestChain() << endl;
	return 0;
}
