# 数组的最小偏移量
# 给你一个由n个正整数组成的数组nums
# 你可以对数组的任意元素执行任意次数的两类操作：
# 如果元素是偶数，除以2
# 例如如果数组是[1,2,3,4]
# 那么你可以对最后一个元素执行此操作，使其变成[1,2,3,2]
# 如果元素是奇数，乘上2
# 例如如果数组是[1,2,3,4]
# 那么你可以对第一个元素执行此操作，使其变成[2,2,3,4]
# 数组的偏移量是数组中任意两个元素之间的最大差值
# 返回数组在执行某些操作之后可以拥有的最小偏移量
# 测试链接 : https://leetcode.cn/problems/minimize-deviation-in-array/

from sortedcontainers import SortedList
class Solution:
    def minimumDeviation(self, nums: list[int]) -> int:
        set_ = SortedList()
        for num in nums:
            if num & 1:
                set_.add(num * 2)
            else:
                set_.add(num)
        ans = set_[-1] - set_[0]
        while ans > 0 and set_[-1] % 2 == 0:
            x = set_.pop()
            set_.add(int(x // 2))  # 注意是int
            ans = min(ans, set_[-1] - set_[0])
        return ans

