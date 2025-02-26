// ��������
// ����һ���� '1'��½�أ��� '0'��ˮ����ɵĵĶ�ά����������������е��������
// �������Ǳ�ˮ��Χ������ÿ������ֻ����ˮƽ�����/����ֱ���������ڵ�½�������γ�
// ���⣬����Լ��������������߾���ˮ��Χ
// �������� : https://leetcode.cn/problems/number-of-islands/


#include <iostream>
using namespace std;
const int MAXN = 301;
int (*board)[MAXN] = new int[MAXN][MAXN];
int n,m;

void dfs(int i, int j)
{
	if(i < 0 || i == n || j < 0 || j == m || board[i][j] != 1)
		return;
	board[i][j] = 0;
	dfs(i, j - 1);
	dfs(i, j + 1);
	dfs(i - 1, j);
	dfs(i + 1, j);
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cin >> board[i][j];
	}
	int islands = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(board[i][j] == 1){
				islands++;
				dfs(i, j);
			}
		}
	}
	cout << islands << endl;
	return 0;
} 
