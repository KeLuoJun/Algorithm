# 会议只占一天的最大会议数量
# 给定若干会议的开始、结束时间
# 任何会议的召开期间，你只需要抽出1天来参加
# 但是你安排的那一天，只能参加这个会议，不能同时参加其他会议
# 返回你能参加的最大会议数量
# 测试链接 : https://leetcode.cn/problems/maximum-number-of-events-that-can-be-attended/

# 一个会议只会占用会议开始与结束时间内的某一天
import heapq
class Solution:
    def maxEvents(self, events: list[list[int]]) -> int:
        # 根据会议开始时间排序
        n = len(events)
        events.sort(key=lambda x: x[0])
        Min = events[0][0]
        Max = max([x for _, x in events])
        
        # 小根堆：会议的结束时间  
        heap = []
        ans, i = 0, 0
        for day in range(Min, Max + 1):
            # 将所有当天开始的会议加入堆中
            while i < n and events[i][0] == day:
                heapq.heappush(heap, events[i][1])
                i += 1
            # 移除所有已经结束的会议
            while heap and heap[0] < day:
                heapq.heappop(heap)
            # 如果堆不为空，移除最早结束的会议并计数
            if heap and heap[0] >= day:
                heapq.heappop(heap)
                ans += 1
        return ans


        
