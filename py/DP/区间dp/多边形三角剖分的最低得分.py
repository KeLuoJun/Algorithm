# 多边形三角剖分的最低得分
# 你有一个凸的 n 边形，其每个顶点都有一个整数值
# 给定一个整数数组values，其中values[i]是第i个顶点的值(顺时针顺序)
# 假设将多边形 剖分 为 n - 2 个三角形
# 对于每个三角形，该三角形的值是顶点标记的乘积
# 三角剖分的分数是进行三角剖分后所有 n - 2 个三角形的值之和
# 返回 多边形进行三角剖分后可以得到的最低分
# 测试链接 : https://leetcode.cn/problems/minimum-score-triangulation-of-polygon/

import sys
from typing import List

def minScoreTriangulation1(values: List[int]) -> int:
    """记忆化搜索"""
    n = len(values)
    dp = [[-1] * n for _ in range(n)]

    def f(l, r):
        """
        以 l 和 r 为子三角形的两个边界点，在 l 和 r 之间选择另一个顶点 m
        在 l 和 m 以及 m 和 r 采用相同的方式进行递归求出最小得分
        """
        if dp[l][r] != -1:
            return dp[l][r]
        ans = sys.maxsize
        if l == r or l == r - 1:
            return 0
        else:
            # l....r >=3
			# 0..1..2..3..4...5
            for m in range(l + 1, r):
                ans = min(ans, f(l, m) + f(m, r) + values[l] * values[m] * values[r])
        dp[l][r] = ans
        return ans
    return f(0, n - 1)

def minScoreTriangulation2(values: List[int]) -> int:
    # 严格位置依赖的动态规划
    n = len(values)
    dp = [[0] * n for _ in range(n)]
    for l in range(n - 3, -1, -1):
        for r in range(l + 2, n):
            dp[l][r] = sys.maxsize
            for m in range(l + 1, r):
                dp[l][r] = min(dp[l][r], dp[l][m] + dp[m][r] + values[l] * values[m] * values[r])
    return dp[0][n - 1]


def main() -> None:
    values = list(map(int, sys.stdin.readline().strip().split()))
    print(minScoreTriangulation2(values))

if __name__ == '__main__':
    main()
