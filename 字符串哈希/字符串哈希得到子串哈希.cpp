// 字符串哈希得到子串哈希
// 利用字符串哈希的便利性替代KMP算法
// 测试链接 : https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/

#include <iostream>
#include <string>
using namespace std;
const int base = 499;
const int N = 100005;
long pow[N];     // 每一位对应base的多少次方 
long hashs[N];   // 字符串 0-i 对应的哈希值 


// 如下代码是字符串哈希的原理和模版
// 比如，base = 499, 也就是课上说的选择的质数进制
// 再比如字符串s如下
// " c a b e f "
//   0 1 2 3 4
// hash[0] = 3 * base的0次方
// hash[1] = 3 * base的1次方 + 1 * base的0次方
// hash[2] = 3 * base的2次方 + 1 * base的1次方 + 2 * base的0次方
// hash[3] = 3 * base的3次方 + 1 * base的2次方 + 2 * base的1次方 + 5 * base的0次方
// hash[4] = 3 * base的4次方 + 1 * base的3次方 + 2 * base的2次方 + 5 * base的1次方 + 6 *
// base的0次方
// hash[i] = hash[i-1] * base + s[i] - 'a' + 1，就是上面说的意思
// 想计算子串"be"的哈希值 -> 2 * base的1次方 + 5 * base的0次方
// 子串"be"的哈希值 = hash[3] - hash[1] * base的2次方(子串"be"的长度次方)
// hash[1] = 3 * base的1次方 + 1 * base的0次方
// hash[1] * base的2次方 = 3 * base的3次方 + 1 * base的2次方
// hash[3] = 3 * base的3次方 + 1 * base的2次方 + 2 * base的1次方 + 5 * base的0次方
// hash[3] - hash[1] * base的2次方 = 2 * base的1次方 + 5 * base的0次方
// 这样就得到子串"be"的哈希值了
// 子串s[l...r]的哈希值 = hash[r] - hash[l-1] * base的(r-l+1)次方，就是上面说的意思
void build(string s, int n)
{
	pow[0] = 1;
	for(int i = 1; i < n; i++){
		pow[i] = pow[i - 1] * base;
	}
	hashs[0] = s[0] - 'a' + 1;
	for(int i  = 1; i < n; i++){
		hashs[i] = hashs[i - 1] * base + s[i] - 'a' + 1;
	}
}

long getHash(int l, int r)
{
	long ans = hashs[r];
	if(l > 0){
		ans -= hashs[l - 1] * pow[r - l + 1];
	}
	return ans;
}


int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.size();
	int m = s2.size();
	build(s1, n);
	long h2 = s2[0] - 'a' + 1;  // h2 为s2的哈希值 
	for(int i = 1; i < m; i++){
		h2 = h2 * base + s2[i] - 'a' + 1;
	}
	// 滑动窗口 
	int ans = -1;
	for(int l = 0, r = m - 1; r < n; l++, r++){
		if(getHash(l, r) == h2){
			ans = l;
			break;
		}
	}
	cout << ans << endl;
	return 0;
 } 
