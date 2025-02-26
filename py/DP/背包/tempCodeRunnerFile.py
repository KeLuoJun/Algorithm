def solution_1():
    dp = [[0 for _ in range(t + 1)] for _ in range(m + 1)]

    for i in range(1, m + 1):
        for j in range(cost[i], t + 1):
            dp[i][j] = max(dp[i - 1][j], dp[i][j - cost[i]] + val[i])
    return dp[m][t]


t, m = list(map(int, input().split()))
cost = list(map(int, input().split()))
val = list(map(int, input().split()))
cost.insert(0, 0)
val.insert(0, 0)

print(solution_1())