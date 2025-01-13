// 每日温度
// 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer
// 其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后
// 如果气温在这之后都不会升高，请在该位置用 0 来代替。
// 测试链接 : https://leetcode.cn/problems/daily-temperatures/

#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5;
vector<int> nums(N);

vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        int *stack = new int[n];  // 小压大 
        int r = 0;
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
        	// 相同也压入 
            while(r > 0 && temperatures[stack[r - 1]] < temperatures[i]){
                int cur = stack[--r];
                ans[cur] = i - cur;
            }
            stack[r++] = i;
        }
        return ans;
}

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> nums[i];
	}
	vector<int> ans = dailyTemperatures(nums);
	for(int i = 0; i < n; i++){
		cout << ans[i] << " ";
	}
	return 0;
}
