# 检查边长度限制的路径是否存在
# 给你一个 n 个点组成的无向图边集 edgeList
# 其中 edgeList[i] = [ui, vi, disi] 表示点 ui 和点 vi 之间有一条长度为 disi 的边
# 请注意，两个点之间可能有 超过一条边 。
# 给你一个查询数组queries ，其中 queries[j] = [pj, qj, limitj]
# 你的任务是对于每个查询 queries[j] ，判断是否存在从 pj 到 qj 的路径
# 且这条路径上的每一条边都 严格小于 limitj 。
# 请你返回一个 布尔数组 answer ，其中 answer.length == queries.length
# 当 queries[j] 的查询结果为 true 时， answer 第 j 个值为 true ，否则为 false
# 测试链接 : https://leetcode.cn/problems/checking-existence-of-edge-length-limited-paths/

import sys

questions = []
father = []

def distanceLimitedPathsExist(n, edges, queries):
    global questions, father
    def build(n):
        global father
        father = [i for i in range(n)]
    def find(i):
        global father
        if i != father[i]:
            father[i] = find(father[i])
        return father[i]
    def union(x, y):
        global father
        father[find(x)] = father[find(y)]
    def isSameSet(x, y):
        return find(x) == find(y)
    m, k = len(edges), len(queries)
    questions = [[0] * 4 for _ in range(k)]
    for i in range(k):
        questions[i][0] = queries[i][0]
        questions[i][1] = queries[i][1]
        questions[i][2] = queries[i][2]
        questions[i][3] = i
    questions.sort(key=lambda x: x[2])
    edges.sort(key=lambda x: x[2])
    build(n)
    ans = [False] * k
    j = 0
    for i in range(k):
        while j < m and edges[j][2] < questions[i][2]:
            union(edges[j][0], edges[j][1])
            j += 1
        ans[questions[i][3]] = isSameSet(questions[i][0], questions[i][1])
    return ans


def main():
    n, m, k = map(int, sys.stdin.readline().split())
    edges = [list(map(int, sys.stdin.readline().split())) for _ in range(m)]
    queries = [list(map(int, sys.stdin.readline().split())) for _ in range(k)]
    print(distanceLimitedPathsExist(n, edges, queries))

if __name__ == "__main__":
    main()

