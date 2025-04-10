# 水资源分配优化
# 村里面一共有 n 栋房子。我们希望通过建造水井和铺设管道来为所有房子供水。
# 对于每个房子 i，我们有两种可选的供水方案：一种是直接在房子内建造水井
# 成本为 wells[i - 1] （注意 -1 ，因为 索引从0开始 ）
# 另一种是从另一口井铺设管道引水，数组 pipes 给出了在房子间铺设管道的成本，
# 其中每个 pipes[j] = [house1j, house2j, costj] 
# 代表用管道将 house1j 和 house2j连接在一起的成本。连接是双向的。
# 请返回 为所有房子都供水的最低总成本
# 测试链接 : https://leetcode.cn/problems/optimize-water-distribution-in-a-village/

import sys

edges = []
cnt = None
father = []

class minCostToSupplyWater:
    def __init__(self, n, wells, pipes):
        self.n = n
        self.wells = wells
        self.pipes = pipes
        self.edges = [[0] * 3 for _ in range(n + 1)]

    def build(self):
        self.cnt = 0
        self.father = [i for i in range(self.n + 1)]

    def find(self, i):
        if i != self.father[i]:
            self.father[i] = self.find(father[i])
        return self.father[i]
    def union(self, x, y):
        fx, fy = self.find(x), self.find(y)
        if fx != fy:
            self.father[fx] = self.father[fy]
            return True
        else:
            return False
    def ans(self):
        self.build();
        for i in range(self.n):
            self.edges[self.cnt][0] = 0
            self.edges[self.cnt][1] = i + 1
            self.edges[self.cnt][2] = self.wells[i]
            self.cnt += 1
        for i in range(len(self.pipes)):
            self.edges[self.cnt][0] = self.pipes[i][0]
            self.edges[self.cnt][1] = self.pipes[i][1]
            self.edges[self.cnt][2] = self.pipes[i][2]
            self.cnt += 1
        edges.sort(key=lambda x: x[2])
        ans = 0
        for i in range(self.cnt):
            if self.union(edges[i][0], edges[i][1]):
                ans += edges[i][2]
        return ans


def main() -> None:
    n, m = map(int, sys.stdin.readline().strip().split())
    wells = list(map(int, sys.stdin.readline().strip().split()))
    pipes = [list(map(int, sys.stdin.readline().strip().split())) for _ in range(m)]
    res = minCostToSupplyWater(n, wells, pipes)
    print(res.ans())


if __name__ == '__main__':
    main()

