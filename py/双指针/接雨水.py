# 接雨水
# 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水
# 测试链接 : https://leetcode.cn/problems/trapping-rain-water/

class Solution:
    # 辅助数组的解法（不是最优解）
    # 时间复杂度O(n)，额外空间复杂度O(n)
    def trap(self, height: list[int]) -> int:
        n = len(height)
        l_max, r_max = [0] * n, [0] * n
        l_max[0] = height[0]
        for i in range(1, n):
            l_max[i] = max(l_max[i - 1], height[i])
        r_max[n - 1] = height[n - 1]
        for i in range(n - 2, -1, -1):
            r_max[i] = max(r_max[i + 1], height[i])
        ans = 0
        for i in range(1, n - 1):
            ans += max(0, min(l_max[i - 1], r_max[i + 1]) - height[i])
        return ans
    