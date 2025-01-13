// 最长递增子序列字典序最小的结果
// 给定数组arr，设长度为n
// 输出arr的最长递增子序列
// 如果有多个答案，请输出其中字典序最小的
// 注意这道题的字典序设定（根据提交的结果推论的）：
// 每个数字看作是单独的字符，比如120认为比36的字典序大
// 保证从左到右每个数字尽量小
// 测试链接 : https://www.nowcoder.com/practice/30fb9b3cab9742ecae9acda1c75bf927
// 测试链接 : https://www.luogu.com.cn/problem/T386911


#include <iostream>
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 1;
int n,k;

int arr[MAXN];
int endss[MAXN];
int dp[MAXN];
int ans[MAXN];

// ends[有效区]从大到小的
// 二分的方式找<=num的最左位置
int bs(int len, int num)
{
	int l = 0, r = len - 1, ans = -1;
	while(l <= r){
		int m = l + ((r - l) >> 1);
		if(endss[m] <= num){
			ans = m;
			r = m - 1;
		}else{
			l = m + 1;
		}
	}
	return ans;
}

// dp[i] : 必须以i位置的数字开头的情况下，最长递增子序列长度
// 填好dp表 + 返回最长递增子序列长度
int f()
{
	int len = 0;
	for(int i = n - 1; i >= 0; i--){
		int find = bs(len, arr[i]);
		if(find == -1){
			endss[len++] = arr[i];
			dp[i] = len;
		}else{
			endss[find] = arr[i];
			dp[i] = find + 1;
		}
	}
	return len;
}


void lis()
{
	k = f();
	for(int i = 0; i <= k; i++){
		ans[i] = INT_MAX;
	}
	for(int i = 0; i < n; i++){
		if(dp[i] == k){
			// 注意这里
			// 为什么不用判断直接设置
			// 有讲究，课上重点讲了
			ans[0] = arr[i];
		}else{
			// 注意这里
			// 为什么只需要判断比前一位(ans[k-dp[i]-1])大即可
			// 有讲究，课上重点讲了
			if(ans[k - dp[i] - 1] < arr[i]){
				ans[k - dp[i]] = arr[i];
			}
		}
	}
	
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	lis();
	for(int i = 0; i < k; i++){
		cout << ans[i] << " ";
	}
	return 0;
}


