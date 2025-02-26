# 最短无序连续子数组
# 给你一个整数数组nums，你需要找出一个 连续子数组
# 如果对这个子数组进行升序排序，那么整个数组都会变为升序排序
# 请你找出符合题意的最短子数组，并输出它的长度
# 测试链接 : https://leetcode.cn/problems/shortest-unsorted-continuous-subarray/

import sys
class Solution:
    def findUnsortedSubarray(self, nums: list[int]) -> int:
        n = len(nums)
        # max > 当前数，认为不达标
	    # 从左往右遍历，记录最右不达标的位置
        Max, Rready = -sys.maxsize - 1, -1
        for i in range(n):
            if nums[i] < Max:
                Rready = i
            Max = max(Max, nums[i])
        # min < 当前数，认为不达标
	    # 从右往左遍历，记录最左不达标的位置
        Min, Lready = sys.maxsize, n
        for i in range(n-1, -1, -1):
            if nums[i] > Min:
                Lready = i
            Min = min(Min, nums[i])
        return max(0, Rready - Lready + 1)

