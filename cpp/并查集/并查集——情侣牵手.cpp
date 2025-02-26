// ����ǣ��
// n�����������������е� 2n ����λ�ϣ���Ҫǣ���Է�����
// �˺���λ��һ���������� row ��ʾ������ row[i] �����ڵ� i ����λ�ϵ��˵�ID
// �����ǰ�˳���ţ���һ���� (0, 1)���ڶ����� (2, 3)���Դ����ƣ����һ���� (2n-2, 2n-1)
// ���� ���ٽ�����λ�Ĵ������Ա�ÿ�����¿��Բ�������һ��
// ÿ�ν�����ѡ���������ˣ�������վ����������λ
// �������� : https://leetcode.cn/problems/couples-holding-hands/

#include <iostream>
using namespace std;

const int MAXN = 10001;
int *father = new int[MAXN];
int *row = new int[MAXN];
int sets = 0;   // ��ʾ��ļ��ϵ����� 
int n;

void build(int m)
{
	for(int i = 0; i < m; i++){
		father[i] = i;
	}
	sets = m; 
}

int find(int i)
{
	if(i != father[i]){
		father[i] = find(father[i]);
	}
	return father[i];
}

void unions(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if(fx != fy){
		father[fx] = fy;
		sets--;
	}
}

int main()
{
	cin >> n;
	int m = n / 2;   // �ж����� 
	for(int i = 0; i < n; i++)
		cin >> row[i];
	build(m);
	for(int i = 0; i < n; i += 2){
		unions(row[i] / 2, row[i + 1] / 2);
	}
	cout << n / 2 - sets << endl;  // �ؼ����
	// ���ٽ����� ���� �����ϼ�ȥ1����� 
	// �ȼ��� �ܵ�������ȥ���ϵ����� 
	return 0;
} 
