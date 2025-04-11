# 岛屿数量
# 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量
# 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成
# 此外，你可以假设该网格的四条边均被水包围
# 测试链接 : https://leetcode.cn/problems/number-of-islands/

import sys

def numIslands(grid):
    n, m = len(grid), len(grid[0])
    def dfs(grid, n, m, i, j):
        if i < 0 or i >= n or j < 0 or j >= m or grid[i][j] != '1':
            return
        grid[i][j] = '0'
        MOVE = [-1, 0, 1, 0, -1]
        for k in range(4):
            dfs(grid, n, m, i + MOVE[k], j + MOVE[k + 1])
    islands = 0
    for i in range(n):
        for j in range(m):
            if grid[i][j] == '1':
                islands += 1
                dfs(grid, n, m, i, j)
    return islands
    

def main() -> None:
    n, m = map(int, sys.stdin.readline().strip().split())
    grid = [list(map(str, sys.stdin.readline().strip().split())) for _ in range(n)]
    print(numIslands(grid))


if __name__ == '__main__':
    main()
