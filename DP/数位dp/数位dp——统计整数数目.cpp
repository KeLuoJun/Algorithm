// ͳ��������Ŀ
// �������������ַ��� num1 �� num2 ���Լ���������max_sum��min_sum
// ���һ������ x �����������������ǳ�����һ��������
// num1 <= x <= num2
// min_sum <= digit_sum(x) <= max_sum
// ���㷵�غ���������Ŀ
// �𰸿��ܴܺ��뷵�ش𰸶�10^9 + 7 ȡ���Ľ��
// ע�⣬digit_sum(x)��ʾx��λ����֮��
// �������� : https://leetcode.cn/problems/count-of-integers/

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


// ע�⣺
// ���֣�char[] num
// ���ֳ��ȣ�int len
// �ۼӺ���СҪ��int min
// �ۼӺ����Ҫ��int max
// ���ĸ���������ȫ�־�̬���������Բ��ô�������ֱ�ӷ��ʼ���
// �ݹ麬�壺
// ��num�ĸ�λ��������ǰ����iλ��
// ֮ǰ�����������ۼӺ���sum
// ֮ǰ�ľ����Ѿ���numС��������������ѡ�����֣���ôfree == 1
// ֮ǰ�ľ�����numһ������������������ѡ�����֣���ôfree == 0
// �����ж����ֿ�����
int f(string num, int i, int sum, int free)
{
	if(sum > max_num)
		return 0;
	// �����ǰ�ĺͼ��Ϻ���ÿ��λ�ö���9�ĺͺ���С��min��
	// �������ÿ��λ���ϵ����ֵĺͲ����ܴ���min 
	if(sum + (len - 1) * 9 < min_num)
		return 0;
	if(i == len)
		return 1;
	if(dp[i][sum][free] != -1)
		return dp[i][sum][free];
	int ans = 0;
	int cur = num[i] - '0';
	if(free == 0){
	// ����������ѡ��
		for(int k = 0;  k < cur; k++){
			ans = (ans + f(num, i + 1, sum + k, 1)) % MOD;
			
		}
		ans = (ans + f(num, i + 1, sum + cur, 0)) % MOD;
	}else{
		// ��������ѡ��
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
