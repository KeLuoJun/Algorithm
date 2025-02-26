# 使数组相似的最少操作次数
# 给你两个正整数数组 nums 和 target ，两个数组长度相等
# 在一次操作中，你可以选择两个 不同 的下标 i 和 j
# 其中 0 <= i, j < nums.length ，并且：
# 令 nums[i] = nums[i] + 2 且
# 令 nums[j] = nums[j] - 2
# 如果两个数组中每个元素出现的频率相等，我们称两个数组是 相似 的
# 请你返回将 nums 变得与 target 相似的最少操作次数
# 测试数据保证nums一定能变得与target相似
# 测试链接 : https://leetcode.cn/problems/minimum-number-of-operations-to-make-arrays-similar/

class Solution:
    def makeSimilar(self, nums: list[int], target: list[int]) -> int:
        self.n = len(nums)
        self.nums, oddsize = self.split(nums)
        self.target, _ = self.split(target)
        self.nums[:oddsize] = sorted(self.nums[:oddsize])
        self.nums[oddsize:] = sorted(self.nums[oddsize:])
        self.target[:oddsize] = sorted(self.target[:oddsize])
        self.target[oddsize:] = sorted(self.target[oddsize:])
        ans = 0
        for i in range(self.n):
            ans += abs(self.nums[i] - self.target[i])
        return int(ans // 4)

    def split(self, arr):
        oddsize = 0
        for i in range(self.n):
            if arr[i] & 1:
                arr[i], arr[oddsize] = arr[oddsize], arr[i]
                oddsize += 1
        return arr, oddsize
        
        