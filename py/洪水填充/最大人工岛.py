# 最大人工岛
# 给你一个大小为 n * n 二进制矩阵 grid 。最多 只能将一格 0 变成 1 。
# 返回执行此操作后，grid 中最大的岛屿面积是多少？
# 岛屿 由一组上、下、左、右四个方向相连的 1 形成
# 测试链接 : https://leetcode.cn/problems/making-a-large-island/

import sys

def largestIsland(grid):
    n = len(grid)
    def dfs(grid, n, i, j, id):
        if i < 0 or i == n or j < 0 or j == n or grid[i][j] != 1:
            return
        MOVE = [-1, 0, 1, 0, -1]
        grid[i][j] = id
        for k in range(4):
            dfs(grid, n, i + MOVE[k], j + MOVE[k + 1], id)
    id = 2
    for i in range(n):
        for j in range(n):
            if grid[i][j] == 1:
                dfs(grid, n, i, j, id)
                id += 1

    size = [0] * id
    ans = 0
    for i in range(n):
        for j in range(n):
            if grid[i][j] > 1:
                size[grid[i][j]] += 1
                ans = max(ans, size[grid[i][j]])
    visited = [False] * id
    for i in range(n):
        for j in range(n):
            if grid[i][j] == 0:
                up = grid[i - 1][j] if i > 0 else 0
                down = grid[i + 1][j] if i + 1 < n else 0
                left = grid[i][j - 1] if j > 0 else 0
                right = grid[i][j + 1] if j + 1 < n else 0
                visited[up] = True
                merge = 1 + size[up]
                if not visited[down]:
                    merge += size[down]
                    visited[down] = True
                if not visited[left]:
                    merge += size[left]
                    visited[left] = True
                if not visited[right]:
                    merge += size[right]
                    visited[right] = True
                ans = max(ans, merge)
                visited[up] = False
                visited[down] = False
                visited[left] = False
                visited[right] = False
    return ans


def main() -> None:
    n = int(sys.stdin.readline().strip())
    grid = [list(map(int, sys.stdin.readline().strip().split())) for _ in range(n)]
    print(largestIsland(grid))

if __name__ == '__main__':
    main()
