# 完全背包(模版)
# 给定一个正数t，表示背包的容量
# 有m种货物，每种货物可以选择 任意个
# 每种货物都有体积costs[i]和价值values[i]
# 返回在不超过总容量的情况下，怎么挑选货物能达到价值最大
# 返回最大的价值
# 测试链接 : https://www.luogu.com.cn/problem/P1616




def solution_1():
    dp = [[0 for _ in range(t + 1)] for _ in range(m + 1)]

    for i in range(1, m + 1):
        for j in range(cost[i], t + 1):
            dp[i][j] = max(dp[i - 1][j], dp[i][j - cost[i]] + val[i])
    return dp[m][t]

def solution_2():
    dp = [0 for _ in range(t + 1)]
    # 注意这里相当于
    # for(int j = 0; j <= t; j++)
    #		if(j - cost[i] >= 0) 
    # 从左往右
    # 因为不完全依赖于前i-1种物品的情况 
    #只要当前背包还有容量就能一直放当前物品而不用考虑当前物品的数量 
    # 此时 dp[j - cost[i]] 已经是当前行已经更新过的值 
    for i in range(1, t + 1):
        for j in range(cost[i], t + 1):
            dp[j] = max(dp[j], dp[j - cost[i]] + val[i])
    return dp[t]


t, m = list(map(int, input().split()))
cost = list(map(int, input().split()))
val = list(map(int, input().split()))
cost.insert(0, 0)
val.insert(0, 0)

print(solution_1())