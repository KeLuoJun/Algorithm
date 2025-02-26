// 最小的必要团队
// 作为项目经理，你规划了一份需求的技能清单req_skills
// 并打算从备选人员名单people中选出些人组成必要团队
// 编号为i的备选人员people[i]含有一份该备选人员掌握的技能列表
// 所谓必要团队，就是在这个团队中
// 对于所需求的技能列表req_skills中列出的每项技能，团队中至少有一名成员已经掌握
// 请你返回规模最小的必要团队，团队成员用人员编号表示
// 你可以按 任意顺序 返回答案，题目数据保证答案存在
// 测试链接 : https://leetcode.cn/problems/smallest-sufficient-team/

#include <iostream>
#include <map>
using namespace std;
const int MAXN = 17;
const int MAXM = 61;
string skills;
int n, m;
int num[MAXM];
int arr[MAXN];
map<string, int> mm;

// arr : 每个人所掌握的必要技能的状态
// m : 人的总数
// n : 必要技能的数量
// i : 当前来到第几号人
// s : 必要技能覆盖的状态
// 返回 : i....这些人，把必要技能都凑齐，至少需要几个人
int f(int *arr, int i, int s, int (*dp)[MAXM])
{
	if(s == (1 << n) - 1)
	// 所有技能已经凑齐了
		return 0;
	// 没凑齐
	if(i == n)
	// 人已经没了，技能也没凑齐
	// 无效
		return INT_MAX;
	if(dp[i][s] != -1)
		return dp[i][s];
	// 可能性1 : 不要i号人
	int p1 = f(arr, i + 1, s, dp);
	// 可能性2 : 要i号人
	int p2 = INT_MAX;
	int next2 = f(arr, i + 1, s | arr[i], dp);
	if(next2 != INT_MAX){
		// 后续有效
		p2 = 1 + next2;
	}
	int ans = min(p1, p2);
	dp[i][s] = ans;
	return ans;
}

int main()
{
	cout << "请输入所需技能的数量:";
	cin >> n;
	cout << "请输入所需技能:" ; 
	for(int i = 0; i < n; i++){
		// 把所有必要技能依次编号
		cin >> skills;
		mm.insert(make_pair(skills, i));
	}
	cout << "请输入人的数量:" ;
	cin >> m;
	// arr[i] : 第i号人掌握必要技能的状况，用位信息表示
	for(int i = 0; i < m; i++){
		cout << "请输入第" << i + 1 << "号人所会的技能数:"; 
		cin >> num[i];
		string s;
		int status = 0;
		cout << "请输入第" << i + 1 << "号人所会的技能:"; 
		for(int j = 0; j < num[i]; j++){
			cin >> s;
			// 如果当前技能是必要的
			// 才设置status
			if(mm.find(s) != mm.end()){
				status |= 1 << mm[s];
			}
		}
		arr[i] = status;
	}
	int dp[m][MAXM];
	for(int i = 0; i < m; i++){
		for(int j = 0; j <= (1 << n); j++){
			dp[i][j] = -1;
		}
	}
	int size = f(arr, 0, 0, dp);
	for(int i = 0, j = 0, s = 0; s != (1 << n) - 1; i++){
		// s 表示还没凑齐
		if(i == m - 1 || dp[i][s] != dp[i + 1][s]){
			// 当初的决策是选择了i号人
			cout << i << " ";
			j++;
			s |= arr[i];
		}
	}
	return 0;
}
