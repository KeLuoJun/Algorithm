# https://www.luogu.com.cn/problem/P2719

import sys

# 方法一
def main() -> None:
    n_2 = int(sys.stdin.read().strip())
    n = n_2 // 2
    dp = [[0.0] * (n + 1) for _ in range(n + 1)]
    dp[0][0] = 1.0
    for i in range(2, n + 1):
        dp[i][0] = 1.0
        dp[0][i] = 1.0
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) / 2
    print(f"{dp[n][n]:.4f}")
    return

# 方法二



if __name__ == '__main__':
    main()
