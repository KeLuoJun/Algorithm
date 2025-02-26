# 岛屿数量
# 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量
# 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成
# 此外，你可以假设该网格的四条边均被水包围
# 测试链接 : https://leetcode.cn/problems/number-of-islands/

class Solution:

    def get_index(self, a, b):
        return a * self.m + b

    def build(self):
        for i in range(self.n):
            for j in range(self.m):
                if self.grid[i][j] == '1':
                    pos = self.get_index(i, j)
                    self.father[pos] = pos
                    self.sets += 1

    def find(self, i):
        if i != self.father[i]:
            self.father[i] = self.find(self.father[i])
        return self.father[i]

    def unions(self, a, b, c, d):
        fx = self.find(self.get_index(a, b))
        fy = self.find(self.get_index(c, d))
        if fx != fy:
            self.father[fx] = fy
            self.sets -= 1

    def numIslands(self, grid: list[list[str]]) -> int:
        self.grid = grid
        self.n = len(grid)
        self.m = len(grid[0])
        self.father = [-1] * (self.n * self.m)
        self.build()
        for i in range(self.n):
            for j in range(self.m):
                if self.grid[i][j] == '1':
                    if j > 0 and self.grid[i][j - 1] == '1':
                        self.unions(i, j, i, j - 1)
                    if i > 0 and self.grid[i - 1][j] == '1':
                        self.unions(i, j, i - 1, j)
        return self.sets

    # father = []
    sets = 0  # 集合数量