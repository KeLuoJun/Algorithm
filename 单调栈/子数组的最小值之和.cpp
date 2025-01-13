// ���������Сֵ֮��
// ����һ���������� arr���ҵ� min(b) ���ܺͣ����� b �ķ�ΧΪ arr ��ÿ���������������顣
// ���ڴ𰸿��ܴܺ���� ���ش�ģ 10^9 + 7
// �������� : https://leetcode.cn/problems/sum-of-subarray-minimums/

#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5;
const int mod = 1e9 + 7;

int sumSubarrayMins(vector<int>& arr) 
{
    int n = arr.size();
    vector<int> stack(n);
    int r = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
    	// ��ͬҲѹ�룬������ֵĻ��ǰ��©��� 
        while(r > 0 && arr[stack[r - 1]] >= arr[i]){
            int cur = stack[--r];
            int left = r == 0 ? -1 : stack[r - 1];
            ans = (ans + (long long)(cur - left) * (i - cur) * arr[cur]) % mod;
        }
        stack[r++] = i;
    }
    while(r > 0){
        int cur = stack[--r];
        int left = r == 0 ? -1 : stack[r - 1];
        ans = (ans + (long long)(cur - left) * (n - cur) * arr[cur]) % mod;
    }
    return ans;
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int ans = sumSubarrayMins(arr);
	cout << ans << endl;
	return 0;
} 
