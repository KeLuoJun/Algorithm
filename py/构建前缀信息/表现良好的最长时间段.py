# 表现良好的最长时间段
# 给你一份工作时间表 hours，上面记录着某一位员工每天的工作小时数
# 我们认为当员工一天中的工作小时数大于 8 小时的时候，那么这一天就是 劳累的一天
# 所谓 表现良好的时间段 ，意味在这段时间内，「劳累的天数」是严格 大于 不劳累的天数
# 请你返回 表现良好时间段 的最大长度
# 测试链接 : https://leetcode.cn/problems/longest-well-performing-interval/


class Solution:
    def longestWPI(self, hours: list[int]) -> int:
        hours = [1 if h > 8 else -1 for h in hours]
        ans = 0
        m = {}
        m[0] = -1
        sum = 0
        for i in range(len(hours)):
            sum += hours[i]
            if sum > 0:
                ans = i + 1
            else:
                if sum - 1 in m:
                    ans = max(ans, i - m[sum - 1])
            if sum not in m:
                m[sum] = i
        return ans


        