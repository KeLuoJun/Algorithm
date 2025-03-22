# 最低票价
# 在一个火车旅行很受欢迎的国度，你提前一年计划了一些火车旅行
# 在接下来的一年里，你要旅行的日子将以一个名为 days 的数组给出
# 每一项是一个从 1 到 365 的整数
# 火车票有 三种不同的销售方式
# 一张 为期1天 的通行证售价为 costs[0] 美元
# 一张 为期7天 的通行证售价为 costs[1] 美元
# 一张 为期30天 的通行证售价为 costs[2] 美元
# 通行证允许数天无限制的旅行
# 例如，如果我们在第 2 天获得一张 为期 7 天 的通行证
# 那么我们可以连着旅行 7 天(第2~8天)
# 返回 你想要完成在给定的列表 days 中列出的每一天的旅行所需要的最低消费
# 测试链接 : https://leetcode.cn/problems/minimum-cost-for-tickets/

import sys

def main() -> None:
    days = list(map(int, sys.stdin.readline().strip().split()))
    costs = list(map(int, sys.stdin.readline().strip().split()))

    durations = [1, 7, 30]
    n = len(days)
    dp = [float('inf')] * 366
    dp[n] = 0
    for i in range(n - 1, -1, -1):
        j = i
        for k in range(3):
            while j < n and days[i] + durations[k] > days[j]:
                j += 1
            dp[i] = min(dp[i], costs[k] + dp[j])
    return dp[0]


if __name__ == '__main__':
    ans = main()
    print(ans)
