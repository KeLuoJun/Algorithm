// 单调栈求每个位置左右两侧，离当前位置最近、且值严格小于的位置
// 给定一个可能含有 重复 值的数组 arr
// 找到每一个 i 位置左边和右边离 i 位置最近且值比 arr[i] 小的位置
// 返回所有位置相应的信息。
// 输入描述：
// 第一行输入一个数字 n，表示数组 arr 的长度。
// 以下一行输入 n 个数字，表示数组的值
// 输出描述：
// 输出n行，每行两个数字 L 和 R，如果不存在，则值为 -1，下标从 0 开始。
// 测试链接 : https://www.nowcoder.com/practice/2a2c00e7a88a498693568cef63a4b7bb
// （通用） 


// 求最近且大于  栈：小压大
// 求最近且小于  栈：大压小
// 至于栈中要不要严格大压小（小压大），看题目情况 
// 相等的时候也弹出，则只有最后一个相等的值弹出的时候结果才是对的
// 所以要进行修正 


#include <iostream>
using namespace std;
const int MAXN = 1000000;
int (*ans)[2] = new int[MAXN][2];
int *stack = new int[MAXN];

void compute(int *arr,int n)
{
	int r = 0;
	int cur;
	//遍历阶段 
	for(int i = 0; i < n; i++)
	{
		while(r > 0 && arr[i] <= arr[stack[r - 1]])
		{
			// cur当前弹出的位置，左边最近且小
			cur = stack[--r];
			ans[cur][0] = r > 0 ? stack[r - 1] : -1;
			ans[cur][1] = i;
		}
		stack[r++] = i;
	}
	
	//清算阶段 
	while(r > 0)
	{
		cur = stack[--r];
		ans[cur][0] = r > 0 ? stack[r - 1] : -1;
		ans[cur][1] = -1;
	}
	
	//修正阶段 
	// 左侧的答案不需要修正一定是正确的，只有右侧答案需要修正
	// 因为左侧都是在栈中得到的答案，而栈是严格的大压小的 
	// 从右往左修正，n-1位置的右侧答案一定是-1，不需要修正
	// 数组上 a[i],a[j]数字相同，则i到j之前的数字必大于a[i] 
	for(int i = n - 2; i >= 0; i--)
	{
		if(ans[i][1] != -1 && arr[ans[i][1]] == arr[i])
			ans[i][1] = ans[ans[i][1]][1];
	}
}

//// 第二种方式求单调栈
//// 这里 l[]表示往右比自己小的最近位置 
////      r[]表示往左比自己小的最近位置  
//typedef long long ll;
//ll solve()
//{
//    ll top = 0;
//    for(ll i = 0; i < n; i++){
//        while(top > 0 && arr[stack[top - 1]] >= arr[i]){
//            top--;
//        }
//        l[i] = top > 0 ? stack[top - 1] : 0;
//        stack[top++] = i;
//    }
//    top = 0;
//    for(ll i = n - 1; i >= 0; i--){
//        while(top > 0 && arr[stack[top - 1]] >= arr[i]){
//            top--;
//        }
//        r[i] = top > 0 ? stack[top - 1] : n - 1;
//        stack[top++] = i;
//    }
//
//    ll ans = 0;
//    for(int i = 0; i < n; i++){
//        ans = max(ans, (r[i] - l[i] - 1) * arr[i]);
//    }
//    return ans;
//}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for(int i = 0; i < n; i++)	
		cin >> arr[i];
	compute(arr, n);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= 1; j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	delete[] arr;
	return 0;
 } 
