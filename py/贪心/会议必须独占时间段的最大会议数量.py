# 会议必须独占时间段的最大会议数量
# 给定若干会议的开始、结束时间
# 你参加某个会议的期间，不能参加其他会议
# 返回你能参加的最大会议数量
# 来自真实大厂笔试，没有在线测试，对数器验证

# 一个会议会占用会议起始和结束时间内的所有时间
class Solution:
    def maxEvents(self, events: list[list[int]]) -> int:
        n = len(events)
        # 根据会议开始时间排序

        events.sort(key=lambda x: x[0])
        ans = 0
        cur = -1
        for i in range(n):
            if events[i][0] >= cur:
                ans += 1
                cur = events[i][1]
        return ans
    

# 暴力方法
class Solution:
    def maxEvents(self, events: list[list[int]]) -> int:
        self.n = len(events)
        return self.f(events, 0)
    
    def f(self, events, i):
        ans = 0
        if i == self.n:
            cur = -1
            for j in range(self.n):
                if events[j][0] >= cur:
                    ans += 1
                    cur = events[j][1]
        else:
            for j in range(i, self.n):
                events[j], events[i] = events[i], events[j]
                ans = max(ans, self.f(events, i + 1))
                events[j], events[i] = events[i], events[j]
        return ans