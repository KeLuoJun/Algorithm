# 最小路径和
# 给定一个包含非负整数的 m x n 网格 grid
# 请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
# 说明：每次只能向下或者向右移动一步。
# 测试链接 : https://leetcode.cn/problems/minimum-path-sum/


class Solution:
    def minPathSum(self, grid: list[list[int]]) -> int:
        # dp = [[0 for _ in range(len(grid[0]))] for _ in range(len(grid))]
        # dp[0][0] = grid[0][0]
        # for i in range(1, len(grid)):
        #     dp[i][0] = grid[i][0] + dp[i - 1][0]
        # for j in range(1, len(grid[0])):
        #     dp[0][j] = grid[0][j] + dp[0][j - 1]
        # for i in range(1, len(grid)):
        #     for j in range(1, len(grid[0])):
        #         dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]
        # return dp[len(grid) - 1][len(grid[0]) - 1]

        # 空间压缩
        n = len(grid)
        m = len(grid[0])
        dp = [0 for _ in range(m)]
        dp[0] = grid[0][0]
        for j in range(1, m):
            dp[j] = dp[j - 1] + grid[0][j]
        for i in range(1, n):
            dp[0] += grid[i][0]
            for j in range(1, m):
                dp[j] = min(dp[j - 1], dp[j]) + grid[i][j]
        return dp[m - 1]
