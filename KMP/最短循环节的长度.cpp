// ���ѭ���ڵĳ���
// ����һ���ַ���s����һ������ĳ��ѭ���ڲ������������γɵ�
// ��Ŀ��֤�����ظ�2�Σ��������һ��ѭ���ڲ�һ������
// ������֪��s�����ѭ�����Ƕ೤
// �������� : https://www.luogu.com.cn/problem/P4391

#include <iostream>
using namespace std;
const int N = 1e6 + 1;
int n;
int nexts[N];
string s;

void getNextArray()
{
	nexts[0] = -1;
	nexts[1] = 0;
	int i = 2, cn = 0;
	while(i <= n){
		if(s[i - 1] == s[cn]){
			nexts[i++] = ++cn;
		}else if(cn > 0){
			cn = nexts[cn];
		}else{
			nexts[i++] = 0;
		}
	}
}

int compute()
{
	getNextArray();
	return n - nexts[n];
}

int main()
{
	cin >> n;
	cin >> s;
	cout << compute() << endl;
	return 0;
} 
