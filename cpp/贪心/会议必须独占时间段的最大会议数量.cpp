// 会议必须独占时间段的最大会议数量
// 给定若干会议的开始、结束时间
// 你参加某个会议的期间，不能参加其他会议
// 返回你能参加的最大会议数量
// 来自真实大厂笔试，没有在线测试，对数器验证

#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e6;
int n;
struct meeting
{
	int starts;
	int ends;
};

bool cmp(meeting a, meeting b)
{
	return a.ends <= b.ends;
}

void swap(meeting *&meetings, int i, int j)
{
	meeting tmp = meetings[i];
	meetings[i] = meetings[j];
	meetings[j] = tmp;
}

int f(meeting *meetings, int i)
{
	int ans = 0;
	if(i == n){
		for(int j = 0, cur = -1; j < n; j++){
			if(cur <= meetings[j].starts){
				ans++;
				cur = meetings[j].ends;
			}
		}
	}else{
		for(int j = i; j < n; j++){
			swap(meetings, i, j);
			ans = max(ans, f(meetings, i + 1));
			swap(meetings, i, j);
		}
	}
	return ans;
}
// 纯暴力方法 
int maxValue1(meeting *meetings)
{
	return f(meetings, 0);
}


int maxMeeting2(meeting *meetings)
{
	sort(meetings, meetings + n, cmp);
	int ans = 0;
	for(int i = 0, cur = -1; i < n; i++){
		if(cur <= meetings[i].starts){
			ans++;
			cur = meetings[i].ends;
		}
	}
	return ans;
}

int main()
{
	cin >> n;
	meeting meetings[n];
	for(int i = 0; i < n; i++){
		cin >> meetings[i].starts >> meetings[i].ends;  
	}
	cout << maxValue1(meetings) << endl;
	cout << maxMeeting2(meetings) << endl;
	return 0;
}
