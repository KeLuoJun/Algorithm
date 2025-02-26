// 潜水的最大时间与方案
// 一共有n个工具，每个工具都有自己的重量a、阻力b、提升的停留时间c
// 因为背包有限，所以只能背重量不超过m的工具
// 因为力气有限，所以只能背阻力不超过v的工具
// 希望能在水下停留的时间最久
// 返回最久的停留时间和下标字典序最小的选择工具的方案
// 注意这道题的字典序设定（根据提交的结果推论的）：
// 下标方案整体构成的字符串保证字典序最小
// 比如下标方案"1 120"比下标方案"1 2"字典序小
// 测试链接 : https://www.luogu.com.cn/problem/P1759

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
