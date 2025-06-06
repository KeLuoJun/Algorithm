# 相似字符串组
# 如果交换字符串 X 中的两个不同位置的字母，使得它和字符串 Y 相等
# 那么称 X 和 Y 两个字符串相似
# 如果这两个字符串本身是相等的，那它们也是相似的
# 例如，"tars" 和 "rats" 是相似的 (交换 0 与 2 的位置)；
# "rats" 和 "arts" 也是相似的，但是 "star" 不与 "tars"，"rats"，或 "arts" 相似
# 总之，它们通过相似性形成了两个关联组：{"tars", "rats", "arts"} 和 {"star"}
# 注意，"tars" 和 "arts" 是在同一组中，即使它们并不相似
# 形式上，对每个组而言，要确定一个单词在组中，只需要这个词和该组中至少一个单词相似。
# 给你一个字符串列表 strs列表中的每个字符串都是 strs 中其它所有字符串的一个字母异位词。
# 返回 strs 中有多少字符串组
# 测试链接 : https://leetcode.cn/problems/similar-string-groups/


class Solution:
    def numSimilarGroups(self, strs: list[str]) -> int:
        n = len(strs)
        self.bulid(n)
        for i in range(n):
            for j in range(i + 1, n):
                diff = 0
                if self.find(i) != self.find(j):
                    for k in range(len(strs[i])):
                        if strs[i][k] != strs[j][k]:
                            diff += 1
                            if diff > 2:
                                break
                if diff == 0 or diff == 2:
                    self.union(i, j)
        return self.sets
    def bulid(self, n):
        self.father = [i for i in range(n)]
        self.sets = n
    def find(self, i):
        if i != self.father[i]:
            self.father[i] = self.find(self.father[i])
        return self.father[i]
    def union(self, x, y):
        fx, fy = self.find(x), self.find(y)
        if fx != fy:
            self.father[fx] = fy
            self.sets -= 1

    
