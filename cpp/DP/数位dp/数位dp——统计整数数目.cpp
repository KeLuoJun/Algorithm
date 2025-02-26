// 统计整数数目
// 给你两个数字字符串 num1 和 num2 ，以及两个整数max_sum和min_sum
// 如果一个整数 x 满足以下条件，我们称它是一个好整数
// num1 <= x <= num2
// min_sum <= digit_sum(x) <= max_sum
// 请你返回好整数的数目
// 答案可能很大请返回答案对10^9 + 7 取余后的结果
// 注意，digit_sum(x)表示x各位数字之和
// 测试链接 : https://leetcode.cn/problems/count-of-integers/

#include <iostream>
#include <string>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 23;
const int MAXM = 401;
int dp[MAXN][MAXM][2];
string num1, num2;
int min_num, max_num;
int len;

void build()
{
	for(int i = 0; i <= len; i++){
		for(int j = 0; j <= max_num; j++){
			dp[i][j][0] = -1;
			dp[i][j][1] = -1;
		}		
	}
}


// 注意：
// 数字，char[] num
// 数字长度，int len
// 累加和最小要求，int min
// 累加和最大要求，int max
// 这四个变量都是全局静态变量，所以不用带参数，直接访问即可
// 递归含义：
// 从num的高位出发，当前来到i位上
// 之前决定的数字累加和是sum
// 之前的决定已经比num小，后续可以自由选择数字，那么free == 1
// 之前的决定和num一样，后续不可以自由选择数字，那么free == 0
// 返回有多少种可能性
int f(string num, int i, int sum, int free)
{
	if(sum > max_num)
		return 0;
	// 如果当前的和加上后面每个位置都是9的和后还是小于min，
	// 则这个数每个位置上的数字的和不可能大于min 
	if(sum + (len - 1) * 9 < min_num)
		return 0;
	if(i == len)
		return 1;
	if(dp[i][sum][free] != -1)
		return dp[i][sum][free];
	int ans = 0;
	int cur = num[i] - '0';
	if(free == 0){
	// 还不能自由选择
		for(int k = 0;  k < cur; k++){
			ans = (ans + f(num, i + 1, sum + k, 1)) % MOD;
			
		}
		ans = (ans + f(num, i + 1, sum + cur, 0)) % MOD;
	}else{
		// 可以自由选择
		for(int k = 0; k <= 9; k++){
			ans = (ans + f(num, i + 1, sum + k, 1)) % MOD;
		}
	}
	dp[i][sum][free] = ans;
	return ans;
}

bool check()
{
	int sum = 0;
	int m = num1.size();
	for(int i = 0; i < m; i++){
		sum += num1[i] - '0';
	}
	return sum >= min_num && sum <= max_num;
}

int compute()
{
	len = num2.size();
	build();
	int ans = f(num2, 0, 0, 0);
	len = num1.size();
	build();
	ans = (ans - f(num1, 0, 0, 0) + MOD) % MOD;
	if(check()){
		ans = (ans + 1) % MOD;
	} 
	return ans;
}


int main()
{
	cin >> num1 >> num2;
	cin >> min_num >> max_num;
	cout << compute() << endl;
	return 0;
} 
