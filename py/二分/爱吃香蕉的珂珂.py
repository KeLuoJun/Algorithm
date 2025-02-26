# 爱吃香蕉的珂珂
# 珂珂喜欢吃香蕉。这里有 n 堆香蕉，第 i 堆中有 piles[i] 根香蕉
# 警卫已经离开了，将在 h 小时后回来。
# 珂珂可以决定她吃香蕉的速度 k （单位：根/小时)
# 每个小时，她将会选择一堆香蕉，从中吃掉 k 根
# 如果这堆香蕉少于 k 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉
# 珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。
# 返回她可以在 h 小时内吃掉所有香蕉的最小速度 k（k 为整数）
# 测试链接 : https://leetcode.cn/problems/koko-eating-bananas/

class Solution:
    def minEatingSpeed(self, piles: list[int], h: int) -> int:
        ans = -1
        l, r = 1, max(piles)
        while l <= r:
            mid = (l + r) // 2
            if self.check(piles, mid, h):
                ans = mid
                r = mid - 1
            else:
                l = mid + 1
        return ans
    def check(self, piles, mid, h):
        n = len(piles)
        ans = 0
        for i in range(n):
            # (a/b)结果向上取整，如果a和b都是非负数，可以写成(a+b-1)/b
            ans += (piles[i] + mid - 1) // mid
        return ans <= h



