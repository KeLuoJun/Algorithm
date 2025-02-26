// ����ֻռһ�������������
// �������ɻ���Ŀ�ʼ������ʱ��
// �κλ�����ٿ��ڼ䣬��ֻ��Ҫ���1�����μ�
// �����㰲�ŵ���һ�죬ֻ�ܲμ�������飬����ͬʱ�μ���������
// �������ܲμӵ�����������
// �������� : https://leetcode.cn/problems/maximum-number-of-events-that-can-be-attended/

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
	// С���ѣ�����Ľ���ʱ��  
	priority_queue<int, vector<int>, greater<int>> heap; 
	int ans = 0, i = 0;
	for(int day = minn; day <= maxx; day++){
		// �����е��쿪ʼ�Ļ���������
		while(i < n && events[i][0] == day){
			heap.push(events[i++][1]);
		}
		// �Ƴ������Ѿ������Ļ���  
		while(!heap.empty() && heap.top() < day){
			heap.pop();
		}
		// ����Ѳ�Ϊ�գ��Ƴ���������Ļ��鲢����  
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
