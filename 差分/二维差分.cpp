#include <iostream>
using namespace std;
#define MAXN 10000

int arr[MAXN][MAXN];
// help 多准备一圈0 减少边界值的判断 
// help 为差分数组 
int help[MAXN+1][MAXN+1] = {0};
int row,cow;

void add(int a,int b,int c,int d,int num)
{
	help[a][b] += num;
	help[a][d+1] -= num;
	help[c+1][b] -= num;
	help[c+1][d+1] += num; 
}

void build()
{
	//help 数组做一次前缀和即可得到修改后的数值变化 
	for(int i = 1; i <= row; i++)
		for(int j = 1; j <= cow; j++)
			help[i][j] += help[i-1][j] + help[i][j-1] - help[i-1][j-1];
			
	//还原原数组
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < cow; j++)
		{
			arr[i][j] += help[i+1][j+1];
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
		
			 
}

void clear()
{
	for(int i = 1; i <= row; i++)
		for(int j = 1; j <= cow; j++)
			help[i][j] = 0;
}


int main()
{
	int m;
	cin >> row >> cow >> m;
	for(int i = 0; i < row; i++)
		for(int j = 0; j < cow; j++)
			cin >> arr[i][j];
	
	int a,b,c,d,num;
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> c >> d >> num;
		add(a,b,c,d,num);
	}
	build();
	clear();
	return 0;
} 
