# 目标和
# 给你一个非负整数数组 nums 和一个整数 target 。
# 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数
# 可以构造一个表达式
# 例如nums=[2, 1]，可以在2之前添加'+' ，在1之前添加'-'
# 然后串联起来得到表达式 "+2-1" 。
# 返回可以通过上述方法构造的，运算结果等于 target 的不同表达式的数目
# 测试链接 : https://leetcode.cn/problems/target-sum/


# 普通尝试，暴力递归
class Solution:
    def findTargetSumWays(self, nums: list[int], target: int) -> int:
        self.nums = nums
        self.target = target
        self.n = len(nums)
        return self.f1(0, 0)

    def f1(self, i, sum):
        if i == self.n:
            return 1 if sum == self.target else 0
        return self.f1(i + 1, sum + self.nums[i]) + self.f1(i + 1, sum - self.nums[i])
    
# 普通尝试
# 严格位置依赖的动态规划
class Solution:
    def findTargetSumWays(self, nums: list[int], target: int) -> int:
        n = len(nums)
        s = sum(nums)
        if target > s or target < -s:
            return 0
        # 原本的dp[i][j]含义:
        # nums[0...i-1]范围上，已经形成的累加和是sum
        # nums[i...]范围上，每个数字可以标记+或者-
        # 最终形成累加和为target的不同表达式数目
        # 因为sum可能为负数，为了下标不出现负数，
        # "原本的dp[i][j]"由dp表中的dp[i][j + s]来表示
        # 也就是平移操作！
        # 一切"原本的dp[i][j]"一律平移到dp表中的dp[i][j + s]
        m = 2 * s + 1
        dp = [[0] * (m)] * (n + 1)
        # 原本的dp[n][target] = 1，平移！
        dp[n][target + s] = 1
        # 从 n-1 出发省去讨论 i 越界的问题 
        for i in range(n-1, -1, -1):
            for j in range(-s, s + 1):
                if j + nums[i] + s < m:
                    # 原本是 : dp[i][j] = dp[i + 1][j + nums[i]]
                    # 平移
                    dp[i][j + s] = dp[i + 1][j + s + nums[i]]
                if j - nums[i] + s >= 0:
                    # 原本是 : dp[i][j] += dp[i + 1][j - nums[i]]
			        # 平移！
                    dp[i][j + s] += dp[i + 1][j - nums[i] + s]
        # 原本应该返回dp[0][0]
        # 平移！
        # 返回dp[0][0 + s]
        return dp[0][s]



        