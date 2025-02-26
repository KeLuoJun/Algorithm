// ����԰��ŵ����������Ŀ
// ���� n ������� m �����ˡ�ÿ��������Ҫһ��������ֵ�������
// ��Ҫ������ֵ�������±�� 0 ��ʼ���������� tasks �У�
// ��i��������Ҫ tasks[i] �������������
// ÿ�����˵�����ֵ�������±�� 0 ��ʼ����������workers�У�
// ��j�����˵�����ֵΪ workers[j]
// ÿ������ֻ�����һ������������ֵ��Ҫ���ڵ��ڸ����������Ҫ��ֵ����workers[j]>=tasks[i]
// �������⣬�㻹�� pills ������ҩ�裬���Ը� һ�����˵�����ֵ ���� strength
// ����Ծ�������Щ����ʹ��ҩ�裬��ÿ������ ��� ֻ��ʹ�� һƬ ҩ��
// �����±�� 0 ��ʼ����������tasks �� workers �Լ��������� pills �� strength
// ���㷵�� ��� �ж��ٸ�������Ա���ɡ�
// �������� : https://leetcode.cn/problems/maximum-number-of-tasks-you-can-assign/

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e4 * 5;
int n, m, pills, strength;
// n == tasks.length
// m = workers.length
int tasks[N], workers[N];
int dq[N];
int h, t;

// ������������ : O(n * logn) + O(m * logm)
// ���ִ𰸵Ĺ��̣�ÿ�ζ��ֶ���һ��˫�˶��� : O((n��m��Сֵ)*log(n��m��Сֵ))
// ��ӵķ���������Ĺ����ˣ�����ʱ�临�Ӷ�O(n * logn) + O(m * logm)

// tasks[tl....tr]��Ҫ������С�ļ�������
// workers[wl....wr]����ֵ���ļ�������
// ҩЧ��s��һ���е�ҩpills��
// ��ҩ��������������£��ܲ���ÿ�����˶���һ������
bool f(int tl, int tr, int wl, int wr)
{
	h = t = 0;
	int cnt = 0;  // �Ѿ�ʹ�õ�ҩ������
	for(int i = wl, j = tl; i <= wr; i++){
		// i : ���˵ı��
		// j : ����ı��
		for(; j <= tr && tasks[j] <= workers[i]; j++){
			// ���˲���ҩ������£�ȥ��������
			dq[t++] = j;
		}
		if(h < t && tasks[dq[h]] <= workers[i]){
			h++;
		}else{
			// ��ҩ֮����߼�
			for(; j <= tr && tasks[j] <= workers[i] + strength; j++){
				dq[t++] = j;
			}
			if(h < t){
				cnt++;
				t--;
			}else{
				// ��ҩ֮�󻹲��������������������Ĺ���
				// ��������˲����ܻᱻ��������
				// ��˲��������� wl �� wr �Ĺ��˶��������� 
				return false;
			}
		}
	}
	return cnt <= pills;
}

int maxTaskAssign()
{
	sort(tasks, tasks + n);
	sort(workers, workers + m);
	int ans = 0;
	int l = 0, r = min(n, m);
	// [0, Math.min(tsize, wsize)]
	while(l <= r){
		int mid = l + ((r - l) >> 1);
		// m�е㣬һ��Ҫ��ɵ���������
		if(f(0, mid - 1, m - mid, m - 1)){
			ans = mid;
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	return ans;
}



int main()
{
	cin >> n >> m >> pills >> strength;
	for(int i = 0; i < n; i++){
		cin >> tasks[i];
	}
	for(int i = 0; i < m; i++){
		cin >> workers[i];
	} 
	int ans = maxTaskAssign();
	cout << ans << endl;
	return 0; 
	
 } 
