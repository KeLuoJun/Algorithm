# 有效涂色问题
# 给定n、m两个参数
# 一共有n个格子，每个格子可以涂上一种颜色，颜色在m种里选
# 当涂满n个格子，并且m种颜色都使用了，叫一种有效方法
# 求一共有多少种有效的涂色方法
# 1 <= n, m <= 5000
# 结果比较大请 % 1000000007 之后返回
# 对数器验证

MOD = 1000000007

def solution(n, m):
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        dp[i][1] = m
    for i in range(2, n + 1):
        for j in range(2, m + 1):
            dp[i][j] = (dp[i - 1][j] * j) % MOD
            dp[i][j] = (dp[i - 1][j - 1] * (m - j + 1) + dp[i][j]) % MOD
    return dp[n][m]