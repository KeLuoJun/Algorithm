# 砍竹子II
# 现需要将一根长为正整数bamboo_len的竹子砍为若干段
# 每段长度均为正整数
# 请返回每段竹子长度的最大乘积是多少
# 答案需要对1000000007取模
# 测试链接 : https://leetcode.cn/problems/jian-sheng-zi-ii-lcof/


class Solution:
    def cuttingBamboo(self, bamboo_len: int) -> int:
        self.mod = int(1e9 + 7)
        if bamboo_len == 2:
            return 1
        if bamboo_len == 3:
            return 2
        # n = 4  -> 2 * 2
        # n = 5  -> 3 * 2
        # n = 6  -> 3 * 3
        # n = 7  -> 3 * 2 * 2
        # n = 8  -> 3 * 3 * 2
        # n = 9  -> 3 * 3 * 3
        # n = 10 -> 3 * 3 * 2 * 2
        # n = 11 -> 3 * 3 * 3 * 2
        # n = 12 -> 3 * 3 * 3 * 3
        tail = 1 if bamboo_len % 3 == 0 else 4 if bamboo_len % 3 == 1 else 2
        n = int((bamboo_len if tail == 1 else (bamboo_len - tail)) // 3)
        return int(self.power(3, n) * tail % self.mod)
    
    def power(self, a, n):
        ans = 1
        while n > 0:
            if n & 1:
                ans = (ans * a) % self.mod
            a = (a * a) % self.mod
            n >>= 1
        return ans
 