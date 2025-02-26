// ���������������ۼӺ�Ϊ����ֵ��������鳤��
// ����һ����������arr, ����Ԫ�ؿ������ɸ�����0
// ����һ������aim
// ��arr�������������ۼӺ�Ϊaim��������鳤��
// �������� : https://www.nowcoder.com/practice/36fb0fd3c656480c92b569258a1223d5

#include <bits/stdc++.h>
#include <map>
using namespace std;
const int MAXN = 1e5;
const int N = 1e9;
typedef long long ll;
int arr[MAXN];
int n, aim;

// ��������
int solve1() {
    int ans = 0;
    ll sum = 0;
    for (int l = 0, r = 0; r < n; r++) {
        sum += arr[r];
        if (sum > aim) {
            sum -= arr[l++];
        }
        if (sum == aim) {
            ans = max(ans, r - l + 1);
        }
    }
    return ans;
}

int solve2() {
    map<ll, int> m;
    m.insert({0, -1});
    int ans = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (m.find(sum - aim) != m.end()) {
            ans = max(ans, i - m[sum - aim]);
        }
        if (m.find(sum) == m.end()) {
            m.insert({sum, i});
        }
    }
    return ans;
}


// ���������� 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1000;
    while(t--){
    	n = 1 + rand() % MAXN;
	    aim = -N + rand() % (N * 2);
	//    cin >> n >> aim;
	    srand((unsigned)time(NULL));
	    
	    for (int i = 0; i < n; i++) {
	//        cin >> arr[i];
			arr[i] = -100 + rand() % 201;
	    }
	    int ans1 = solve1();
	    int ans2 = solve2();
	    cout << "��" << t << "��"; 
	    if(ans1 == ans2){
	    	cout << "������ȷ" << endl;
		}else{
			cout << "���Դ���" << endl;
		}
	}

    return 0;
}
