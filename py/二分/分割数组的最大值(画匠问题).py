# 分割数组的最大值(画匠问题)
# 给定一个非负整数数组 nums 和一个整数 m
# 你需要将这个数组分成 m 个非空的连续子数组。
# 设计一个算法使得这 m 个子数组各自和的最大值最小。
# 测试链接 : https://leetcode.cn/problems/split-array-largest-sum/
import sys

class Solution:
    def splitArray(self, nums: list[int], k: int) -> int:
        self.nums = nums
        l, r = min(nums), sum(nums)
        ans = 0
        while l <= r:
            mid = (l + r) // 2
            if self.func(mid) <= k:
                ans = mid
                r = mid - 1
            else:
                l = mid + 1
        return ans
    
    def func(self, mid):
        count = 1
        sum = 0
        for num in self.nums:
            if num > mid:
                return sys.maxsize
            if sum + num > mid:
                count += 1
                sum = num
            else:
                sum += num
        return count



