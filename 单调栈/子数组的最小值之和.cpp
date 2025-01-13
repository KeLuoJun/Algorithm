// 子数组的最小值之和
// 给定一个整数数组 arr，找到 min(b) 的总和，其中 b 的范围为 arr 的每个（连续）子数组。
// 由于答案可能很大，因此 返回答案模 10^9 + 7
// 测试链接 : https://leetcode.cn/problems/sum-of-subarray-minimums/

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
    	// 相同也压入，后面出现的会填补前面漏算的 
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
