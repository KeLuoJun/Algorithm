// 俄罗斯套娃信封问题
// 给你一个二维整数数组envelopes ，其中envelopes[i]=[wi, hi]
// 表示第 i 个信封的宽度和高度
// 当另一个信封的宽度和高度都比这个信封大的时候
// 这个信封就可以放进另一个信封里，如同俄罗斯套娃一样
// 请计算 最多能有多少个信封能组成一组“俄罗斯套娃”信封
// 即可以把一个信封放到另一个信封里面，注意不允许旋转信封
// 测试链接 : https://leetcode.cn/problems/russian-doll-envelopes/

#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 1;
int n;

struct envelope
{
	int a;
	int b;
}envelopes[MAXN];

bool cmp(envelope x, envelope y)
{
	if(x.a == y.a)
		return x.b >= y.b;
	return x.a <= y.a;
}

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


int maxEnvelopes()
{
	// 排序策略:
	// 宽度从小到大
	// 宽度一样，高度从大到小
	sort(envelopes, envelopes + n, cmp);
	int *ends = new int[n];
	int len = 0;
	for(int i = 0; i < n; i++){
		int num = envelopes[i].b;
		int find = bs(ends, len, num);
		if(find == -1){
			ends[len++] = num;
		}else{
			ends[find] = num;
		}
	}
	return len;
}


int main()
{
	cin >> n;
	int a,b;
	vector<int> v;
	for(int i = 0; i < n; i++){
		cin >> envelopes[i].a >> envelopes[i].b;
	}
	int ans = maxEnvelopes();
	cout << ans << endl;
	return 0;
}
