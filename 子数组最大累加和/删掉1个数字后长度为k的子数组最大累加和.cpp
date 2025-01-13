// 删掉1个数字后长度为k的子数组最大累加和
// 给定一个数组nums，求必须删除一个数字后的新数组中
// 长度为k的子数组最大累加和，删除哪个数字随意
// 对数器验证
// （有点小问题） 

#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
const int N = 1e5;
int n, k;
int arr[N];

void Delete(int *num, int index)
{
	int i = 0;
	for(int j = 0; j < n; j++){
		if(j != index){
			num[i++] = arr[j];
		}
	}
}

int lenKmaxSum(int *num)
{
	int ans = INT_MIN;
	int sum = 0;
	for(int i = 0; i < n - 1; i++){
		sum += num[i];
		if(i >= k - 1){
			ans = max(ans, sum);
			sum -= num[i - k + 1];
		}
	}
	return ans;
}

// 暴力方法
// 为了测试
// 枚举每一个子数组找到最大累加和
int maxSum1()
{
	if(n <= k) return 0;
	int ans = INT_MIN;
	for(int i = 0; i < n; i++){
		int *num = new int[n];
		Delete(num, i);
		ans = max(ans, lenKmaxSum(num));
		delete[] num;
	} 
	return ans;
}





// 正式方法
// 时间复杂度O(N)
// 求出长度为 k+1 的子数组的累加和，再减去其中的最小值（用单调队列） 
int maxSum2()
{
	if(n <= k) return 0;
	// 单调队列 : 维持窗口内最小值的更新结构，讲解054的内容
	int *window = new int[n + 1];
	int l = 0, r = 0;
	// 窗口累加和
	int sum = 0;
	int ans = INT_MIN;
	for(int i = 0; i < n; i++){
		// 单调队列 
		// 小压大 
		while(l < r && arr[window[r - 1]] >= arr[i]){
			r--;
		}
		window[r++] = i;   // 存储的是下标 
		sum += arr[i];
		if(i >= k){
			ans = max(ans, sum - arr[window[l]]);
			if(window[l] == i - k){
				// 单调队列 : 如果单调队列最左侧的位置过期了，从队列中弹出
				l++;
			}
			sum -= arr[i - k];
		}
	}
	delete[] window;
	return ans;
}

// 对数器 
int main()
{
	int testTime = 10000;
	srand((unsigned)time(NULL));
	cout << "测试开始" << endl;
	for(int i = 0; i < testTime; i++){
		n = rand() % 15;
		k = rand() % n;
		for(int j = 0; j < n; j++){
			arr[j] = rand() % 100;
		}
		int ans1 = maxSum1();
		int ans2 = maxSum2();
		cout << ans1 << " " << ans2 << endl;
		if(ans1 != ans2){
			cout << "出错了" << endl; 
		}
	}
	cout << "测试结束" << endl;
	return 0;
}
 
