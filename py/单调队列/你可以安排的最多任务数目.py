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

# 二分 + 贪心 + 双端队列（单调队列）

import sys
from collections import deque
# 两个数组排序 : O(n * logn) + O(m * logm)
# 二分答案的过程，每次二分都用一下双端队列 : O((n和m最小值)*log(n和m最小值))
# 最复杂的反而是排序的过程了，所以时间复杂度O(n * logn) + O(m * logm)

def maxTaskAssign(tasks: list[int], workers: list[int], pills: int, strength: int) -> int:
    n, m = len(tasks), len(workers)
    tasks.sort(), workers.sort()

    def ok(mid):
        '''
        tasks[0....mid-1]需要力量最小的几个任务
        workers[mid....m-1]力量值最大的几个工人
        药效是s，一共有的药pills个
        在药的数量不超情况下，能不能每个工人都做一个任务
        '''
        nonlocal tasks, workers, pills, strength
        cnt = 0  # 已经使用的药的数量
        dq = deque()
        # i : 工人的编号
		# j : 任务的编号
        j = 0
        for i in range(m - mid, m):
            while j < mid and workers[i] >= tasks[j]:
                # 工人不吃药的情况下，去解锁任务
                dq.append(j)
                j += 1
            if dq and workers[i] >= tasks[dq[0]]:
                # 不吃药的情况下，去头部拿任务
                dq.popleft()
            else:
                # 吃药之后的逻辑
                # 吃药之后，去解锁任务
                while j < mid and workers[i] + strength >= tasks[j]:
                    dq.append(j)
                    j += 1
                if dq:
                # 吃药的情况下，去尾部拿任务
                    cnt += 1
                    dq.pop()
                else:
                    return False
        return cnt <= pills
    
    ans = 0
    l, r = 0, min(n, m)
    while l <= r:
        # m中点，一定要完成的任务数量
        mid = (l + r) // 2
        if ok(mid):
            ans = max(ans, mid)
            l = mid + 1
        else:
            r = mid - 1

    return ans


def main() -> None:
    n, m, pills, strength = map(int, sys.stdin.readline().strip().split())
    tasks = list(map(int, sys.stdin.readline().strip().split()))
    workers = list(map(int, sys.stdin.readline().strip().split()))
    print(maxTaskAssign(tasks, workers, pills, strength))

if __name__ == '__main__':
    main()

        


