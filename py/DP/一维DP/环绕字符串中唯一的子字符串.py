# 环绕字符串中唯一的子字符串
# 定义字符串 base 为一个 "abcdefghijklmnopqrstuvwxyz" 无限环绕的字符串
# 所以 base 看起来是这样的：
# "..zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd.."
# 给你一个字符串 s ，请你统计并返回 s 中有多少 不同非空子串 也在 base 中出现
# 测试链接 : https://leetcode.cn/problems/unique-substrings-in-wraparound-string/

import sys

def main() -> None:
    s = sys.stdin.readline().strip()
    s = [ord(c) - ord('a') for c in s]
    n = len(s)

    dp = [0] * 26
    dp[s[0]] = 1
    length = 1
    for i in range(1, n):
        cur, pre = s[i], s[i - 1]
        if (cur == pre + 1) or (cur == 0 and pre == 25):
            length += 1
        else:
            length = 1
        dp[cur] = max(dp[cur], length)
    ans = sum(dp)
    return ans
    

if __name__ == '__main__':
    ans = main()
    print(ans)
