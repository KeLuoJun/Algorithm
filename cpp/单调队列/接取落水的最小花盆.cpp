// 接取落水的最小花盆
// 老板需要你帮忙浇花。给出 N 滴水的坐标，y 表示水滴的高度，x 表示它下落到 x 轴的位置
// 每滴水以每秒1个单位长度的速度下落。你需要把花盆放在 x 轴上的某个位置
// 使得从被花盆接着的第 1 滴水开始，到被花盆接着的最后 1 滴水结束，之间的时间差至少为 D
// 我们认为，只要水滴落到 x 轴上，与花盆的边沿对齐，就认为被接住
// 给出 N 滴水的坐标和 D 的大小，请算出最小的花盆的宽度 W
// 测试链接 : https://www.luogu.com.cn/problem/P2698

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e5 + 1;
int n,d;
vector<vector<int>> arr;
int maxdq[N];
int mindq[N];
int maxh, maxt, minh, mint;

// 当前窗口 最大值 - 最小值 是不是>=d
bool ok()
{
	int maxnum = maxh < maxt ? arr[maxdq[maxh]][1] : 0;
	int minnum = minh < mint ? arr[mindq[minh]][1] : 0;
	return maxnum - minnum >= d;
}

void push(int r)
{
	while(maxh < maxt && arr[maxdq[maxt - 1]][1] <= arr[r][1]){
		maxt--;
	}
	maxdq[maxt++] = r;
	while(minh < mint && arr[mindq[mint - 1]][1] >= arr[r][1]){
		mint--;
	}
	mindq[mint++] = r;
}

void pop(int l)
{
	if(maxh < maxt && maxdq[maxh] == l){
		maxh++;
	}
	if(minh < mint && mindq[minh] == l){
		minh++;
	}
}

int compute()
{
	// arr[0...n-1][2]: x(0), 高度(1)
	// 所有水滴根据x排序，谁小谁在前
	sort(arr.begin(), arr.end());
	maxh = maxt = minh = mint = 0;
	int ans = INT_MAX;
	for(int l = 0, r = 0; l < n; l++){
		// [l,r) : 水滴的编号
		// l : 当前花盘的左边界，arr[l][0]
		while(!ok() && r < n){
			push(r++);
		}
		// 可能题目根本就不可能满足 
		if(ok()){
			ans = min(ans, arr[r - 1][0] - arr[l][0]);
		}
		pop(l);
	}
	return ans;
}


int main()
{
	cin >> n >> d;
	for(int i = 0; i < n; i++){
		vector<int> tmp;
		int num;
		for(int j = 0; j < 2; j++){
			cin >> num;
			tmp.push_back(num);
		}
		arr.push_back(tmp);
	}
	int ans = compute();
	if(ans == INT_MAX) cout << "-1" << endl;
	else cout << ans << endl;
	return 0;
}
