// ��¸����
// ��ʼʱ���������0�����Ŀ���Ǵ�0�Ź��޿�ʼ��ͨ�����е�nֻ����
// ����㵱ǰ������С��i�Ź��޵�����������븶��b[i]��Ǯ��¸�������
// Ȼ����޾ͻ�����㣬��������a[i]ֱ���ۼӵ����������
// ����㵱ǰ���������ڵ���i�Ź��޵������������ѡ��ֱ��ͨ���������������½�
// ������Ȼ����ѡ���¸������ޣ�Ȼ����޵�����ֱ���ۼӵ����������
// ����ͨ�����еĹ��ޣ���Ҫ������СǮ��
// �������� : https://www.nowcoder.com/practice/736e12861f9746ab8ae064d4aae2d5a9

// ���Ȿ���Ŀ�Ĳ�������Ϊ��ͨ������⣬���ǽ������µ�˼��:
// ����a[i]��ֵ�ķ�Χ�ܴ󣬵���b[i]��ֵ�ķ�Χ���󣬸���ô����
// ����a[i]��ֵ�ķ�Χ���󣬵���b[i]��ֵ�ķ�Χ�ܴ��ָ���ô����

#include <iostream>
using namespace std;
const int MAXN = 501;
int n;
int a[MAXN];  // ��ʾ���޵����� 
int b[MAXN];  // ��ʾ��Ҫ�Ľ�Ǯ 

// ����a[i]��ֵ�ķ�Χ�ܴ󣬵���b[i]��ֵ�ķ�Χ����
// ʱ�临�Ӷ�O(n * ���й��޵�Ǯ���ۼӺ�)
int compute1()
{
	int m = 0;
	for(int i = 1; i <= n; i++){
		m += b[i];
	}
	// dp[i][j] : ����Ǯ���ܳ���j��ͨ��ǰi�����ޣ���������Ƕ���
	// ���dp[i][j] == Integer.MIN_VALUE
	// ��ʾ����Ǯ���ܳ���j��������ζ��޷�ͨ��ǰi������
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

// ���Ƿ���1�Ŀռ�ѹ���汾
int compute2()
{
	int m = 0;
	for(int i = 1; i <= n; i++){
		m += b[i];
	}
	int dp[m + 1] = {0};
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= 0; j--){
			// j �ķ�Χ���� m ~ b[i]
			// ��Ϊ <b[i] �ĸ���ҲҪ����,����򲻹�Ҫ������INT_MIN 
			int cur = INT_MIN;  // ����ͨ�Ŀռ�ѹ����һ�������� 
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


// ����a[i]��ֵ�ķ�Χ���󣬵���b[i]��ֵ�ķ�Χ�ܴ�
// ʱ�临�Ӷ�O(n * ���й��޵������ۼӺ�)
int compute3()
{
	int m = 0;
	for(int i = 1; i <= n; i++){
		m += a[i];
	}
	// dp[i][j] : ����������j������ȷ����ͨ��ǰi�����ޣ���Ҫ���ٻ�����Ǯ
	// ���dp[i][j] == Integer.MAX_VALUE
	// ��ʾ����������j��������ζ��޷�ͨ��ǰi������
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

// ���Ƿ���3�Ŀռ�ѹ���汾
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
