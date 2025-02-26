# 你可以安排的最多任务数目
# 给你 n 个任务和 m 个工人。每个任务需要一定的力量值才能完成
# 需要的力量值保存在下标从 0 开始的整数数组 tasks 中，
# 第i个任务需要 tasks[i] 的力量才能完成
# 每个工人的力量值保存在下标从 0 开始的整数数组workers中，
# 第j个工人的力量值为 workers[j]
# 每个工人只能完成一个任务，且力量值需要大于等于该任务的力量要求值，即workers[j]>=tasks[i]
# 除此以外，你还有 pills 个神奇药丸，可以给 一个工人的力量值 增加 strength
# 你可以决定给哪些工人使用药丸，但每个工人 最多 只能使用 一片 药丸
# 给你下标从 0 开始的整数数组tasks 和 workers 以及两个整数 pills 和 strength
# 请你返回 最多 有多少个任务可以被完成。
# 测试链接 : https://leetcode.cn/problems/maximum-number-of-tasks-you-can-assign/

# 二分 + 贪心 + 队列

class Solution:
    def maxTaskAssign(self, tasks: list[int], workers: list[int], pills: int, strength: int) -> int:
        self.max_num = int(1e5)  # 双端队列，长度为原来的两倍
        self.n, self.m = len(tasks), len(workers)
        self.strength, self.pills = strength, pills
        self.tasks = sorted(tasks)
        self.workers = sorted(workers)
        ans = 0
        l, r = 0, min(self.n, self.m)
        while l <= r:
            mid = (l + r) // 2
            if self.ok(0, mid - 1, self.m - mid, self.m - 1):
                # mid中点，一定要完成的任务数量
		        # 任务拿最小的m个，工人找最大的m个（贪心） 
                ans = mid
                l = mid + 1
            else:
                r = mid - 1
        return ans

    def ok(self, tl, tr, wl, wr):
        h, t = 0, 0
        cnt = 0  #已经使用的药丸数量
        dq = [0] * (self.max_num)
        j = tl
        for i in range(wl, wr + 1):
            # i : 工人的编号
		    # j : 任务的编号
            for j in range(j, tr + 1):
                # 工人不吃药的情况下，去解锁任务
                if self.tasks[j] <= self.workers[i]:
                    dq[t] = j
                    t += 1
                else:
                    break
            # 1-当前工人不吃药下能做任务(从队列头部拿任务做)
            if h < t and self.tasks[dq[h]] <= self.workers[i]:
                h += 1
            # 吃药之后的逻辑
            else:
                # 吃药之后，当前工人能再次解锁的任务
                for j in range(j, tr + 1):
                    if self.tasks[j] <= self.workers[i] + self.strength:
                        dq[t] = j
                        t += 1
                    else:
                        break
                # 2-当前工人吃药下能做任务(从队列尾部拿任务做)(贪心)
                # 因为是根据吃药后自己的能力解锁出来的，
                # 所以如果有任务，则t位置的任务一定能做
                if h < t:
                    t -= 1
                    cnt += 1
                else:
                    # 3-吃药之后还不能做解锁后的最大体力的工作
                    # 则这个工人不可能会被安排任务
                    # 因此不可能做到 wl 到 wr 的工人都安排任务 
                    return False
        return cnt <= self.pills
            
        


