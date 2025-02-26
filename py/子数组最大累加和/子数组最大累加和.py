# 子数组最大累加和
# 给你一个整数数组 nums
# 返回非空子数组的最大累加和
# 测试链接 : https://leetcode.cn/problems/maximum-subarray/


# 动态规划
class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        n = len(nums)
        dp = [0] * n
        dp[0] = nums[0]
        ans = nums[0]
        for i in range(1, n):
            dp[i] = max(nums[i], dp[i - 1] + nums[i])
            ans = max(ans, dp[i])
        return ans
    
# Kadane算法
class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        """
        找出给定整数列表中连续子数组的最大累加和。

        参数:
        nums: list[int] - 整数列表

        返回:
        int - 连续子数组的最大累加和
        """
        # 初始化数组长度
        n = len(nums)
        # 初始化最大子数组和为数组的第一个元素
        ans = nums[0]
        # 初始化以当前位置结尾的最大子数组和为数组的第一个元素
        pre = nums[0]
        
        # 从数组的第二个元素开始遍历
        for i in range(1, n):
            # 更新以当前元素结尾的最大子数组和
            pre = max(nums[i], pre + nums[i])
            # 更新迄今为止找到的最大子数组和
            ans = max(ans, pre)
        
        # 返回最大子数组和
        return ans