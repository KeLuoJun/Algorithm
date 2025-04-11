# 不同的子序列
# 给你两个字符串s和t ，统计并返回在s的子序列中t出现的个数
# 答案对 1000000007 取模
# 测试链接 : https://leetcode.cn/problems/distinct-subsequences/

import sys

def numDistinct1(s, t):
    n, m = len(s), len(t)
    # dp[i][j] :
	# s[前缀长度为i]的所有子序列中，有多少个子序列等于t[前缀长度为j]
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    for i in range(n + 1):
        dp[i][0] = 1    
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            dp[i][j] = dp[i - 1][j]
            if s[i - 1] == t[j - 1]:
                dp[i][j] += dp[i - 1][j - 1]
    return dp[n][m]

# 空间压缩
def numDistinct2(s, t):
    n, m = len(s), len(t)
    dp = [0] * (m + 1)
    dp[0] = 1
    for i in range(1, n + 1):
        for j in range(m, 0, -1):
            if s[i - 1] == t[j - 1]:
                dp[j] += dp[j - 1]
    return dp[m]

def main() -> None:
    s = sys.stdin.readline().strip()
    t = sys.stdin.readline().strip()
    print(numDistinct2(s, t))


if __name__ == '__main__':
    main()

