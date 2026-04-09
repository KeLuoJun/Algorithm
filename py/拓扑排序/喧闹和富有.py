# 喧闹和富有
# 从 0 到 n - 1 编号，其中每个人都有不同数目的钱，以及不同程度的安静值
# 给你一个数组richer，其中richer[i] = [ai, bi] 表示
# person ai 比 person bi 更有钱
# 还有一个整数数组 quiet ，其中 quiet[i] 是 person i 的安静值
# richer 中所给出的数据 逻辑自洽
# 也就是说，在 person x 比 person y 更有钱的同时，不会出现
# person y 比 person x 更有钱的情况
# 现在，返回一个整数数组 answer 作为答案，其中 answer[x] = y 的前提是,
# 在所有拥有的钱肯定不少于 person x 的人中，
# person y 是最安静的人（也就是安静值 quiet[y] 最小的人）。
# 测试链接 : https://leetcode.cn/problems/loud-and-rich/


import sys
from collections import deque
from typing import List


def loudAndRich(richer: List[List[int]], quiet: List[int]) -> List[int]:
    n = len(quiet)
    graph = [[] for _ in range(n)]
    indegree = [0] * n
    for r in richer:
        graph[r[0]].append(r[1])
        indegree[r[1]] += 1

    queue = deque()
    for i in range(n):
        if indegree[i] == 0:
            queue.append(i)
    ans = [i for i in range(n)]

    while queue:
        cur = queue.popleft()
        for next in graph[cur]:
            if quiet[ans[cur]] < quiet[ans[next]]:
                ans[next] = ans[cur]
            indegree[next] -= 1
            if indegree[next] == 0:
                queue.append(next)
    return ans




def main() -> None:
    n = int(sys.stdin.readline().strip())
    richer = [list(map(int, sys.stdin.readline().strip().split())) for _ in range(n)]
    quiet = list(map(int, sys.stdin.readline().strip().split()))
    result = loudAndRich(richer, quiet)
    print(*result)

if __name__ == '__main__':
    main()
