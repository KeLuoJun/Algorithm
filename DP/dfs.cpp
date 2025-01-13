#include <iostream>
using namespace std;
const int MAXN = 21;
int n;
int w[MAXN];
int nexts[MAXN][MAXN];
int ans[MAXN],path[MAXN],maxx = 0,cnt = 0;
int vis[MAXN] = {0};

//检查是否还能继续往下挖
bool check(int x)
{
	for(int i = 1; i <= n; i++){
		if(nexts[x][i] && !vis[i])
			return false;
	}
	return true;
	
}

void dfs(int x, int stp, int sum)
{
	if(check(x)){
		if(sum > maxx){
			maxx = sum;
			cnt = stp;
			for(int i = 1; i <= stp; i++)
				ans[i] = path[i];
		}
		return;
	}
	
	
	for(int i = 1; i <= n; i++){
		if(nexts[x][i] && !vis[i]){
			vis[i] = 1;
			path[stp + 1] = i;
			dfs(i, stp + 1, sum + w[i]);
			vis[i] = 0;
		}
	}
}


int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)	
		cin >> w[i];
	for(int i = 1; i <= n; i++)	
		for(int j = i + 1; j <= n; j++)
			cin >> nexts[i][j];
	
	for(int i = 1; i <= n; i++){
		vis[i] = 1;
		path[1] = i;
		dfs(i, 1, w[i]);
		vis[i] = 0;
	}
	for(int i = 1; i <= cnt; i++)
		cout << ans[i] << " ";
	cout << endl;
	cout << maxx;
	return 0;
	
}
