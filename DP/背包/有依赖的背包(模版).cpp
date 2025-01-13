// �������ı���(ģ��)
// ��Ʒ��Ϊ�����ࣺ�����͸���
// �����Ĺ���û�����ƣ�Ǯ���Ϳ��ԣ������Ĺ��������ƣ��ø����������������ȹ��򣬲��ܹ����������
// ���磬�������ӡ����ɨ���������ĸ����������ȹ�������������
// ������һЩ�������丽����չʾ��
// ���ԣ���ӡ����ɨ���� | ���ͼ�� | ������̨�ƣ��ľ� | �����Σ��޸���
// ÿ�����������2�����������Ҹ����������и����������������ôȥѡ�����������ȫ���⣬Ǯ���Ϳ���
// ���е���Ʒ��Ŷ���1~m֮�䣬ÿ����Ʒ��������Ϣ���۸�v����Ҫ��p������q
// �۸���ǻ��ѣ��۸� * ��Ҫ�� �������棬�������Ǹ���Ʒ���������ĸ���ŵ�����
// ����һ����Ʒ��ϢΪ[300,2,6]������300������600������Ʒ��6��������Ʒ�ĸ���
// �ٱ���һ����Ʒ��Ϣ[100,4,0]������100������400������Ʒ����������(q==0)
// ����m����Ʒ����Ϣ��������Ǯ��n�������ڲ�Υ�����������������������
// �������� : https://www.luogu.com.cn/problem/P1064
// �������� : https://www.nowcoder.com/practice/f9c6f980eeec43ef85be20755ddbeaf4

#include <iostream> 
using namespace std;
#include <algorithm>
const int MAXN = 33001;
const int MAXM = 61;
int n,m;
int *cost = new int[MAXM];
int *val = new int[MAXM];
bool *king = new bool[MAXM];  // ��ǰ��Ʒ�Ƿ�Ϊ���� ��Ϊtrue������Ϊfalse 
int fans[MAXM] = {0};  //������������Ʒ������ 
int (*follows)[2] = new int[MAXM][2]; //��������������Ʒ�ı�� 

void clean()
{
	for(int i = 0; i <= m; i++)
		fans[i] = 0;
}

int compute1()
{
	int (*dp)[MAXN] = new int[MAXM][MAXN];
	// dp[0][....] = 0 : ����Ʒ��ʱ��
	for(int j = 0; j <= n ;j++) dp[0][j] = 0;
	for(int i = 0; i <= m; i++) dp[i][0] = 0;
	// p : �ϴ�չ��������Ʒ���  �ܹؼ��������������� 
	int p = 0;
	for(int i = 1, fan1, fan2; i <= m ; i++)
	{
		if(king[i])
		{
			// dp[i][j] : 0...i��Χ�ϣ�ֻ��������Ʒ�����ҽ���չ��
			//            ���Ѳ�����j������£���õ��������
			for(int j = 0; j <= n; j++)
			{ 
				// ������1�������ǵ�ǰ��Ʒ
				dp[i][j] = dp[p][j];
				// ������2��ֻ���ǵ�ǰ��Ʒ 
				if(j - cost[i] >= 0)
					dp[i][j] = max(dp[i][j], dp[p][j - cost[i]] + val[i]);
				// fan1 : ����и�1��Ʒ����Ÿ�fan1�����û�У�fan1 == -1
				// fan2 : ����и�2��Ʒ����Ÿ�fan2�����û�У�fan2 == -1
				fan1 = fans[i] >= 1 ? follows[i][0] : -1;
				fan2 = fans[i] >= 2 ? follows[i][1] : -1;
				// ������3 : �� + ��1
				if(fan1 != -1 && j - cost[i] - cost[fan1] >= 0)
					dp[i][j] = max(dp[i][j], dp[p][j - cost[i] - cost[fan1]] + val[i] + val[fan1]);
				// ������4 : �� + ��2
				if(fan2 != -1 && j - cost[i] - cost[fan2] >= 0)
					dp[i][j] = max(dp[i][j], dp[p][j - cost[i] - cost[fan2]] + val[i] + val[fan2]);
				// ������5 : �� + ��1 + ��2
				if(fan1 != -1 && fan2 != -1 && j - cost[i] - cost[fan1] - cost[fan2] >=0)
					dp[i][j] = max(dp[i][j], dp[p][j - cost[i] - cost[fan1] - cost[fan2]] + val[i] + val[fan1] + val[fan2]);
			}
			p = i;
		}
	}
	return dp[p][n];
}


// �ռ�ѹ��
int compute2()
{
	int *dp = new int[MAXN];
	for(int i = 0; i <= n; i++) dp[i] = 0;
	//����Ҫ p 
	for(int i = 1, fan1, fan2; i <= m; i++)
	{
		if(king[i])
		{
			for(int j = n; j >= 0; j--)
			{
				if(j - cost[i] >= 0)
					dp[j] = max(dp[j], dp[j - cost[i]] + val[i]);
				fan1 = fans[i] >= 1 ? follows[i][0] : -1;
				fan2 = fans[i] >= 2 ? follows[i][1] : -1;
				if(fan1 != -1 && j - cost[i] - cost[fan1] >= 0)
					dp[j] = max(dp[j], dp[j - cost[i] - cost[fan1]] + val[i] + val[fan1]);
				if(fan2 != -1 && j - cost[i] - cost[fan2] >= 0)
					dp[j] = max(dp[j], dp[j - cost[i] - cost[fan2]] + val[i] + val[fan2]);
				if(fan1 != -1 && fan2 != -1 && j - cost[i] - cost[fan1] - cost[fan2] >= 0)
					dp[j] = max(dp[j], dp[j - cost[i] - cost[fan1] - cost[fan2]] + val[i] + val[fan1] + val[fan2]);
			}
		}
	}
	return dp[n];
}



int main()
{
	cin >> n >> m;
	int v, p, q;
	clean();
	for(int i = 1; i <= m; i++)
	{
		cin >> v >> p >> q;
		//���ת���ܹؼ������� 
		val[i] = v * p;
		cost[i] = v;
		king[i] = (q == 0);
		if(q != 0)
			follows[q][fans[q]++] = i;
	}
	int ans1 = compute1();
	int ans2 = compute2();
	
	cout << ans1 << endl;
	cout << ans2 << endl;
	return 0;
}
