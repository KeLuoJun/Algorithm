// �߿�Ϊ1�����������
// ����һ�������� 0 �� 1 ��ɵĶ�ά���� grid
// �����ҳ��߽�ȫ���� 1 ��ɵ���� ������ ������
// �����ظ��������е�Ԫ����������������ڣ��򷵻� 0��
// �������� : https://leetcode.cn/problems/largest-1-bordered-square/

#include <iostream>
using namespace std;
#define MAXN 10000

int g[MAXN][MAXN];
int n,m;

int get(int i, int j) {
	return (i < 0 || j < 0) ? 0 : g[i][j];
}


void build() {
	//��(0,0) �� (i,j) ��ǰ׺�� 
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		//�����ϽǼ����ϽǼ����ص��Ĳ��� 
			g[i][j] += get(i,j-1) + get(i-1,j) - get(i-1,j-1);
}

// (a,b) �� (c,d) ��ǰ׺��
int sum(int a,int b,int c,int d) {
	// ���Ͻ� �ܵ� ���½ǵĺ��� 
	return a > c ? 0 : g[c][d] - get(c,b-1) - get(a-1,d) + get(a-1,b-1);
}


int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> g[i][j];
	build();
	if(g[n-1][m-1] == 0) return 0;

	int ans = 1;
	for(int a = 0; a < n; a++) {
		for(int b = 0; b < m; b++) {
			//a b Ϊ���Ͻǵĵ�
			//k Ϊ�߳� ansΪĿǰ�����߳� 
			for(int c = a + ans,d = b + ans,k = ans + 1; c < n && d < m; c++,d++,k++)
					if(sum(a,b,c,d) - sum(a+1,b+1,c-1,d-1) == (k - 1) * 4)
						ans = k;
			}
	}
	cout << ans * ans << endl;
	return 0;
}
