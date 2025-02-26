# 01背包(模版)
# 给定一个正数t，表示背包的容量
# 有m个货物，每个货物可以选择一次
# 每个货物有自己的体积costs[i]和价值values[i]
# 返回在不超过总容量的情况下，怎么挑选货物能达到价值最大
# 返回最大的价值
# 测试链接 : https://www.luogu.com.cn/problem/P1048
def compute1(t, m):
    # 初始化dp表
    dp = [[0 for _ in range(t + 1)] for _ in range(m + 1)]

    # 动态规划计算过程
    for i in range(1, m + 1):
        for j in range(1, t + 1):
            dp[i][j] = dp[i - 1][j]
            if j - cost[i] >= 0:
                dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + value[i])
    return dp[m][t]

# 空间压缩
def compute2(t, m):
    dp = [0 for _ in range(t + 1)]
    for i in range(1, m + 1):
        for j in range(t, cost[i] - 1, -1):
            dp[j] = max(dp[j], dp[j - cost[i]] + value[i])
    return dp[t]


if __name__ == '__main__':
    t, m = map(int, input().split())
    cost = [0] * (m + 1)
    value = [0] * (m + 1)
    for i in range(1, m+ 1):
        c, v = map(int, input().split())
        cost[i] = c
        value[i] = v

    print(compute1(t, m))
    print(compute2(t, m))
