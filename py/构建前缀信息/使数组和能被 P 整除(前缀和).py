# 给你一个正整数数组 nums，请你移除 最短 子数组（可以为 空），
# 使得剩余元素的 和 能被 p 整除。 不允许 将整个数组都移除。
# 请你返回你需要移除的最短子数组的长度，如果无法满足题目要求，返回 -1 。
# 测试链接：https://leetcode.cn/problems/make-sum-divisible-by-p/ 
 
class Solution:
    def minSubarray(self, nums: list[int], p: int) -> int:
        mod = 0  # 整体的模
        for i in nums:
            mod = (mod + i) % p
            # 不是 mod += (mod + num[i]) % p
        if mod == 0:
            return 0
        ans = len(nums)
        m = {}
        m[0] = -1
        cur = 0
        for i in range(len(nums)):
            cur = (cur + nums[i]) % p  # 当前位置之前的子数组的模
            find = cur - mod if cur >= mod else cur + p - mod
            # find  = (cur + p - mod) % p;
            if find in m:
                ans = min(ans, i - m[find])
            m[cur] = i  # 更新模为cur的最右位置 
        if ans == len(nums):
            return -1
        return ans

        

