# 最小区间
# 你有k个非递减排列的整数列表
# 找到一个最小区间，使得k个列表中的每个列表至少有一个数包含在其中
# 测试链接 : https://leetcode.cn/problems/smallest-range-covering-elements-from-k-lists/

import heapq
import bisect
from sortedcontainers import SortedSet

class Node:
        def __init__(self, v, i, j):
            self.v = v
            self.i = i
            self.j = j
        def __lt__(self, other):
            return (self.v, self.i) < (other.v, other.i)

class Solution:
    def smallestRange(self, nums: list[list[int]]) -> list[int]:
        n = len(nums)
        # 根据值排序
		# 为什么排序的时候i要参与
		# 因为有序表中比较相等的样本只会保留一个
		# 为了值一样的元素都保留，于是i要参与排序
		# 在有序表中的所有元素i必然都不同
        set_ = SortedSet(key=lambda node: (node.v, node.i))
        for i in range(n):
            set_.add(Node(nums[i][0], i, 0))

        r = float('inf') # 记录最窄区间的宽度
        a, b = 0, 0  # 记录最窄区间的开头和结尾
        max_node, min_node = None, None
        while len(set_) == n:
            max_node = set_[-1]  # 在有序表中，值最大的记录
            min_node = set_.pop(0)  # 在有序表中，值最小的记录，并弹出

            if max_node.v - min_node.v < r:
                r = max_node.v - min_node.v
                a, b = min_node.v, max_node.v
            if min_node.j + 1 < len(nums[min_node.i]):
                set_.add(Node(nums[min_node.i][min_node.j + 1], min_node.i, min_node.j + 1))
        return [a, b]
    



        