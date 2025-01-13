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
int dp[MAXN][MAXN][MAXN];
string path[MAXN][MAXN][MAXN];


void build()
{
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			for(int k = 0; k <= v; k++){
				dp[i][j][k] = 0;
				path[i][j][k] = "";
			}
		}
	}
}

// ��ͨ�汾�Ķ�ά���ñ���
// Ϊ�˺ö���ʵ�ֲ����пռ�ѹ���İ汾
void compute()
{
	string p2;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= m; j++){
			for(int k = 0; k <= v; k++){
				// ������1 : ��Ҫiλ�õĻ�
				// �Ȱѿ�����1�Ĵ�������
				// ����dp��Ϣ��path��Ϣ
				dp[i][j][k] = dp[i - 1][j][k];
				path[i][j][k] = path[i - 1][j][k];
				if(j >= a[i] && k >= b[i]){
				// ������2 : Ҫiλ�õĻ�
				// ��ô��Ҫ:
				// ��������������j >= a[i]
				// ��������������k >= b[i]
				// Ȼ��ѡ��iλ�õĻ����Ϳ��Ի������c[i]��
				// ������2���� : dp[i-1][j-a[i]][k-b[i]] + c[i]
				// ������2·��(p2) : path[i-1][j-a[i]][k-b[i]] + " " + i
					if(path[i - 1][j - a[i]][k - b[i]] == ""){
						p2 = to_string(i);
					}else{
						p2 = path[i - 1][j - a[i]][k - b[i]] + " " + to_string(i);
					}
					
					if(dp[i][j][k] < dp[i - 1][j - a[i]][k - b[i]] + c[i]){
						dp[i][j][k] = dp[i - 1][j - a[i]][k - b[i]] + c[i];
						path[i][j][k] = p2;
					}else if(dp[i][j][k] == dp[i - 1][j - a[i]][k - b[i]] + c[i]){
						if(p2.compare(path[i][j][k]) < 0){
							// ���������2��·�����ֵ���С�ڣ�������1��·��
							// ��ô��·�����óɿ�����2��·��
							path[i][j][k] = p2;
						}
					}
				}
			}
		}
	}
}




int main()
{
	cin >> m >> v >> n;
	for(int i  =1; i <= n; i++){
		cin >> a[i] >> b[i] >> c[i];
	}
	build();
	compute();
	cout << dp[n][m][v] << endl;
	cout << path[n][m][v] << endl;
	return 0;
	
}
