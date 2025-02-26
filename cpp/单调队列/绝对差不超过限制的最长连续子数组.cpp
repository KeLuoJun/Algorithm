// 绝对差不超过限制的最长连续子数组
// 给你一个整数数组 nums ，和一个表示限制的整数 limit
// 请你返回最长连续子数组的长度
// 该子数组中的任意两个元素之间的绝对差必须小于或者等于 limit
// 如果不存在满足条件的子数组，则返回 0
// 测试链接 : https://leetcode.cn/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

#include <iostream>
using namespace std;
const int N = 100001;
int n, limit;
int arr[N];
// 窗口内最大值的更新结构（单调队列）
int maxdq[N];
// 窗口内最小值的更新结构（单调队列）
int mindq[N];
int maxh, maxt, minh, mint;


// 判断如果加入数字number，窗口最大值 - 窗口最小值是否依然 <= limit
// 依然 <= limit，返回true
// 不再 <= limit，返回false
bool ok(int num)
{
	// maxnum : 如果number进来，新窗口的最大值
	int maxnum = maxh < maxt ? max(arr[maxdq[maxh]], num) : num;
	// minnum : 如果number进来，新窗口的最小值
	int minnum = minh < mint ? min(arr[mindq[minh]], num) : num;
	return maxnum - minnum <= limit;
}

// r位置的数字进入窗口，修改窗口内最大值的更新结构、修改窗口内最小值的更新结构
void push(int r)
{
	while(maxh < maxt && arr[maxdq[maxt - 1]] <= arr[r]){
		maxt--;
	}
	maxdq[maxt++] = r;
	while(minh < mint && arr[mindq[mint - 1]] >= arr[r]){
		mint--;
	}
	mindq[mint++] = r;
}

// 窗口要吐出l位置的数了！检查过期！
void pop(int l)
{
	if(maxh < maxt && maxdq[maxh] == l){
		maxh++;
	}
	if(minh < mint && mindq[minh] == l){
		minh++;
	}
}


int longestSubarray()
{
	maxh = maxt = minh = mint = 0;
	int ans = 0;
	for(int l = 0, r = 0; l < n; l++){
		// [l,r)，r永远是没有进入窗口的、下一个数所在的位置
		while(r < n && ok(arr[r])){
			push(r++);
		}
		// 从while出来的时候，[l,r)是l开头的子数组能向右延伸的最大范围
		ans = max(ans, r - l);
		pop(l);
	}
	return ans;
}



int main()
{
	cin >> n >> limit;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int ans = longestSubarray();
	cout << ans << endl;
	return 0;
}
