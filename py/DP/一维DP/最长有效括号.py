# 最长有效括号
# 给你一个只包含 '(' 和 ')' 的字符串
# 找出最长有效（格式正确且连续）括号子串的长度。
# 测试链接 : https://leetcode.cn/problems/longest-valid-parentheses/

import sys


def main() -> None:
    s = sys.stdin.readline().strip()
    n = len(s)

    dp = [0] * n
    ans = 0
    for i in range(1, n):
        if s[i] == ')':
            p = i - dp[i - 1] - 1
            if p >= 0 and s[p] == '(':
                dp[i] = dp[i - 1] + 2 + (dp[p - 1] if p > 0 else 0)
        ans = max(ans, dp[i])
    return ans


if __name__ == '__main__':
    ans = main()
    print(ans)

