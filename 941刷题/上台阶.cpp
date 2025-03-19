#include <iostream>
using namespace std;
 
const int MAXN = 1000; // 假设楼梯阶数不会超过这个值
int dp[MAXN + 1]; // 初始化为全零数组

// 假设a, b, c是常量，在代码中给出它们的具体数值
int a;
int b;
int c;

void countWays(int n) {
    dp[0] = 1; // 到达第0级有一种方法，即原地不动

    // 对于每一级台阶
    for (int i = 1; i <= n; ++i) {
        // 从上一级台阶过来，分别尝试走a、b、c级台阶
        dp[i] = dp[i - a] + dp[i - b] + dp[i - c];
        
        // 如果当前台阶数不足以走a、b或c级，则对应的dp[i - x]应当忽略，即等于0
        if (i - a < 0) dp[i] -= dp[i - a];
        if (i - b < 0) dp[i] -= dp[i - b];
        if (i - c < 0) dp[i] -= dp[i - c];
    }
}

int main() {
    int n;
    std::cin >> n;
    //每次可以走的台阶数 
	cin >> a >> b >> c;
	
    countWays(n);
    std::cout << "小蓝总共有 " << dp[n] << " 种方案能正好走到楼梯顶端。\n";

    return 0;
}
