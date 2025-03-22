# 不同的子序列 II
# 给定一个字符串 s，计算 s 的 不同非空子序列 的个数
# 因为结果可能很大，答案对 1000000007 取模
# 字符串的 子序列 是经由原字符串删除一些（也可能不删除）
# 字符但不改变剩余字符相对位置的一个新字符串
# 例如，"ace" 是 "abcde" 的一个子序列，但 "aec" 不是
# 测试链接 : https://leetcode.cn/problems/distinct-subsequences-ii/

import sys

def main() -> None:
    MOD = 1000000007
    s = sys.stdin.readline().strip()
    cnt = [0] * 26

    all_counts = 1  # 空集
    for c in s:
        new_add = (all_counts - cnt[ord(c) - ord('a')] + MOD) % MOD
        cnt[ord(c) - ord('a')] = (cnt[ord(c) - ord('a')] + new_add) % MOD
        all_counts = (all_counts + new_add) % MOD

    return (all_counts - 1 + MOD) % MOD  # 减去空集

if __name__ == '__main__':
    ans = main()
    print(ans)
