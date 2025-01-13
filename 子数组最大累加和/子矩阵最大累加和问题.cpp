// �Ӿ�������ۼӺ�����
// ����һ����ά����grid���ҵ������Ӿ��������ۼӺ�
// ����ӵ������ۼӺ͵��Ӿ������ϽǺ����½�����
// ����ж���Ӿ���������ۼӺͣ�������һ��������
// �������� : https://leetcode.cn/problems/max-submatrix-lcci/

#include <iostream>
using namespace std;
const int MAXN = 201;
int (*nums)[MAXN] = new int[MAXN][MAXN];
int n,m;
int a = 0,b = 0,c = 0,d = 0;

void fill(int *&dp, int m)
{
	for(int i = 0; i < m; i++)	
		dp[i] = 0;
}

// ����к��еĹ�ģ����n��ʱ�临�Ӷ�O(n^3)�����Ž���
void getMaxMatrix()
{
	int *dp = new int[m];
	int maxsum = INT_MIN;
	for(int up = 0; up < n; up++){
		fill(dp, m);   // ˢ��dp��ֵ 
		// ���� 0-0 0-1 0-2 .... 0-n-1
		// 1-1 1-2 .... 1-n-1
		// ........
		// n-n 
		for(int down = up; down < n; down++){
			// ���´��������Ŀ1�ĸ������� :
			// ���������ҵ�ӵ������ۼӺ͵�������
			for(int l = 0, r = 0, pre = INT_MIN; r < m; r++){
				dp[r] += nums[down][r];
				if(pre >= 0)
					pre += dp[r];
				else{
					pre = dp[r];
					l = r;
				}
				if(pre > maxsum){
					maxsum = pre;
					a = up;
					b = l;
					c = down;
					d = r;
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cin >> nums[i][j];
	}
	getMaxMatrix();
	cout << a << " " << b << " " << c << " " << d << endl;
	return 0;
} 
