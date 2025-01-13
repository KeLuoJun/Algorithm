// 会议只占一天的最大会议数量
// 给定若干会议的开始、结束时间
// 任何会议的召开期间，你只需要抽出1天来参加
// 但是你安排的那一天，只能参加这个会议，不能同时参加其他会议
// 返回你能参加的最大会议数量
// 测试链接 : https://leetcode.cn/problems/maximum-number-of-events-that-can-be-attended/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 1e6;
int n;
vector<vector<int>>events;

bool cmp(vector<int>a, vector<int>b)
{
	return a[0] <= b[0];
}

int maxEvents()
{
	int minn = events[0][0];
	int maxx = events[0][1];
	for(int i = 0; i < n; i++){
		maxx = max(maxx, events[i][1]);
	}
	// 小根堆：会议的结束时间  
	priority_queue<int, vector<int>, greater<int>> heap; 
	int ans = 0, i = 0;
	for(int day = minn; day <= maxx; day++){
		// 将所有当天开始的会议加入堆中
		while(i < n && events[i][0] == day){
			heap.push(events[i++][1]);
		}
		// 移除所有已经结束的会议  
		while(!heap.empty() && heap.top() < day){
			heap.pop();
		}
		// 如果堆不为空，移除最早结束的会议并计数  
		if(!heap.empty()){
			heap.pop();
			ans++;
		}
	}
	return ans;
}

int main()
{
	cin >> n;
	int a,b;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		vector<int>v;
		v.push_back(a);
		v.push_back(b);
		events.push_back(v);
	}
	sort(events.begin(), events.end(), cmp);
	cout << maxEvents() << endl;
	return 0;
	
}
