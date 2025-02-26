// Ǳˮ�����ʱ���뷽��
// һ����n�����ߣ�ÿ�����߶����Լ�������a������b��������ͣ��ʱ��c
// ��Ϊ�������ޣ�����ֻ�ܱ�����������m�Ĺ���
// ��Ϊ�������ޣ�����ֻ�ܱ�����������v�Ĺ���
// ϣ������ˮ��ͣ����ʱ�����
// ������õ�ͣ��ʱ����±��ֵ�����С��ѡ�񹤾ߵķ���
// ע���������ֵ����趨�������ύ�Ľ�����۵ģ���
// �±귽�����幹�ɵ��ַ�����֤�ֵ�����С
// �����±귽��"1 120"���±귽��"1 2"�ֵ���С
// �������� : https://www.luogu.com.cn/problem/P1759

#include <iostream>
#include <string>
using namespace std;
const int MAXN = 101;
int n,m,v;
int a[MAXN], b[MAXN], c[MAXN]; 
int dp[MAXN][MAXN];
string path[MAXN][MAXN];


void build()
{
	for(int i = 0; i <= m; i++){
		for(int j = 0; j <= v; j++){
			dp[i][j] = 0;
			path[i][j] = "";
		}
	}
}

void compute()
{
	string p2;
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= a[i]; j--){
			for(int k = v; k >= b[i]; k--){
				if(path[j - a[i]][k - b[i]] == ""){
					p2 = to_string(i);
				}else{
					p2 = path[j - a[i]][k - b[i]] + " " + to_string(i);
				}
				
				if(dp[j][k] < dp[j - a[i]][k - b[i]] + c[i]){
					dp[j][k] =  dp[j - a[i]][k - b[i]] + c[i];
					path[j][k] = p2;
				}else if(dp[j][k] ==  dp[j - a[i]][k - b[i]] + c[i]){
					if(p2.compare(path[j][k]) < 0)
						path[j][k] = p2;
				}
			}
		}
	}
}


int main()
{
	cin >> m >> v >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> b[i] >> c[i];
	}
	build();
	compute();
	cout << dp[m][v] << endl;
	cout << path[m][v] << endl;
	return 0;
	
}
