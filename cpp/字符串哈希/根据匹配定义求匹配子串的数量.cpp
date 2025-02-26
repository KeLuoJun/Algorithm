// 根据匹配定义求匹配子串的数量
// 给定长为n的字符串s，以及长度为m的字符串p，还有一个正数k
// s'与s匹配的定义为，s'与s长度相同，且最多有k个位置字符不同
// 要求查找字符串s中有多少子串与字符串p匹配
// 测试链接 : https://www.luogu.com.cn/problem/P3763

#include <iostream>
#include <string>
using namespace std;
const int base = 499;
const int N = 100001;
int t;
long pow[N];
long hashs[N];
long hashp[N];


void build(string s, int n, string p, int m)
{
	// s和p可以共用一个pow 
	pow[0] = 1;
	for(int i = 1; i < N; i++){
		pow[i] = pow[i - 1] * base;
	}
	hashs[0] = s[0] - 'a' + 1;
	for(int i = 1; i < n; i++){
		hashs[i] = hashs[i - 1] * base + s[i] - 'a' + 1;
	}
	hashp[0] = p[0] - 'a' + 1;
	for(int i = 1; i < m; i++){
		hashp[i] = hashp[i - 1] * base + p[i] - 'a' + 1; 
	}
}

long getHash(long *hashed, int l, int r)
{
	long ans = hashed[r];
	if(l > 0){
		ans -= hashed[l - 1] * pow[r - l + 1];
	}
	return ans;
}

bool same(int l1, int l2, int len)
{
	return getHash(hashs, l1, l1 + len - 1) == getHash(hashp, l2, l2 + len - 1);
}

// s[l1...r1] 和 p[0...m-1] 取等长的两段
// 返回这两段上字符不一样的位置是不是<=k个
// p[0...m-1] 与下列函数中的m不是通过含义 
bool check(int l1, int r1, int k){
	int diff = 0;
	int l2 = 0;   // p的左边位置 
	
	
	// 此题的二分思想很重要
	while(l1 <= r1 && diff <= k){
		// l和r只是构造出来的二分位置，实际对应字符串的下标为 l+len 和 r+len 
		int l = 1;
		int r = r1 - l1 + 1;
		int m, len = 0;
		// 二分找到最左边的不同位置 
		while(l <= r){
			m = (l + r) / 2;
			if(same(l1, l2, m)){
				// 相同，则从len到m-1去二分 
				len = m;
				l = m + 1;
			}else{
				r = m - 1;
			}
		}
		if(l1 + len <= r1){
			// 说明 l1到len有一个不同 
			diff++;
		}
		// 从len+1位置开始继续比较 
		l1 += len + 1;
		l2 += len + 1;
	}
	return diff <= k;
}


// s中有多少子串修改最多k个位置的字符就可以变成p
// s长度为n，p长度为m，时间复杂度O(n * k * logm)
int compute(string s, string p, int k)
{
	int n = s.size();
	int m = p.size();
	if(n < m) return 0;
	build(s, n, p, m);
	int ans = 0;
	for(int i = 0; i <= n - m; i++){
		// s[i...i+m-1] -> m
		// p[0.....m-1]
		if(check(i, i + m - 1, k)){
			ans++;
		}
	}
	return ans;
}


int main()
{
	cin >> t;
	for(int i = 0; i< t; i++){
		string s,p;
		cin >> s >> p;
		cout << compute(s, p, 3) << endl;
	}
	return 0;
} 



 
