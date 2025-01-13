// 贿赂怪兽
// 开始时你的能力是0，你的目标是从0号怪兽开始，通过所有的n只怪兽
// 如果你当前的能力小于i号怪兽的能力，则必须付出b[i]的钱贿赂这个怪兽
// 然后怪兽就会加入你，他的能力a[i]直接累加到你的能力上
// 如果你当前的能力大于等于i号怪兽的能力，你可以选择直接通过，且能力不会下降
// 但你依然可以选择贿赂这个怪兽，然后怪兽的能力直接累加到你的能力上
// 返回通过所有的怪兽，需要花的最小钱数
// 测试链接 : https://www.nowcoder.com/practice/736e12861f9746ab8ae064d4aae2d5a9

// 讲解本题的目的不仅仅是为了通过这个题，而是进行如下的思考:
// 假设a[i]数值的范围很大，但是b[i]数值的范围不大，该怎么做？
// 假设a[i]数值的范围不大，但是b[i]数值的范围很大，又该怎么做？

#include <iostream>
using namespace std;
const int MAXN = 501;
int n;
int a[MAXN];  // 表示怪兽的力量 
int b[MAXN];  // 表示需要的金钱 

// 假设a[i]数值的范围很大，但是b[i]数值的范围不大
// 时间复杂度O(n * 所有怪兽的钱数累加和)
int compute1()
{
	int m = 0;
	for(int i = 1; i <= n; i++){
		m += b[i];
	}
	// dp[i][j] : 花的钱不能超过j，通过前i个怪兽，最大能力是多少
	// 如果dp[i][j] == Integer.MIN_VALUE
	// 表示花的钱不能超过j，无论如何都无法通过前i个怪兽
	int dp[n + 1][m + 1];
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			dp[i][j] = 0;
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= m; j++){
			dp[i][j] = INT_MIN;
			if(dp[i - 1][j] >= a[i]){
				dp[i][j] = dp[i - 1][j];
			}
			if(j - b[i] >= 0 && dp[i - 1][j - b[i]] != INT_MIN){
				dp[i][j] = max(dp[i][j], dp[i - 1][j - b[i]] + a[i]);
			}
		}
	}
	int ans = -1;
	for(int j = 0; j <= m; j++){
		if(dp[n][j] != INT_MIN){
			ans = j;
			break;
		}
	}
	return ans;
}

// 就是方法1的空间压缩版本
int compute2()
{
	int m = 0;
	for(int i = 1; i <= n; i++){
		m += b[i];
	}
	int dp[m + 1] = {0};
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= 0; j--){
			// j 的范围不是 m ~ b[i]
			// 因为 <b[i] 的格子也要操作,如果打不过要给他赋INT_MIN 
			int cur = INT_MIN;  // 跟普通的空间压缩有一定的区别 
			if(dp[j] >= a[i])
				cur = dp[j];
			if(j - b[i] >= 0 && dp[j - b[i]] != INT_MIN){
				cur = max(cur, dp[j - b[i]] + a[i]);
			}
			dp[j] = cur;
		}
	}
	int ans = -1;
	for(int j = 0; j <= m; j++){
		if(dp[j] != INT_MIN){
			ans = j;
			break;
		}
	}
	return ans;
}


// 假设a[i]数值的范围不大，但是b[i]数值的范围很大
// 时间复杂度O(n * 所有怪兽的能力累加和)
int compute3()
{
	int m = 0;
	for(int i = 1; i <= n; i++){
		m += a[i];
	}
	// dp[i][j] : 能力正好是j，并且确保能通过前i个怪兽，需要至少花多少钱
	// 如果dp[i][j] == Integer.MAX_VALUE
	// 表示能力正好是j，无论如何都无法通过前i个怪兽
	int dp[n + 1][m + 1];
	dp[0][0] = 0;
	for(int j = 1; j <= m; j++){
		dp[0][j] = INT_MAX;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= m; j++){
			dp[i][j] = INT_MAX;
			if(j >= a[i] && dp[i - 1][j] != INT_MAX){
				dp[i][j] = dp[i - 1][j];
			}
			if(j - a[i] >= 0 && dp[i - 1][j - a[i]] != INT_MAX){
				dp[i][j] = min(dp[i][j], dp[i - 1][j - a[i]] + b[i]);
			}
		}
	}
	int ans = INT_MAX;
	for(int j = 0; j <= m; j++){
		ans = min(ans, dp[n][j]);
	}
	return ans;
}

// 就是方法3的空间压缩版本
int compute4()
{
	int m = 0;
	for(int i = 1; i <= n; i++){
		m += a[i];
	}
	int dp[m + 1];
	dp[0] = 0;
	for(int j = 1; j <= m; j++){
		dp[j] = INT_MAX;
	}
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= 0; j--){
			int cur = INT_MAX;
			if(j - a[i] >= 0 && dp[j] != INT_MAX){
				cur = dp[j];
			}
			if(j - a[i] >= 0 && dp[j - a[i]] != INT_MAX){
				cur = min(cur, dp[j - a[i]] + b[i]);
			}
			dp[j] = cur;
		}
		int ans = INT_MAX;
		for(int j = 0; j <= m; j++){
			ans = min(ans, dp[j]);
		}
		return ans;
	}
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> b[i];
	}
	
	cout << compute4() << endl;
	return 0;
} 
