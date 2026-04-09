# 数组中两个数的最大异或值
# 给你一个整数数组 nums ，返回 nums[i] XOR nums[j] 的最大运算结果，其中 0 <= i <= j <= n
# 1 <= nums.length <= 2 * 10 ^ 5
# 0 <= nums[i] <= 2 ^ 31 - 1
# 测试链接: https: // leetcode.cn/problems/maximum-xor-of-two-numbers-in -an-array/


"""
以下解法存在超出内存限制
"""
from typing import List

class TrieNode:
    def __init__(self):
        self.childern = {}
        self.pass_count = 0

class Solution:
    def __init__(self):
        self.root = TrieNode()

    def findMaximumXOR(self, nums: List[int]) -> int:
        # 计算数组最大值的二进制状态，有多少个前缀的0
        # 可以忽略这些前置的0，从left位开始考虑
        self.high = 31 - (32 - max(nums).bit_length())
        ans = 0
        for num in nums:
            self._insert(num)
        for num in nums:
            ans = max(ans, self._maxXor(num))
        self._clearn()
        return ans


    def _insert(self, num: int) -> None:
        cur = self.root
        for i in range(self.high, -1, -1):
            bit = (num >> i) & 1
            if bit not in cur.childern:
                cur.childern[bit] = TrieNode()
            cur = cur.childern[bit]

    def _maxXor(self, num: int) -> int:
        cur = self.root
        ans = 0  # 最终异或的结果(尽量大)
        for i in range(self.high, -1, -1):
            bit = (num >> i) & 1  # bit : num第i位的状态
            want = bit ^ 1  # want : num第i位希望遇到的状态
            if want not in cur.childern:
                # 不能达成
                # want变成真的往下走的路
                want ^= 1
            ans |= (bit ^ want) << i
            cur = cur.childern[want]
        return ans

    def _clearn(self):
        self.root = None

        