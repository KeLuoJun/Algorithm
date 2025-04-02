# 使网格图至少有一条有效路径的最小代价
# 给你一个 m * n 的网格图 grid 。 grid 中每个格子都有一个数字
# 对应着从该格子出发下一步走的方向。 grid[i][j] 中的数字可能为以下几种情况：
# 1 ，下一步往右走，也就是你会从 grid[i][j] 走到 grid[i][j + 1]
# 2 ，下一步往左走，也就是你会从 grid[i][j] 走到 grid[i][j - 1]
# 3 ，下一步往下走，也就是你会从 grid[i][j] 走到 grid[i + 1][j]
# 4 ，下一步往上走，也就是你会从 grid[i][j] 走到 grid[i - 1][j]
# 注意网格图中可能会有 无效数字 ，因为它们可能指向 grid 以外的区域
# 一开始，你会从最左上角的格子 (0,0) 出发
# 我们定义一条 有效路径 为从格子 (0,0) 出发，每一步都顺着数字对应方向走
# 最终在最右下角的格子 (m - 1, n - 1) 结束的路径
# 有效路径 不需要是最短路径
# 你可以花费1的代价修改一个格子中的数字，但每个格子中的数字 只能修改一次
# 请你返回让网格图至少有一条有效路径的最小代价
# 测试链接 : https://leetcode.cn/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/


import sys
from collections import deque

def bfs_01(grid):
    m, n = len(grid), len(grid[0])
    MOVE = [[], [0, 1], [0, -1], [1, 0], [-1, 0]]
    distance = [[float('inf')] * n for _ in range(m)]
    dq = deque()

    dq.appendleft([0, 0])
    distance[0][0] = 0
    while dq:
        x, y = dq.popleft()
        if x == m - 1 and y == n - 1:
            return distance[x][y]
        for i in range(1, 5):
            nx, ny = x + MOVE[i][0], y + MOVE[i][1]
            weight = 1 if grid[x][y] != i else 0
            if 0 <= nx < m and 0 <= ny < n and \
                distance[x][y] + weight < distance[nx][ny]:
                    distance[nx][ny] = distance[x][y] + weight
                    if weight == 0:
                        dq.appendleft([nx, ny])
                    else:
                        dq.append([nx, ny])
    return -1

def main():
    m, n = map(int, sys.stdin.readline().strip().split())
    grid = []
    for _ in range(m):
        grid.append(list(map(int, sys.stdin.readline().strip().split())))
    print(bfs_01(grid))

if __name__ == '__main__':
    main()
