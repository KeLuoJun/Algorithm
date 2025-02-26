// ��ȡ��ˮ����С����
// �ϰ���Ҫ���æ���������� N ��ˮ�����꣬y ��ʾˮ�εĸ߶ȣ�x ��ʾ�����䵽 x ���λ��
// ÿ��ˮ��ÿ��1����λ���ȵ��ٶ����䡣����Ҫ�ѻ������ x ���ϵ�ĳ��λ��
// ʹ�ôӱ�������ŵĵ� 1 ��ˮ��ʼ������������ŵ���� 1 ��ˮ������֮���ʱ�������Ϊ D
// ������Ϊ��ֻҪˮ���䵽 x ���ϣ��뻨��ı��ض��룬����Ϊ����ס
// ���� N ��ˮ������� D �Ĵ�С���������С�Ļ���Ŀ�� W
// �������� : https://www.luogu.com.cn/problem/P2698

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

// ��ǰ���� ���ֵ - ��Сֵ �ǲ���>=d
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
	// arr[0...n-1][2]: x(0), �߶�(1)
	// ����ˮ�θ���x����˭С˭��ǰ
	sort(arr.begin(), arr.end());
	maxh = maxt = minh = mint = 0;
	int ans = INT_MAX;
	for(int l = 0, r = 0; l < n; l++){
		// [l,r) : ˮ�εı��
		// l : ��ǰ���̵���߽磬arr[l][0]
		while(!ok() && r < n){
			push(r++);
		}
		// ������Ŀ�����Ͳ��������� 
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
