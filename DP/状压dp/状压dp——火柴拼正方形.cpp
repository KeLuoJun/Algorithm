// 火柴拼正方形
// 你将得到一个整数数组 matchsticks
// 其中 matchsticks[i] 是第 i?个火柴棒的长度
// 你要用 所有的火柴棍?拼成一个正方形
// 你 不能折断 任何一根火柴棒，但你可以把它们连在一起，而且每根火柴棒必须 使用一次
// 如果你能拼出正方形，则返回 true ，否则返回 false
// 测试链接 : https://leetcode.cn/problems/matchsticks-to-square/

#include <iostream>
using namespace std;
const int MAXN = 20;
int n, sum = 0, maxx = 0; 
int lens[MAXN];


// limit : 每条边规定的长度
// status : 表示哪些数字还可以选
// cur : 当前要解决的这条边已经形成的长度
// rest : 一共还有几条边没有解决
// 返回 : 能否用光所有火柴去解决剩下的所有边
// 因为调用子过程之前，一定保证每条边累加起来都不超过limit
// 所以status是决定cur和rest的，关键可变参数只有status
bool f(int limit, int status, int cur, int rest, int *dp)
{
	if(rest == 0)
		return status == 0; 
	if(dp[status] != 0)
		return dp[status] == 1;
	bool ans = false;
	for(int i = 0; i < n; i++){
		// 考察每一根火柴，只能使用状态为1的火柴
		if((status & (1 << i)) != 0 && cur + lens[i] <= limit){
			if(cur + lens[i] == limit){
			ans = f(limit, status ^ (1 << i), 0, rest - 1, dp);
			}
			else{
				ans = f(limit, status ^ (i << i), cur + lens[i], rest, dp);
			}
			if(ans)
				break;	
		} 
	}
	dp[status] = ans ? 1 : -1;
	return ans;
}


bool compute()
{
	if(sum % 4 != 0)
		return false;
	if(maxx > sum / 4)
		return false;
	int *dp = new int[1 << n];
	return f(sum / 4, (1 << n) - 1, 0, 4, dp);
	
	
}


int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> lens[i];
		sum += lens[i];
		maxx = max(maxx, lens[i]);
	}
	if(compute())
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
	
}
