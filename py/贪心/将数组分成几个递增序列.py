# 将数组分成几个递增序列
# 给你一个有序的正数数组 nums 和整数 K
# 判断该数组是否可以被分成一个或几个 长度至少 为 K 的 不相交的递增子序列
# 数组中的所有数字，都要被，若干不相交的递增子序列包含
# 测试链接 : https://leetcode.cn/problems/divide-array-into-increasing-sequences/

from collections import Counter

class Solution:
    def jump(self, nums: list[int], k) -> int:

        # 方式一求最大词频
        count = Counter(nums) # 最大词频
        max_cnt =  max(count.values())

        # 方式二求最大词频
        cnt = 1
        max_cnt = 1
        # 在有序数组中，求某个数的最大词频
        for i in range(1, len(nums)):
            if nums[i - 1] == nums[i]:
                cnt += 1
                max_cnt = max(max_cnt, cnt)
            else:
                cnt = 1
        max_cnt = max(max_cnt, cnt)
        # 向下取整如果满足 >= k
		# 那么所有的递增子序列长度一定 >= k
        return len(nums) // max_cnt >= k