# 超级洗衣机
# 假设有n台超级洗衣机放在同一排上
# 开始的时候，每台洗衣机内可能有一定量的衣服，也可能是空的
# 在每一步操作中，你可以选择任意 m (1 <= m <= n) 台洗衣机
# 与此同时将每台洗衣机的一件衣服送到相邻的一台洗衣机
# 给定一个整数数组machines代表从左至右每台洗衣机中的衣物数量
# 请给出能让所有洗衣机中剩下的衣物的数量相等的最少的操作步数
# 如果不能使每台洗衣机中衣物的数量相等则返回-1
# 测试链接 : https://leetcode.cn/problems/super-washing-machines/

class Solution:
    def findMinMoves(self, machines: list[int]) -> int:
        n = len(machines)
        total = sum(machines)
        if total % n: return -1

        avg = int(total // n)
        # 左侧累加和，左边还需要多少件衣服，右边还需要多少件衣服
        left_sum, left_need, right_need = 0, 0, 0
        bottle_neck = 0
        ans = 0
        for i in range(n):
            left_need = avg * i - left_sum
            right_need = avg * (n - i - 1) - (total - left_sum - machines[i])
            if left_need > 0 and right_need > 0:
                bottle_neck = left_need + right_need
            else:
                bottle_neck = max(abs(left_need), abs(right_need))
            left_sum += machines[i]
            ans = max(ans, bottle_neck)
        return ans

