// ���ƴ������
// �㽫�õ�һ���������� matchsticks
// ���� matchsticks[i] �ǵ� i?�������ĳ���
// ��Ҫ�� ���еĻ���?ƴ��һ��������
// �� �����۶� �κ�һ��������������԰���������һ�𣬶���ÿ���������� ʹ��һ��
// �������ƴ�������Σ��򷵻� true �����򷵻� false
// �������� : https://leetcode.cn/problems/matchsticks-to-square/

#include <iostream>
using namespace std;
const int MAXN = 20;
int n, sum = 0, maxx = 0; 
int lens[MAXN];


// limit : ÿ���߹涨�ĳ���
// status : ��ʾ��Щ���ֻ�����ѡ
// cur : ��ǰҪ������������Ѿ��γɵĳ���
// rest : һ�����м�����û�н��
// ���� : �ܷ��ù����л��ȥ���ʣ�µ����б�
// ��Ϊ�����ӹ���֮ǰ��һ����֤ÿ�����ۼ�������������limit
// ����status�Ǿ���cur��rest�ģ��ؼ��ɱ����ֻ��status
bool f(int limit, int status, int cur, int rest, int *dp)
{
	if(rest == 0)
		return status == 0; 
	if(dp[status] != 0)
		return dp[status] == 1;
	bool ans = false;
	for(int i = 0; i < n; i++){
		// ����ÿһ�����ֻ��ʹ��״̬Ϊ1�Ļ��
		if((status & (1 << i)) != 0 && cur + lens[i] <= limit){
			if(cur + lens[i] == limit){
			ans = f(limit, status ^ (1 << i), 0, rest - 1, dp);
			}
			else{
				ans = f(limit, status ^ (i << i), cur + lens[i], rest, dp);
			}
			if(ans)
				break;	
		} 
	}
	dp[status] = ans ? 1 : -1;
	return ans;
}


bool compute()
{
	if(sum % 4 != 0)
		return false;
	if(maxx > sum / 4)
		return false;
	int *dp = new int[1 << n];
	return f(sum / 4, (1 << n) - 1, 0, 4, dp);
	
	
}


int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> lens[i];
		sum += lens[i];
		maxx = max(maxx, lens[i]);
	}
	if(compute())
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
	
}
