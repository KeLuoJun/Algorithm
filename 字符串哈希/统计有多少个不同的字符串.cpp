// 统计有多少个不同的字符串
// 测试链接 : https://www.luogu.com.cn/problem/P3370

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int N = 10001;
const int base = 499;
long nums[N];   // 用 long长度，让其自然移除，相当于 %long 的结果 
int n;

// 得到字符所对应的数字 
// 数字 + 大写 + 小写
// '0' -> 1
// '1' -> 2
// ...
// '9' -> 10
// 'A' -> 11
// 'B' -> 12
// ...
// 'Z' -> 36
// 'a' -> 37
// ...
// 'z' -> 62
int v(char c)
{
	// 注意字符对应的编码起始值不能是0 
	if(c >= '0' && c <= '9'){
		return c - '0' + 1;
	}else if(c >= 'A' && c <= 'Z'){
		return c - 'A' + 11;
	}else{
		return c - 'a' + 37;
	}
}


// 主要函数 
// 得到字符串的哈希值 
long value(string s)
{
	long ans = v(s[0]);
	for(int i = 1; i < s.size(); i++){
		ans = ans * base + v(s[i]);
	}
	return ans;
}

// 根据字符串的哈希值判断是否有重复的字符串 
int cnt()
{
	sort(nums, nums + n);
	int ans = 1;
	for(int i = 1; i < n; i++){
		if(nums[i] != nums[i - 1]){
			ans++;
		}
	}
	return ans;
} 


int main()
{
	cin >> n;
	string s;
	for(int i = 0; i < n; i++){
		cin >> s;
		nums[i] = value(s);
	}
	int ans = cnt();
	cout << ans << endl;
	return 0;
}
