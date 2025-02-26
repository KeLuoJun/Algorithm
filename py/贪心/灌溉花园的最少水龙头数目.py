# 灌溉花园的最少水龙头数目
# 在x轴上有一个一维的花园，花园长度为n，从点0开始，到点n结束
# 花园里总共有 n + 1 个水龙头，分别位于[0, 1, ... n]
# 给你一个整数n和一个长度为n+1的整数数组ranges
# 其中ranges[i]表示
# 如果打开点i处的水龙头，可以灌溉的区域为[i-ranges[i], i+ranges[i]]
# 请你返回可以灌溉整个花园的最少水龙头数目
# 如果花园始终存在无法灌溉到的地方请你返回-1
# 测试链接 : https://leetcode.cn/problems/minimum-number-of-taps-to-open-to-water-a-garden/

class Solution:
    def minTaps(self, n: int, ranges:list[int]) -> int:
        start = 0
        # right[i] = j
		# 所有左边界在i的水龙头里，影响到的最右右边界是j
        rigth = [0] * (n + 1)
        for i in range(n + 1):
            start = max(0, i - ranges[i])
            rigth[start] = max(rigth[start], i + ranges[i])
        # 当前ans数量的水龙头打开，影响到的最右右边界
        cur = 0
        # 如果再多打开一个水龙头，影响到的最右边界
        next = 0
        # 打开水龙头的数量
        ans = 0
        for i in range(n):
            next = max(next, rigth[i])
            if i == cur:
                if next > i:
                    ans += 1
                    cur = next
                else:
                    return -1
        return ans


        