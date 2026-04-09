# 并行课程 III
# 给你一个整数 n ，表示有 n 节课，课程编号从 1 到 n
# 同时给你一个二维整数数组 relations ，
# 其中 relations[j] = [prevCoursej, nextCoursej]
# 表示课程 prevCoursej 必须在课程 nextCoursej 之前 完成（先修课的关系）
# 同时给你一个下标从 0 开始的整数数组 time
# 其中 time[i] 表示完成第(i+1) 门课程需要花费的 月份 数。
# 请你根据以下规则算出完成所有课程所需要的 最少 月份数：
# 如果一门课的所有先修课都已经完成，你可以在 任意 时间开始这门课程。
# 你可以 同时 上 任意门课程 。请你返回完成所有课程所需要的 最少 月份数。
# 注意：测试数据保证一定可以完成所有课程（也就是先修课的关系构成一个有向无环图）
# 测试链接 : https://leetcode.cn/problems/parallel-courses-iii/

import sys
from typing import List
from collections import deque


def minimumTime(n: int, relations: List[List[int]], time: List[int]) -> int:
    graph = [[] for _ in range(n + 1)]
    indegree = [0] * (n + 1)
    for edge in relations:
        graph[edge[0]].append(edge[1])
        indegree[edge[1]] += 1

    queue = deque()
    for i in range(1, n + 1):
        if indegree[i] == 0:
            queue.append(i)
    
    cost = [0] * (n + 1)
    ans = 0
    while queue:
        cur = queue.popleft()
        cost[cur] += time[cur - 1]
        ans = max(ans, cost[cur])
        for next in graph[cur]:
            cost[next] = max(cost[next], cost[cur])
            indegree[next] -= 1
            if indegree[next] == 0:
                queue.append(next)
    return ans



def main() -> None:
    n, m = map(int, sys.stdin.readline().strip().split())
    relations = [list(map(int, sys.stdin.readline().strip().split()))
              for _ in range(m)]
    time = list(map(int, sys.stdin.readline().strip().split()))
    result = minimumTime(n, relations, time)
    print(result)


if __name__ == '__main__':
    main()
