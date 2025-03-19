# 最小覆盖子串
# 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串
# 如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
# 测试链接 : https://leetcode.cn/problems/minimum-window-substring/

import sys
def main() -> None:
    s = sys.stdin.readline().strip()
    t = sys.stdin.readline().strip()

    # 欠债表
    cnts = [0] * 58
    for c in t:
        cnts[ord(c) - ord('a')] -= 1

    start = 0
    length = float('inf')

    l, r, debt = 0, 0, len(t)
    while r < len(s):
        # cnts[s[r]] : 当前字符欠债情况，负数就是欠债，正数就是多给的
        index = ord(s[r]) - ord('a')
        if cnts[index] < 0:
            debt -= 1
        cnts[index] += 1

        if debt == 0:
            while cnts[ord(s[l]) - ord('a')] > 0:
                cnts[ord(s[l]) - ord('a')] -= 1
                l += 1
            if r - l + 1 < length:
                length = r - l + 1
                start = l
        r += 1
    ans = ''
    i = start
    for j in range(length):
        ans += s[i]
        i += 1
    print(ans)
    

if __name__ == '__main__':
    main()

