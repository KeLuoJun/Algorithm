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

// 普通版本的多维费用背包
// 为了好懂先实现不进行空间压缩的版本
void compute()
{
	string p2;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= m; j++){
			for(int k = 0; k <= v; k++){
				// 可能性1 : 不要i位置的货
				// 先把可能性1的答案设置上
				// 包括dp信息和path信息
				dp[i][j][k] = dp[i - 1][j][k];
				path[i][j][k] = path[i - 1][j][k];
				if(j >= a[i] && k >= b[i]){
				// 可能性2 : 要i位置的货
				// 那么需要:
				// 背包总重量限制j >= a[i]
				// 背包总阻力限制k >= b[i]
				// 然后选了i位置的货，就可以获得收益c[i]了
				// 可能性2收益 : dp[i-1][j-a[i]][k-b[i]] + c[i]
				// 可能性2路径(p2) : path[i-1][j-a[i]][k-b[i]] + " " + i
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
							// 如果可能性2的路径，字典序小于，可能性1的路径
							// 那么把路径设置成可能性2的路径
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
