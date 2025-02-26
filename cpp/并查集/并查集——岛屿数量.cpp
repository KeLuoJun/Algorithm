// ��������
// ����һ���� '1'��½�أ��� '0'��ˮ����ɵĵĶ�ά����������������е��������
// �������Ǳ�ˮ��Χ������ÿ������ֻ����ˮƽ�����/����ֱ���������ڵ�½�������γ�
// ���⣬����Լ��������������߾���ˮ��Χ
// �������� : https://leetcode.cn/problems/number-of-islands/

#include <iostream>
using namespace std;
const int MAXN = 10001;
int *father = new int[MAXN];
int sets;
int n,m;


// ��ά����ת��Ϊһά���� 
int index(int a, int b)
{
	return a * m + b;
}


// ����ÿ��1��ͬ���±�ֵ 
void build(int board[][MAXN])
{
	sets = 0;
	int pos;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(board[i][j] == 1){
				pos = index(i, j);
				father[pos] = pos;
				sets++;
			}
		}
	}
}

int find(int i)
{
	if(i != father[i]){
		father[i] = find(father[i]);
	}
	return father[i];
}


void unions(int a, int b, int c, int d)
{
	int fx = find(index(a, b));
	int fy = find(index(c, d));
	if(fx != fy){
		father[fx] = fy;
		sets--;
	}
}


int main()
{
	cin >> n >> m;
	int (*board)[MAXN] = new int[n][MAXN];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> board[i][j];
	build(board);
	 for(int i = 0; i < n; i++){
	 	for(int j = 0; j < m; j++){
	 		if(board[i][j] == 1){
	 			if(j > 0 && board[i][j - 1] == 1){
	 				unions(i, j, i, j - 1);
				 }
				if(i > 0 && board[i - 1][j] == 1){
					unions(i, j, i - 1, j);
				}
			 }
		}
	 }
	cout << sets << endl;
	return 0;
} 
