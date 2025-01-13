// ÿ���¶�
// ����һ���������� temperatures ����ʾÿ����¶ȣ�����һ������ answer
// ���� answer[i] ��ָ���ڵ� i �죬��һ�������¶ȳ����ڼ����
// �����������֮�󶼲������ߣ����ڸ�λ���� 0 �����档
// �������� : https://leetcode.cn/problems/daily-temperatures/

#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5;
vector<int> nums(N);

vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        int *stack = new int[n];  // Сѹ�� 
        int r = 0;
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
        	// ��ͬҲѹ�� 
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
