// ��״ͼ�����ľ���
// ���� n ���Ǹ�������������ʾ��״ͼ�и������ӵĸ߶�
// ÿ�����ӱ˴����ڣ��ҿ��Ϊ 1 �����ڸ���״ͼ�У��ܹ����ճ����ľ��ε�������
// �������ӣ�https://leetcode.cn/problems/largest-rectangle-in-histogram

#include <iostream>
#include <vector>
using namespace std; 

// �൱����һ����ÿ���������������Լ�����ұ��Լ�С��λ�� 
int largestRectangleArea(vector<int>& heights) 
{
    int n = heights.size();
    vector<int> stack(n);   // ��ѹС 
    int r = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
    	// ��ͬҲѹ�룬������ͬ�������ֲ�ǰ��Ĵ��� 
    	//  ...1....3........3..2..
		//     ------              ǰ����ͬ�����ֳ��ִ��� 
		//     -----------------   ������ͬ��λ���ֲ��˴��� 
        while(r > 0 && heights[stack[r - 1]] >= heights[i]){
            int cur = stack[--r];
            int left = r == 0 ? -1 : stack[r - 1];
            ans = max(ans, (i - left - 1) * heights[cur]);
        }
        stack[r++] = i;
    }
    while(r > 0){
        int cur = stack[--r];
        int left = r == 0 ? -1 : stack[r - 1];
        ans = max(ans, (n - left - 1) * heights[cur]);
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
	int ans = largestRectangleArea(arr);
	cout << ans << endl;
	return 0;
}
