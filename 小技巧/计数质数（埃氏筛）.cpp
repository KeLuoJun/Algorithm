// 计数质数
// 给定整数n，返回小于非负整数n的质数的数量
// 测试链接 : https://leetcode.cn/problems/count-primes/
#include <bits/stdc++.h> 
using namespace std;


// 埃氏筛统计0 ~ n范围内的质数个数
// 时间复杂度O(n * log(logn))
int ehrlich(int n)
{
	// vis[i] = 1，代表i是合数
	// vis[i] = 0，代表i是质数
	// 初始时认为0~n所有数都是质数
	int vis[n + 1] = {0};  // 0 表示没访问过 
	for(int i = 2; i * i <= n; i++){
		if(!vis[i]){
			for(int j = i * i; j <= n; j += i){
				vis[j] = 1;
			}
		}
	}
	int cnt = 0;
	for(int i = 2; i <= n; i++){
		if(!vis[i]){
			// 此时i就是质数，可以收集，也可以计数
			//printf("%d ",i);
			cout << i << " ";
			cnt++;
		}
	}
	cout << endl;
	return cnt;
}


int main()
{
	int n;
	scanf("%d",&n);
	int ans = ehrlich(n);
	printf("%d",ans);
	return 0;
 } 
