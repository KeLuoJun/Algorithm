// windy��
// ����ǰ������������������֮������Ϊ2������������Ϊwindy��
// windy��֪��[a,b]��Χ���ܹ��ж��ٸ�windy��
// �������� : https://www.luogu.com.cn/problem/P2657

#include <iostream>
using namespace std;
const int MAXN = 11;
int a,b;
int dp[MAXN][MAXN][2];

void build(int len)
{
	for(int i = 0; i <= len; i++){
		for(int j = 0; j <= 10; j++){
			dp[i][j][0] = -1;
			dp[i][j][1] = -1;
		}
	}
} 

// offset��ȫ��len������Ϊ�˷�����ȡnum��ĳһλ���֣��Ͻڿ����ݣ�
// ��num�ĸ�λ��ʼ����ʣ��lenλû�о���
// ǰһλ��������pre�����pre == 10����ʾ����û��ѡ�������
// ���֮ǰ��λ�Ѿ�ȷ����numС����ôfree == 1����ʾ���µ����ֿ�������ѡ��
// ���֮ǰ��λ��numһ������ôfree == 0����ʾ���µ����ֲ��ܴ���num��ǰλ������
// ����<=num��windy���ж��ٸ�
int f(int num, int offset, int len, int pre, int free)
{
	if(len == 0)
		return 1;
	if(dp[len][pre][free] != -1)
		return dp[len][pre][free];
	int cur = num / offset % 10;
	int ans = 0;
	if(free == 0){
		if(pre == 10){
			// ֮ǰ��λ��numһ������ʱ��������ѡ������
			// Ҳ����û��ѡ�������
			// �ͱ�ʾ����������num�����λ
			ans += f(num, offset / 10, len - 1, 10, 1); //һ������Ҳ��Ҫ
			for(int i = 1; i < cur; i++){
				ans += f(num, offset / 10, len - 1, i, 1);
			}
			ans += f(num, offset / 10, len - 1, cur, 0);
		}
		else{
			// ֮ǰ��λ��numһ������ʱ��������ѡ�����֣�
			// ֮ǰѡ�������pre
			for(int i = 0; i <= 9; i++){
				if(i <= pre - 2 || i >= pre + 2){
					if(i < cur && i >= 0){
						ans += f(num, offset / 10, len - 1, i, 1);
					}
					else{
						if(i == cur){
							ans += f(num, offset / 10, len - 1, cur, 0);
						}
					}
				}
			}
		}
	}
	else{
		if(pre == 10){
			// free == 1����������ѡ�����֣�ǰ���״�� < num
			// ����û��ѡ�������
			ans += f(num, offset / 10, len - 1, 10, 1); // ���ǿ��Բ�ѡ������
			for(int i = 1; i <= 9; i++){
				ans += f(num, offset / 10, len - 1, i, 1);
			}
		}
		else{
			// free == 1����������ѡ�����֣�ǰ���״�� < num
			// ѡ�������pre
			for(int i = 0; i <= 9; i++){
				if(i <= pre - 2 || i >= pre + 2){
					ans += f(num, offset / 10, len - 1, i, 1);
				}
			}
		}
	}
	dp[len][pre][free] = ans;
	return ans;
}




int cnt(int num)
{
	if(num == 0)
		return 1;
	int len = 1;
	int offset = 1;
	int tmp = num / 10;
	while(tmp > 0){
		len++;
		offset *= 10;
		tmp /= 10;
	}
	build(len);
	return f(num, offset, len, 10, 0);
}




int compute(int a, int b)
{
	return cnt(b) - cnt(a - 1);
}


int main()
{
	cin >> a >> b;
	cout << compute(a, b) << endl;
	return 0;
}
