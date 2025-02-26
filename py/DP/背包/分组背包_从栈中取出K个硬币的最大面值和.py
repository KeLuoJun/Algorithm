# 从栈中取出K个硬币的最大面值和
# 一张桌子上总共有 n 个硬币 栈 。每个栈有 正整数 个带面值的硬币
# 每一次操作中，你可以从任意一个栈的 顶部 取出 1 个硬币，从栈中移除它，并放入你的钱包里
# 给你一个列表 piles ，其中 piles[i] 是一个整数数组
# 分别表示第 i 个栈里 从顶到底 的硬币面值。同时给你一个正整数 k
# 请你返回在 恰好 进行 k 次操作的前提下，你钱包里硬币面值之和 最大为多少
# 测试链接 : https://leetcode.cn/problems/maximum-value-of-k-coins-from-piles/

class Solution:
    def maxValueOfCoins(self, piles: list[list[int]], k: int) -> int:
        n = len(piles)
        dp = [[0] * (k + 1)] * (n + 1)

        for i in range(1, n + 1):
            t = min(k, len(piles[i]))  # 求在这一组中操作的最大次数 
            # 每一组的前缀和即为最后在这一组所操作的最终次数 
		    # 预处理前缀和，为了加速计算
            presum = [0] * (t + 1)
            sum = 0
            for j in range(1, t + 1):
                sum += piles[i][j - 1]
                presum[j] = sum
            
            # 更新动态规划表
            for j in range(1, k + 1):
                dp[i][j] = dp[i - 1][j]  # i为前i组，j为当前容量
                # 枚举在当前组中，所有小于当前背包容量的操作数的情况 
                for k in range(1, min(j, t) + 1):
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + presum[k])

        return dp[n][k]