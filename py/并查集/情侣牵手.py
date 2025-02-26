# 情侣牵手
# n对情侣坐在连续排列的 2n 个座位上，想要牵到对方的手
# 人和座位由一个整数数组 row 表示，其中 row[i] 是坐在第 i 个座位上的人的ID
# 情侣们按顺序编号，第一对是 (0, 1)，第二对是 (2, 3)，以此类推，最后一对是 (2n-2, 2n-1)
# 返回 最少交换座位的次数，以便每对情侣可以并肩坐在一起
# 每次交换可选择任意两人，让他们站起来交换座位
# 测试链接 : https://leetcode.cn/problems/couples-holding-hands/

class Solution:
    def minSwapsCouples(self, row: list[int]) -> int:
        self.m = len(row) // 2
        self.build()
        for i in range(0, len(row), 2):
            self.unions(row[i] // 2, row[i + 1] // 2)
        return self.m - self.sets

    def build(self):
        self.father = [x for x in range(0, self.m)]
        self.sets = self.m

    def find(self, i):
        if self.father[i] != i:
            self.father[i] = self.find(self.father[i])
        return self.father[i]
    def unions(self, x, y):
        fx = self.find(x)
        fy = self.find(y)
        if (fx != fy):
            self.father[fx] = fy
            self.sets -= 1
