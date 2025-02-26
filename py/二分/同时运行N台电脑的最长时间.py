# 同时运行N台电脑的最长时间
# 你有 n 台电脑。给你整数 n 和一个下标从 0 开始的整数数组 batteries
# 其中第 i 个电池可以让一台电脑 运行 batteries[i] 分钟
# 你想使用这些电池让 全部 n 台电脑 同时 运行。
# 一开始，你可以给每台电脑连接 至多一个电池
# 然后在任意整数时刻，你都可以将一台电脑与它的电池断开连接，并连接另一个电池，你可以进行这个#作 任意次
# 新连接的电池可以是一个全新的电池，也可以是别的电脑用过的电池
# 断开连接和连接新的电池不会花费任何时间。
# 注意，你不能给电池充电。
# 请你返回你可以让 n 台电脑同时运行的 最长 分钟数。
# 测试链接 : https://leetcode.cn/problems/maximum-running-time-of-n-computers/

class Solution:
    def maxRunTime(self, n: int, batteries: list[int]) -> int:
        self.n = n
        self.batteries = batteries
        Sum = sum(batteries)
        Max = max(batteries)
        # 所有电池的最大电量是max
        # 如果此时sum > (long) max * num，
        # 说明 : 最终的供电时间一定在 >= max，而如果最终的供电时间 >= max
        # 说明 : 对于最终的答案X来说，所有电池都是课上讲的"碎片拼接"的概念
        # 那么寻找 ? * num <= sum 的情况中，尽量大的 ? 即可
        # 即sum / num
        if Sum >= (n * Max):
            return Sum // n
        # 最终的供电时间一定在 < max范围上
        # [0, sum]二分范围，可能定的比较粗，虽然不影响，但毕竟是有点慢
        # [0, max]二分范围！更精细的范围，二分次数会变少
        l, r = 0, Max
        ans = -1
        while l <= r:
            mid = (l + r) // 2
            if self.check(mid):
                ans = mid
                l = mid + 1
            else:
                r = mid - 1
        return ans
    
    def check(self, mid):
        sum = 0
        num = self.n
        for x in self.batteries:
            if x >= mid:
                num -= 1
            else:
                sum += x
        if sum >= mid * num:
            return True
        else:
            return False
    

        