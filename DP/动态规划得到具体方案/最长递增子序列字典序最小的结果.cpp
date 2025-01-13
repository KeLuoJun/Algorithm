// ������������ֵ�����С�Ľ��
// ��������arr���賤��Ϊn
// ���arr�������������
// ����ж���𰸣�����������ֵ�����С��
// ע���������ֵ����趨�������ύ�Ľ�����۵ģ���
// ÿ�����ֿ����ǵ������ַ�������120��Ϊ��36���ֵ����
// ��֤������ÿ�����־���С
// �������� : https://www.nowcoder.com/practice/30fb9b3cab9742ecae9acda1c75bf927
// �������� : https://www.luogu.com.cn/problem/T386911


#include <iostream>
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 1;
int n,k;

int arr[MAXN];
int endss[MAXN];
int dp[MAXN];
int ans[MAXN];

// ends[��Ч��]�Ӵ�С��
// ���ֵķ�ʽ��<=num������λ��
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

// dp[i] : ������iλ�õ����ֿ�ͷ������£�����������г���
// ���dp�� + ��������������г���
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
			// ע������
			// Ϊʲô�����ж�ֱ������
			// �н����������ص㽲��
			ans[0] = arr[i];
		}else{
			// ע������
			// Ϊʲôֻ��Ҫ�жϱ�ǰһλ(ans[k-dp[i]-1])�󼴿�
			// �н����������ص㽲��
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


