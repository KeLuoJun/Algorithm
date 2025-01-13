// ����Ӯ��
// ������������n��m
// ������ҿ��������ӹ����������г�ȡ��1��n�����������Żأ�
// ��ȡ���������ۼ�������������Ҷ��㣩
// ˭���Լ��Ļغ����ۼӺ� >= m��˭��ʤ
// ���ȳ��ֵ��������Ӯ�򷵻�true�����򷵻�false
// ������λ�����Ϸʱ����������������ȫ��Ϊ�Լ�����
// �������� : https://leetcode.cn/problems/can-i-win/

#include <iostream>
using namespace std;


// ���1~7��Χ�����ֶ���ѡ����ôstatus��״̬Ϊ��
// 1 1 1 1 1 1 1 1
// 7 6 5 4 3 2 1 0
// 0λ��������
// ���1~7��Χ�����֣�4��2�Ѿ�ѡ�˲�����ѡ����ôstatus��״̬Ϊ��
// 1 1 1 0 1 0 1 1
// 7 6 5 4 3 2 1 0
// 0λ��������
// f�ĺ��� :
// ���ַ�Χ1~n����ǰ�����֣����status����������״̬
// ���ۼӺͻ�ʣrest�������
// ���ص�ǰ�������ܲ���Ӯ����Ӯ����true������Ӯ����false

// ��Ϊ rest��ֵ������ststus������dp��ֻ��Ҫ���ó�һά 
bool f(int n, int status, int rest, int *dp)
{
	if(rest <= 0)
		return false;
	if(dp[status] != 0)
		return dp[status] == 1;
	bool ans = false;
	for(int i = 1; i <= n; i++){
		// �����������֣����ǲ���ѡ��֮ǰѡ�˵�����
		// ע���ж������е����ȼ� 
		if((status & (1 << i)) != 0 && !f(n, (status ^ (1 << i)), rest - i, dp)){
			ans = true;
			break;
		}
	}
	dp[status] = ans ? 1 : -1;
	return ans;
}

bool compute(int n, int m)
{
	if(m == 0)
		return true;
	// ���1~n����ȫ������
	// �ۼӺͺ���n * (n+1) / 2����С��m
	// ��ô������Ӯ�ң�Ҳ����ζ�����ֲ����ʤ
	if(n * (n + 1) / 2 < m)
		return false;
	// dp[status] == 0 ����û���
	// dp[status] == 1 ���������true
	// dp[status] == -1 ���������false
	 
	int *dp = new int[1 << (n + 1)];
	return f(n, (1 << (n + 1) - 1), m , dp);
}


int main()
{
	int n, m;
	cin >> n >> m;
	if(compute(n, m))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
 } 
