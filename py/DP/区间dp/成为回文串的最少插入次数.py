# 让字符串成为回文串的最少插入次数
# 给你一个字符串 s
# 每一次操作你都可以在字符串的任意位置插入任意字符
# 请你返回让s成为回文串的最少操作次数
# 测试链接 : https://leetcode.cn/problems/minimum-insertion-steps-to-make-a-string-palindrome/

import sys

def minInsertions1(s: str) -> int:
    """暴力尝试"""
    n = len(s)
    
    def f1(s, l, r):
        """
        s[l....r]这个范围上的字符串，整体都变成回文串
        返回至少插入几个字符
        """
        # l <= r 一定成立
        if l == r:
            return 0
        if l + 1 == r:
            return 0 if s[l] == s[r] else 1
        
        # l...r 不只两个字符
        if s[l] == s[r]:
            return f1(s, l + 1, r - 1)
        else:
            return min(f1(s, l + 1, r), f1(s, l, r - 1)) + 1

    return f1(s, 0, n - 1)
        

def minInsertions2(s: str) -> int:
    """暴力尝试 + 记忆化搜索"""
    n = len(s)
    dp = [[-1] * n for _ in range(n)]

    def f2(s, l, r):
        if dp[l][r] != -1:
            return dp[l][r]
        
        ans = None
        if l == r:
            ans = 0
        elif l + 1 == r:
            ans = 0 if s[l] == s[r] else 1
        else:
            if s[l] == s[r]:
                ans =  f2(s, l + 1, r - 1)
            else:
                ans = min(f2(s, l + 1, r), f2(s, l, r - 1)) + 1
        dp[l][r] = ans
        return ans

    return f2(s, 0, n - 1)


def minInsertions3(s: str) -> int:
    """严格位置依赖的动态规划"""
    n = len(s)
    dp = [[0] * n for _ in range(n)]
    for l in range(n - 1):
        dp[l][l + 1] = 0 if s[l] == s[l + 1] else 1
    for l in range(n - 3, -1, -1):
        for r in range(l + 2, n):
            if s[l] == s[r]:
                dp[l][r] = dp[l + 1][r - 1]
            else:
                dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + 1
    return dp[0][n - 1]

def main() -> None:
    s = sys.stdin.read().strip()
    print(minInsertions3(s))


if __name__ == '__main__':
    main()
